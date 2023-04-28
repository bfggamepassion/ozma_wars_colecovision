// TODO :
//
//	Hiscore ? (Ou le placer ?)
//	Bruitages
// 	2 Joueurs
//

// Principe 1 sprite = 1 objet
// 
// 0 - Joueur
// 1 - Tir du joueur
// 2 à 16 : Vaisseaux
// 17 à 31 : Tirs ennemis

#include <coleco.h>
#include <getput1.h>

#define chrtab  0x1800 /* écran en linéaire */
#define chrgen  0x0000 /* table des caractères */
#define coltab  0x2000 /* couleur des caractères */
#define sprtab  0x3800 /* sprite_pattern_table */
#define sprgen  0x1b00 /* sprite_attribute_table */
#define buffer  0x1c00 /* buffer screen 2 */

#define S_TRUE 1
#define S_FALSE 0

#define ALIEN1 1
#define ALIEN2 2
#define ENERGIZER1 3
#define ENERGIZER2 4
#define ASTEROID 5
#define ALIEN3 6
#define CLOACKINGALIEN 7
#define COMETE1	8
#define COMETE2	9
#define COMETE3	10
#define COMETE4	11
#define BOSS1 12
#define APPARINGALIEN 13
#define MIDBOSS1 14
#define MINIALIEN1 15
#define ROTATING 16
#define SPLITALIEN 17
#define MINISPLITALIEN 18

#define MVT_BOSS1 1
#define MVT_ENERGIZER 5
#define MVT_ENERGIZER_NOSHOOT 6
#define MVT_ALIEN1 7
#define MVT_ALIEN2 8
#define MVT_ALIEN3 9
#define MVT_ALIEN4 10
#define MVT_ALIEN5 11
#define MVT_ALIEN5MIRROR 12
#define MVT_AST1 13
#define MVT_AST2 14
#define MVT_DROITSHOOT 15
#define MVT_DROITSHOOTDIRIGE 16
#define MVT_ALIEN6 17
#define MVT_ALIEN6INVERSE 18
#define MVT_ALIENCLOACKING 19
#define MVT_COMETE 20
#define MVT_APPARINGALIEN 21
#define MVT_ROTATINGALIENNEXTLEVEL 22
#define MVT_ROTATINGALIENNONEXTLEVEL 23
#define MVT_SPLITTER 24
#define MVT_MINISPLITTER 25
#define MVT_MINI1 26
#define MVT_MINI2 27
#define MVT_MINI3 28
#define MVT_MINI4 29
#define MVT_MINI5 30
#define MVT_MINI6 31
#define MVT_MINI7 32
#define MVT_MINI8 33
#define MVT_MINISPLITTER2 34
#define MVT_MINISPLITTER3 35

#define MVT_LOOP 127
#define	MVT_SHOOT 126
#define MVT_DESTROY 125
#define MVT_FREEZE 124
#define MVT_DESTROY_ALL_SHOOT 123
#define MVT_ANIMATE 122
#define MVT_NEXTLEVEL 121
#define MVT_SPLIT 120
#define MVT_PLAYMUSIC 119
#define MVT_STOPMUSIC 118

// Nombre de sprites maxi à animer (-1)
#define MAXSPRITES 32

#define MAXALIEN 14
#define	MAXSHOOT 15

#define GO_NEXTLEVEL	0
#define GO_GAMEOVER		1

extern const byte PATTERNRLE[];
extern const byte COLORRLE[];
extern const byte SPATTERNRLE[];
extern const byte BIOS0NAMERLE[];
extern const byte BIOS0PATTERNRLE[];
extern const byte* BIOS0COLORS[];

extern const byte BIOS1NAMERLE[];
extern const byte BIOS1PATTERNRLE[];
extern const byte BIOS1COLORRLE[];
extern const byte* levelsTimeLine[];
extern const char* alienMvts[];

extern const sound_t snd_table[] ;
extern const void music[];

char ticks;
unsigned gameTimerFast;
unsigned gameTimerSlow;
unsigned posInTimeLine;
unsigned nrj;
unsigned save_nrj;
unsigned tmp_nrj;
byte nbjoueurs;
byte currentLevel;
byte save_currentLevel;
byte tmp_currentLevel;
byte cheat;
char difficulty;
//byte nbObjectInLevel;
byte nbObjectInLevel2;
byte currentFlicker;
byte littleTimer;

byte minflickery;

byte currentEtoileCaractere;
byte currentEtoileColorPosition;
byte currentEtoileColorPosition8;
byte currentCycle;

//const byte explode0[] = {32,32,32,32};
const byte explode1[] = {1,9,2,10};
const byte explode2[] = {192,200,193,102};
const byte explode3[] = {194,202,195,203};
const byte explode4[] = {3,11,4,12};
byte explodeFond[4];

byte nextLevel;
byte currentPlayer;
byte nbPlayerAlive;

/* Variable globales génériques */
byte globalUse1;
sprite_t bsprites[32];

const byte arrierePlanColor[9][8] =
{
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0xF1,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x11,0xF1,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x11,0x11,0xF1,0x11,0x11,0x11,0x11,0x11},
	{0x11,0x11,0x11,0xF1,0x11,0x11,0x11,0x11},
	{0x11,0x11,0x11,0x11,0xF1,0x11,0x11,0x11},
	{0x11,0x11,0x11,0x11,0x11,0xF1,0x11,0x11},
	{0x11,0x11,0x11,0x11,0x11,0x11,0xF1,0x11},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0xF1}
};

byte explode_x;
byte explode_y;
char explode_timer;

typedef struct
{
	byte px,py;
	unsigned score;
} s_player;

s_player player;

typedef struct
{
	byte px,py;
	byte actif;
} s_shoot;

s_shoot shoot;

// sprno = index du tableau + 2
typedef struct
{
	byte py; 			// Hélas pour le flickering
	byte mvt;
	byte indexMvt;
	byte nbMvt;
	byte anime;	// est-ce un alien animé ?
} s_alien;

s_alien alien[MAXALIEN];	

typedef struct
{
	byte py;
	byte mvt;
	char direction;
} s_alienShoot;

s_alienShoot alienShoot[MAXSHOOT];

unsigned save_score;
unsigned tmp_score;

unsigned hiscore;
char activateNmi;

void showSplash()
{
	byte i,j;
	disable_nmi();
	screen_off();
	rle2vram(BIOS0NAMERLE,chrtab);	
	
	load_patternrle(BIOS0PATTERNRLE);
	duplicate_pattern();
	
	screen_on();
	
	for(i=0;i<4;i++)
	{
		for (j=0;j<6;j++)
		{
			rle2vram(BIOS0COLORS[j],coltab);
			rle2vram(BIOS0COLORS[j],coltab+2048);
			rle2vram(BIOS0COLORS[j],coltab+4096);
			delay(5);
		}						
	}
	screen_off();
	rle2vram(BIOS1NAMERLE,chrtab);	
	
	load_patternrle(BIOS1PATTERNRLE);
	duplicate_pattern();
	
	/* Chargement des couleurs */
	rle2vram(BIOS1COLORRLE,coltab);
	rle2vram(BIOS1COLORRLE,coltab+2048);
	rle2vram(BIOS1COLORRLE,coltab+4096);	
	screen_on();
	enable_nmi();
	pause();
}


void calculateNbObject()
{
	
	
	byte i;
	sprite_t *s0 = &sprites[0];
	
	nbObjectInLevel2 = 0;
	for (i=2;i<32;i++)
	{
		if ((s0+i)->y!=204) nbObjectInLevel2++;
	}
}

void prepareArrierePlan(void)
{
	byte x,y,currentChar,i,j;

	disable_nmi();
	screen_off();
	
	for (i=0;i<32;i++)
	for (j=0;j<24;j++)
	put_char(i,j,32);
		
	for (x=5;x<32-6;x++)
	{
		currentChar = rnd_byte(136,159);
		for (y=0;y<24;y++)
		{
			put_char(x,y,currentChar);
			currentChar++;
			if (currentChar==160) currentChar = 136;
		}
	}

	put_vram_pattern (coltab+(136<<3),arrierePlanColor[0],8,24);
	put_vram_pattern (coltab+(136<<3)+2048,arrierePlanColor[0],8,24);
	put_vram_pattern (coltab+(136<<3)+4096,arrierePlanColor[0],8,24);	
	
	print_at(3,0,"ENERGY 00000");
	print_at(18,0,"SCORE 000000");

	screen_on();
	enable_nmi();
}

void cycleArrierePlan(void)
{
	// Remise à noir
	
	if (currentCycle>=16) currentCycle=0;
	else
	if (currentCycle!=0) currentCycle++;
	else
	{
		currentEtoileColorPosition++;
		currentEtoileColorPosition8+=8;
		if (currentEtoileColorPosition>8) 
		{
			currentEtoileColorPosition=1;
			currentEtoileColorPosition8=8;
			
			put_vram_pattern (coltab+(currentEtoileCaractere<<3),arrierePlanColor,8,1);	
			put_vram_pattern (coltab+(currentEtoileCaractere<<3)+2048,arrierePlanColor,8,1);
			put_vram_pattern (coltab+(currentEtoileCaractere<<3)+4096,arrierePlanColor,8,1);	
			
			
			if (currentEtoileCaractere<159) currentEtoileCaractere++; else currentEtoileCaractere=136;
		}
		
		// OPTIMISATION A EFFECTUER ?
		/*
		put_vram_pattern (coltab+(currentEtoileCaractere<<3),arrierePlanColor[currentEtoileColorPosition],8,1);
		put_vram_pattern (coltab+(currentEtoileCaractere<<3)+2048,arrierePlanColor[currentEtoileColorPosition],8,1);
		put_vram_pattern (coltab+(currentEtoileCaractere<<3)+4096,arrierePlanColor[currentEtoileColorPosition],8,1);*/
		
		put_vram_pattern (coltab+(currentEtoileCaractere<<3),(*arrierePlanColor+currentEtoileColorPosition8),8,1);
		put_vram_pattern (coltab+(currentEtoileCaractere<<3)+2048,(*arrierePlanColor+currentEtoileColorPosition8),8,1);
		put_vram_pattern (coltab+(currentEtoileCaractere<<3)+4096,(*arrierePlanColor+currentEtoileColorPosition8),8,1);
	}
}

// S_TRUE _ Collision  
byte isCollision(byte x1,byte y1,byte h1,byte l1,byte x2,byte y2,byte h2,byte l2)
{
	if(x1 > x2+l2) return S_FALSE;
	if(x1+l1 < x2) return S_FALSE;
	if(y1 > y2+h2) return S_FALSE;
	if(y1+h1 < y2) return S_FALSE;
	
	return S_TRUE;
}

// S_TRUE _ Collision  
byte isSimpleCollision(byte x1,byte l1,byte x2,byte l2)
{
	if(x1 > x2+l2) return S_FALSE;
	if(x1+l1 < x2) return S_FALSE;
	//	if(y1 > y2+h2) return S_FALSE;
	//	if(y1+h1 < y2) return S_FALSE;
	
	return S_TRUE;
}

// Position px et py de l'alien a checker
byte checkPlayerCollisionsWithAliens(byte px)
{	  
	// Faire le test du pattern pour affiner
	if ( vdp_status==159 ) return S_FALSE;
	return isSimpleCollision(player.px,16,px,16);
}

byte checkPlayerCollisionsWithAlienShoot(byte px,byte py,byte pattern)
{	
	// Faire le test du pattern pour affiner !!!!
	if ( vdp_status==159 ) return S_FALSE;
	if (pattern==24) return isSimpleCollision(player.px,16,px+5,5);
	if (pattern==28) return isCollision(player.px+1,player.py+2,14,14,px+5,py,6,5);
	if (pattern==48) return isCollision(player.px+1,player.py+2,14,14,px+6,py+1,15,4);
	if (pattern==168) return isCollision(player.px+1,player.py+2,14,14,px+6,py+1,5,4);	
	if (pattern==172) return isCollision(player.px+1,player.py+2,14,14,px,py,16,16);
	return isSimpleCollision(player.px,16,px+5,5);
}

// Position px et py de l'alien a checker
byte checkAlienCollisionsWithPlayerShoot(byte px,byte py,byte pattern)
{	
	if ( vdp_status==159 ) return S_FALSE;
	if ( (pattern==16) || (pattern==20) || (pattern==88) || (pattern==92) || (pattern==96) ) return S_FALSE;
	if ( (pattern==160) || (pattern==164) ) return isCollision(shoot.px+7,shoot.py,8,2,px+5,py+5,5,5);
	if ( (pattern==128) || (pattern==132) ) return isCollision(shoot.px+7,shoot.py,8,2,px+4,py,8,16);
	if ( (pattern==68) || (pattern==72) || (pattern==76) ) return isCollision(shoot.px+7,shoot.py,8,2,px+6,py,16,6);
	if ( (pattern==32) || (pattern==36) || (pattern==40) || (pattern==44)) return isCollision(shoot.px+7,shoot.py,8,2,px,py,8,12);
	return isCollision(shoot.px+7,shoot.py,8,2,px+2,py+2,14,14);
}

byte checkAlienShootCollisionsWithPlayerShoot(byte px,byte py)
{	
	//if ( vdp_status==159 ) return S_FALSE;
	return isCollision(shoot.px+7,shoot.py,8,2,px+5,py+5,5,5);
}

void changeFontColor(byte col1,byte col2)
{
	byte finalColor;
	
	finalColor = col1 << 4;
	finalColor+= col2;
	
	fill_vram(coltab+(32*8),finalColor,59*8);
	fill_vram(coltab+(32*8)+2048,finalColor,59*8);
	fill_vram(coltab+(32*8)+4096,finalColor,59*8);
}

void shake()
{
	byte j;
	for (j=0;j<200;j++) // Touché, je suis secoué !!
	{
		play_sound(4);
		disable_nmi();
		sprites[0].x +=2;
		put_vram (0x1b00,sprites,128);
		sprites[0].x -=2;
		put_vram (0x1b00,sprites,128);
		enable_nmi();
	}
	// -50 pour level easy
	// -100 pour level normal
	// -150 pour level hard
	// -170 pour very hard
	
	
	if (cheat!=4)
	{
		if (difficulty==0) 
		if (nrj>3000) nrj=nrj-3000; else nrj=0;
		if (difficulty==1)
		if (nrj>4000) nrj=nrj-4000; else nrj=0;
		if ( (difficulty==2) || (difficulty==3) )
		if (nrj>5000) nrj=nrj-5000; else nrj=0;
		if (difficulty==4)
		if (nrj>5500) nrj=nrj-5500; else nrj=0;
		if (difficulty>=5)
		if (nrj>6000) nrj=nrj-6000; else nrj=0;	
	}
}

void moveAlienShoot(byte i)
{				
	s_alienShoot *this_alienShoot = &alienShoot[i];
	//byte *a_actif = &this_alienShoot->actif;
	byte *a_mvt = &this_alienShoot->mvt;		
	byte *a_py = &this_alienShoot->py;	
	//byte *a_flicker = &this_alienShoot->flicker;	
	char *a_direction = &this_alienShoot->direction;
	
	sprite_t *this_sprite = &sprites[i+17];
	byte *s_x = &this_sprite->x;
	byte *s_y = &this_sprite->y;
	byte *s_pattern = &this_sprite->pattern;
	
	//byte j;
	
	if ((*a_py) != 204) // Est il actif ?
	{			
		if (*s_pattern==24) (*s_pattern=47<<2);
		else
		if (*s_pattern==47<<2) (*s_pattern=24);
		
		if ((*a_py)<192)
		{
			(*a_py)++;
			
			if ( ((*a_mvt)==2) || ((*a_mvt)==4) || ((*a_mvt)==8))// Shoot Type 2
			{				
				if (gameTimerFast==16)
				{
					if ((*s_x) > (player.px)) *a_direction=-1; else * a_direction=+1;					
				}
				if (littleTimer==3) (*s_x)+= (*a_direction);
			}
			else if ((*a_mvt==10))
			{
				if (littleTimer==3) (*s_x)+= (*a_direction);
			}
			else if ((*a_mvt==3)) 
			{
				(*a_py)--;
				if (gameTimerSlow>0) gameTimerSlow--; // On repasse à 0 tant qu'on charge en énergie
			}
			else if ((*a_mvt==5))
			{
				if (gameTimerFast%2==0) (*a_py)--; // on le ralentit
			}
			else if ((*a_mvt==6))
			{
				if (gameTimerFast%4==0) (*a_py)++; 
			}
			
			/*if ((currentFlicker==1) && (*a_flicker==S_TRUE) )
			(*s_y) = 204;
			else*/
			(*s_y) = (*a_py);
			
			//if ((*a_py)<minflickery) minflickery = *a_py;	

			if ( ((*a_py)>176) )
			if ((checkPlayerCollisionsWithAlienShoot((*s_x),(*a_py),(*s_pattern)))==S_TRUE) 
			{
				if ( (*s_pattern==46<<2)  || (*s_pattern==24) || (*s_pattern==47<<2))
				{
					if (nrj<65000) {nrj+=60;play_sound(2);}
					player.px = 120;
					sprites[0].x = 120;
				}
				else
				{
					(*a_py) = 204;
					(*s_y) = 204;
					//nbObjectInLevel--;
					/*	disable_nmi();
				for (j=0;j<200;j++) // Touché, je suis secoué !!
				{
					sprites[0].x +=2;
					put_vram (0x1b00,sprites,128);
					sprites[0].x -=2;
					put_vram (0x1b00,sprites,128);
				}
				nrj=nrj-50;
				enable_nmi();*/
					shake();
				}
			}
			
			if ( (*s_pattern==48) || (*s_pattern==168) )
			if (checkAlienShootCollisionsWithPlayerShoot((*s_x),(*a_py))==S_TRUE) 
			{
				disable_nmi();
				put_frame(&explodeFond,explode_x,explode_y,2,2);
				explode_timer = 30;
				explode_x = (*s_x)>>3;
				explode_y = (*a_py)>>3;
				explodeFond[0] = get_char(explode_x,explode_y);
				explodeFond[1] = get_char(explode_x+1,explode_y);
				explodeFond[2] = get_char(explode_x,explode_y+1);
				explodeFond[3] = get_char(explode_x+1,explode_y+1);			
				if (*s_pattern==48)
				put_frame(&explode2,explode_x,explode_y,2,2);
				else
				put_frame(&explode3,explode_x,explode_y,2,2);
				enable_nmi();
				
				(*a_py) = 204;
				(*s_y) = 204;
				//nbObjectInLevel--;
				shoot.actif = S_FALSE;
				shoot.py = 204;
			}
		}
		else
		{
			(*a_py) = 204;
			(*s_y) = 204;
			//nbObjectInLevel--;
		}
		
	}
}


void initLevel(void)
{
	if (currentLevel==0) 
	if (difficulty<10) difficulty++;
	posInTimeLine = 0;
	nextLevel = S_FALSE;
}

void initSpriteLibre(void)
{
	char i;
	for (i=0;i<MAXSPRITES;i++)
	{
		sprites[i].x = 0;
		sprites[i].y = 204;
		sprites[i].pattern = 0;
		sprites[i].colour = 0;
		
		bsprites[i].x = 0;
		bsprites[i].y = 204;
		bsprites[i].pattern = 0;
		bsprites[i].colour = 0;
	}
	
	disable_nmi();
	put_vram (0x1b00,sprites,128); 
	enable_nmi();
}

void initAlien(void)
{
	char i;
	
	//for (i=0;i<MAXALIEN;i++) alien[i].actif = S_FALSE;
	for (i=0;i<MAXALIEN;i++) alien[i].py = 204;
	for (i=0;i<MAXSHOOT;i++) alienShoot[i].py = 204;
}

char retournePremierAlienLibre(void)
{
	/*	char i;
	for (i=0;i<MAXALIEN;i++)
	if (alien[i].py==204) return i;*/
	byte i;
	s_alien *a0 = &alien[0];
	
	for (i=0;i<MAXALIEN;i++)
	{
		if ((a0+i)->py==204) return i;
	}
	
	return -1;
}

char retournePremierShootAlienLibre(void)
{
	/*char i;
	for (i=0;i<MAXSHOOT;i++)
	if (alienShoot[i].py==204) return i;*/
	byte i;
	s_alienShoot *a0 = &alienShoot[0];
	
	for (i=0;i<MAXSHOOT;i++)
	{
		if ((a0+i)->py==204) return i;
	}
	
	return -1;
}

void createAlienShoot(byte g,byte x,byte y)
{
	char a,s,i;
	a = retournePremierShootAlienLibre();
	s = a+17;

	if ( (a!=-1) )
	{
		if (difficulty ==0)
		{ // NOTHING
		}
		else
		if (difficulty ==1) 
		{
			if (g==1) // On transforme 20% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<20)
				g=10; // Shoot dirigé une fois
			}
		}
		else
		if (difficulty ==2) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<40)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>80)
				g=10; // semi auto guidé 
			}
		}
		else
		if (difficulty == 3) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<40)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>80)
				g=2; // auto guidé complet 
			}
		}	
		else
		if (difficulty == 4) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<30)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>60)
				g=2; // auto guidé complet
				else
				g=10; // semi auto guidé
			}
		}
		else
		if (difficulty == 5) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<30)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>60)
				g=2; // auto guidé complet
				else
				g=10; // semi auto guidé
			}
			else
			if (g==4) g=8;
		}
		else
		if (difficulty ==6 ) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<30)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>60)
				g=2; // auto guidé complet
				else
				g=10; // semi auto guidé
			}
			else
			if (g==4) g=2;
		}
		else
		if (difficulty >=7 ) 
		{
			if (g==1) // On transforme 40% des shoots vers le bas en semi autoguidé
			{
				if (rnd_byte(0,100)<30)
				g=6; // Accéléré
				else
				if (rnd_byte(0,100)>60)
				g=2; // auto guidé complet
				else
				g=10; // semi auto guidé
			}
			else
			if (g==4) g=2;
			else
			if (g==8) g=2;
		}
		
		alienShoot[a].mvt = g;			
		
		if ( (g==1) || (g==2) || (g==5) || (g==6) || (g==10))
		{
			sprites[s].pattern = 28;
			sprites[s].colour = 15;
			
			sprites[s].x = x; 
			sprites[s].y = y;
			alienShoot[a].py = y;
		}
		else if (g==7)
		{
			sprites[s].pattern = 172;
			sprites[s].colour = 15;
			sprites[s].x = x;  // Shoot gauche
			sprites[s].y = y;
			alienShoot[a].py = y;
		}
		else if (g==3)  // Energy beam
		{
			sprites[s].pattern = 45<<2;
			sprites[s].colour = 15;
			//alienShoot[a].flicker = S_TRUE;
			sprites[s].x = x-6;
			sprites[s].y = y+12;
			alienShoot[a].py = y+12;
			
			for (i=0;i<7;i++)
			{
					a = retournePremierShootAlienLibre();
					s = a+17;
					
					sprites[s].colour = 15;
					sprites[s].x = x-6;
					sprites[s].y = y+12+(i<<4);
					alienShoot[a].py = y+12+(i<<4);
					alienShoot[a].mvt = g;
				if (i<6)
					sprites[s].pattern = 24;
				else
					sprites[s].pattern = 46<<2;

			}
			
			
			
		}
		else if ( (g==4) || (g==14) )
		{
			sprites[s].pattern = 48;
			sprites[s].colour = 10;
			//alienShoot[a].flicker = S_TRUE;
			sprites[s].x = x;
			sprites[s].y = y+12;
			alienShoot[a].py = y+12;
		}
		else if (g==8) // Mini shoot dirigé
		{
			sprites[s].pattern = 168;
			sprites[s].colour = 10;
			//alienShoot[a].flicker = S_TRUE;
			sprites[s].x = x;
			sprites[s].y = y+12;
			alienShoot[a].py = y+12;
		}

		if (x>player.px) alienShoot[a].direction = -1; else alienShoot[a].direction = 1;
		
		//nbObjectInLevel++;		

			if (alienShoot[a].py<160) play_sound(6);
	}
	
}

void createAlien(byte g,byte x,byte y,byte mvt)
{
	char a,s;
	a = retournePremierAlienLibre();
	s = a+2;
	if ( (a!=-1) )
	{
		//alien[a].actif = S_TRUE;
		alien[a].mvt = mvt;			
		alien[a].indexMvt = 1;
		alien[a].nbMvt = 0;

		
		// TODO _ SELON LE GENRE DEFINIR LE SPRITE
		// TODO _ SELON LE GENRE DEFINIR LES DONNEES DE TIR
		if (g==ALIEN1)
		{
			sprites[s].pattern = 8;
			sprites[s].colour = 4;
			alien[a].anime = S_FALSE;
		}
		else
		if (g==ALIEN2)
		{
			sprites[s].pattern = 52;
			sprites[s].colour = 13;
			alien[a].anime = S_TRUE;
		}
		else
		if (g==ALIEN3)
		{
			sprites[s].pattern = 60;
			sprites[s].colour = 9;
			alien[a].anime = S_FALSE;
		}
		else		
		if (g==CLOACKINGALIEN)
		{
			sprites[s].pattern = 64;
			sprites[s].colour = 8;
			alien[a].anime = S_FALSE;
		}
		else	
		if (g==ENERGIZER1)
		{
			sprites[s].pattern = 16;
			sprites[s].colour = 14;
			alien[a].anime = S_FALSE;
		}
		else
		if (g==ENERGIZER2)
		{
			sprites[s].pattern = 20;
			sprites[s].colour = 14;
			alien[a].anime = S_FALSE;
		}
		else
		if (g==ASTEROID)
		{
			sprites[s].pattern = 32;
			sprites[s].colour = 6;
			alien[a].anime = S_TRUE;
		}
		else
		if (g==COMETE1)
		{
			sprites[s].pattern = 84;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;		
		}
		else
		if (g==COMETE2)
		{
			sprites[s].pattern = 88;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;		
		}
		else
		if (g==COMETE3)
		{
			sprites[s].pattern = 92;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;		
		}
		else
		if (g==COMETE4)
		{
			sprites[s].pattern = 96;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;		
		}
		else
		if (g==APPARINGALIEN)
		{
			sprites[s].pattern = 112;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;		 // L'anim est générée par le mvt
		}
		else		
		if (g==BOSS1)
		{
			sprites[s].pattern = 100;
			sprites[s].colour = 7;
			alien[a].anime = S_TRUE;					
			alien[a].nbMvt=0;			// Mouvement de type IA pour le boss
			alien[a].indexMvt=1;		// On va réutiliser ces variables pour le mouvement	
			globalUse1 = 0;
		}
		else 
		if (g==MIDBOSS1)
		{
			sprites[s].pattern = 128;
			sprites[s].colour = 7;
			alien[a].anime = S_TRUE;					
			alien[a].nbMvt=0;			// Mouvement de type IA pour le boss, on réutilise la variable
			alien[a].indexMvt=1;		// On va réutiliser ces variables pour le mouvement	
		}
		else 
		if (g==MINIALIEN1)
		{
			sprites[s].pattern = 160;
			sprites[s].colour = 7;
			alien[a].anime = S_TRUE;						
		}
		else
		if (g==ROTATING)
		{
			sprites[s].pattern = 140;
			sprites[s].colour = 7;
			alien[a].anime = S_TRUE;
		}
		else
		if (g==SPLITALIEN)
		{
			sprites[s].pattern = 136;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;	
		}
		else
		if (g==MINISPLITALIEN)
		{
			sprites[s].pattern = 156;
			sprites[s].colour = 11;
			alien[a].anime = S_FALSE;	
		}

		sprites[s].x = x;
		sprites[s].y = y;
		alien[a].py = y;
		
		//if (a%2==0) alien[a].flicker = S_TRUE; else alien[a].flicker = S_FALSE;
		
		//nbObjectInLevel++;		

	}
}

void readTimeLine() // A executer tout les 16 pixels !!
{
	byte timeLineDesiree;
	byte nbAlienACreer;
	byte px,py,a,i,m;
	
	byte *this_timeLine = levelsTimeLine[currentLevel];		
	
	timeLineDesiree = (*(this_timeLine+posInTimeLine));
	
	if (timeLineDesiree!=255) 		// Si on est pas en fin de timeLine
	{
		if (timeLineDesiree==gameTimerSlow)
		{
			// Création des aliens // paramétrage
			posInTimeLine++;
			//nbAlienACreer = levelsTimeLine[currentLevel][posInTimeLine];
			nbAlienACreer = (*(this_timeLine+posInTimeLine));
			for (i=0;i<nbAlienACreer;i++)
			{			
				posInTimeLine++;
				//px=levelsTimeLine[currentLevel][posInTimeLine];
				px=(*(this_timeLine+posInTimeLine));
				posInTimeLine++;
				//py=levelsTimeLine[currentLevel][posInTimeLine];
				py=(*(this_timeLine+posInTimeLine));
				posInTimeLine++;
				//a=levelsTimeLine[currentLevel][posInTimeLine];
				a=(*(this_timeLine+posInTimeLine));
				posInTimeLine++;
				//m=levelsTimeLine[currentLevel][posInTimeLine];
				m=(*(this_timeLine+posInTimeLine));
				createAlien(a,px,py,m);
			}
			posInTimeLine++;
		}	
	}
	else nextLevel = S_TRUE;
	
}

void initPlayer(void)
{
	player.px = 120;
	player.py = 176;
	
	shoot.actif = S_FALSE;
	shoot.px = 0;
	shoot.py = 204;
	
	// Initialisation du sprite du vaisseau
	sprites[0].pattern = 0;
	sprites[0].colour = 7;
	sprites[0].x = player.px;
	sprites[0].y = player.py; 
	
	// Initialisation du sprite du tir
	sprites[1].pattern = 4;
	sprites[1].colour = 15;
	sprites[1].x = shoot.px;
	sprites[1].y = shoot.py; // Pas encore l'autorisation de l'afficher	
}

void reinitPlayer(void)
{
	shoot.actif = S_FALSE;
	shoot.px = 0;
	shoot.py = 204;
	
	// Initialisation du sprite du vaisseau
	sprites[0].pattern = 0;
	sprites[0].colour = 7;
	sprites[0].x = player.px;
	sprites[0].y = player.py; 
	
	// Initialisation du sprite du tir
	sprites[1].pattern = 4;
	sprites[1].colour = 15;
	sprites[1].x = shoot.px;
	sprites[1].y = shoot.py; // Pas encore l'autorisation de l'afficher	
}


/*
void renderPlayer()
{
	
	(*s0_x) = player.px;
	(*s0_y) = player.py;

	(*s1_x) = shoot.px;
	(*s1_y) = shoot.py;	
}*/

void controlPlayer(byte currentPlayer)
{
	sprite_t *this_sprite0 = &sprites[0];
	byte *s0_x = &this_sprite0->x;
	byte *s0_y = &this_sprite0->y;

	sprite_t *this_sprite1 = &sprites[1];
	byte *s1_x = &this_sprite1->x;
	byte *s1_y = &this_sprite1->y;

	if (currentPlayer==1)
	{
		if ( (keypad_1==1) && (cheat==0) ) cheat = 1;
		if ( (keypad_1==9) && (cheat==1) ) cheat = 2;
		if ( (keypad_1==7) && (cheat==2) ) cheat = 3;
		if ( (keypad_1==9) && (cheat==3) ) {cheat = 4;play_sound(4);play_sound(2);}
		
		if (joypad_1 & LEFT)
		{
			if ((player.px)>48) (player.px)-=2;
		}
		else
		if (joypad_1 & RIGHT)
		{
			if ((player.px)<192) (player.px)+=2;
		}
	
		if ( (joypad_1 & FIRE1) || (joypad_1 & FIRE2) )
		{
			if (shoot.actif == S_FALSE)
			{
				shoot.actif = S_TRUE;
				shoot.px = (player.px);
				shoot.py = (player.py);
				play_sound(3);
			}
		}
	}
	else
	{
		if (joypad_2 & LEFT)
		{
			if ((player.px)>48) (player.px)-=2;
		}
		else
		if (joypad_2 & RIGHT)
		{
			if ((player.px)<192) (player.px)+=2;
		}
	
		if ( (joypad_2 & FIRE1) || (joypad_2 & FIRE2) )
		{
			if (shoot.actif == S_FALSE)
			{
				shoot.actif = S_TRUE;
				shoot.px = (player.px);
				shoot.py = (player.py);
				play_sound(3);
			}
		}
	}
	
			if (keypad_1==10)
		{
				while (keypad_1==10) {delay(1);}
				delay(2);
				while(keypad_1!=10) {delay(1);}
				delay(2);
				delay(5);
		}
		
	(*s0_x) = player.px;
	(*s0_y) = player.py;

	(*s1_x) = shoot.px;
	(*s1_y) = shoot.py;	

}

void moveShoot()
{
	if (shoot.actif == S_TRUE)
	{
		if (shoot.py>3) shoot.py-=4;
		else
		{
			shoot.py = 204;
			shoot.actif = S_FALSE;
		}
	}
}

void destroyAllAlienShoot()
{
	byte i;
	
	for (i=0;i<MAXSHOOT;i++) 
	{
		//if (alienShoot[i].py!=204) nbObjectInLevel--;
		
		alienShoot[i].py = 204;
		sprites[i+17].y = 204;
	}
}

void destroyAllAliens()
{
	byte i;
	
	for (i=0;i<MAXALIEN;i++) 
	{
				
		alien[i].py = 204;
		sprites[i+2].y = 204;
	}
}

void moveAlien(byte i)
{
	char nbmv,dx,dy,s;
	byte sp,sc;
	
	s_alien *this_alien = &alien[i];
	//byte *a_actif = &this_alien->actif;
	byte *a_nbMvt = &this_alien->nbMvt;
	byte *a_mvt = &this_alien->mvt;		
	byte *a_py = &this_alien->py;
	//byte *a_flicker = &this_alien->flicker;
	byte *a_anime = &this_alien->anime;
	byte *this_alienMvts = alienMvts[(*a_mvt)];		
	
	sprite_t *this_sprite = &sprites[i+2];
	byte *s_x = &this_sprite->x;
	byte *s_y = &this_sprite->y;
	byte *s_pattern = &this_sprite->pattern;

	//byte j;
	
	byte a_indexMvt;
	a_indexMvt = this_alien->indexMvt;

	sc=1;
	nbmv=dx=dy=0;
	s=i+2;		// Correspondance Alien/Sprite

	if ((*a_py) != 204) // L'alien est il actif
	{		
		if ((*a_py)<192)	// Est il en zone visible ?
		{
			//Animations
			if ((*a_anime==S_TRUE))
			{
				if (gameTimerFast==10)
				{
					(*s_pattern)+=4;		// Necessite d'avoir un sprite fixe entre chaque animation.
					
					if ((*s_pattern==48)) (*s_pattern=32);		// METEOR
					else
					if ((*s_pattern==60)) (*s_pattern=52);		// ALIEN
					else
					if ((*s_pattern==112)) (*s_pattern=100);		// BOSS 1
					else
					if ((*s_pattern==136)) (*s_pattern=128);		// MIDBOSS 1
					else
					if ((*s_pattern==156)) (*s_pattern=140);		// ROTATING			
					else
					if ((*s_pattern==168)) (*s_pattern=160);		// MINIALIENx
					
				}
			}
			
			if ((*a_mvt)>4) // Mouvement prédéfinit et non IA
			{					
				if (littleTimer<=(*this_alienMvts))
				{
					if (*a_nbMvt==0) // L'alien à effectué son dernier mouvement
					{
						(a_indexMvt)+=3;	// On avance dans l'index
						//nbmv = this_alienMvts[(a_indexMvt)]; // On récupère le nouveaux	
						nbmv = (*(this_alienMvts+a_indexMvt));
						
						if (nbmv==MVT_LOOP)  // Fin de mouvement ?
						{
							(a_indexMvt) = 4;
							//nbmv = this_alienMvts[(a_indexMvt)];
							nbmv = (*(this_alienMvts+a_indexMvt));
						}

						this_alien->indexMvt = (a_indexMvt);
						(*a_nbMvt) = nbmv;
					}
					
					/*
					dx = this_alienMvts[(a_indexMvt)+1];  // Voir si on peut y accéder en direct !!!
					dy = this_alienMvts[(a_indexMvt)+2];
					*/

					dx = (*(this_alienMvts+a_indexMvt+1));  // Voir si on peut y accéder en direct !!!
					dy = (*(this_alienMvts+a_indexMvt+2));
					
					if (dx > 110) // Code mouvement spéciaux
					{
						if (dx==MVT_SHOOT) // Tirer
						{
							// dy donne le type de shoot
							//center_string(0,"SHOOT");
							createAlienShoot(dy,(*s_x),(*a_py));
						}
						else
						if (dx==MVT_DESTROY_ALL_SHOOT) 
						{
							destroyAllAlienShoot();
						}
						else
						if (dx==MVT_DESTROY) // Détruire (A passer en dernier je pense ...)
						{
							(*s_y) = 204;
							(*a_py) = 204;
							//nbObjectInLevel--;
							
						}
						else
						if (dx==MVT_FREEZE) // On change le mouvement !
						{
							(a_indexMvt)-=3;
							this_alien->indexMvt = (a_indexMvt);
						}
						else
						if (dx==MVT_LOOP)
						{
							(a_indexMvt)-=dy;
							this_alien->indexMvt = (a_indexMvt);
						}
						else
						if (dx==MVT_ANIMATE)
						{
							(*s_pattern)+=4;
						}
						else
						if (dx==MVT_NEXTLEVEL)
						{
							nextLevel = S_TRUE;
						}
						else
						if (dx==MVT_PLAYMUSIC)
						{
							if (dy==1) play_sound(7);
						}
						else
						if (dx==MVT_STOPMUSIC)
						{
							stop_music();
						}
						else
						if (dx==MVT_SPLIT)
						{
							if (dy==0) // Split de type 0
							{
								createAlien(MINISPLITALIEN,sprites[i+2].x-8,alien[i].py,MVT_MINISPLITTER);
								createAlien(MINISPLITALIEN,sprites[i+2].x,alien[i].py+8,MVT_MINISPLITTER2);
								createAlien(MINISPLITALIEN,sprites[i+2].x+8,alien[i].py,MVT_MINISPLITTER3);
								// On détruit l'objet courant
								(*s_y) = 204;
								(*a_py) = 204;
								(*s_x) = 0;
								//nbObjectInLevel--;
							}
						}
					}
					else
					{								
						(*s_x)+=dx; 
						(*a_py) +=dy;
					}
					
					(*a_nbMvt)--;
					
				}
			}		
			else
			{
				// Mouvement spécifique
				if ((*a_mvt)==0) 
				{
					if ((*a_py)<192)
					{
						(*a_py)++;

						if (littleTimer==1) 
						{
							if ((*s_x)>player.px) (*s_x)--; else (*s_x)++;
						}
					}
				}
				else
				if ((*a_mvt)==1)  // MOUVEMENT BOSS 1
				{
					if ((*s_x)<48) {(*a_nbMvt=1) ;} // On va aller à droite
					if ((*s_x)>200) {(*a_nbMvt=0);} // On va aller à gauche

					if (*a_nbMvt==1) (*s_x)++; else (*s_x)--;
					
					if (difficulty<4)
					{
						if ((gameTimerFast==4) || (gameTimerFast==8) /*|| (gameTimerFast==16)*/ /*|| (gameTimerFast==12) || (gameTimerFast==16)*/ )// on va tirer
						{
							createAlienShoot(this_alien->indexMvt,(*s_x),(*a_py));								
							if (this_alien->indexMvt == 1) this_alien->indexMvt = 14; else this_alien->indexMvt = 1;												
						}
					}
					else
					{
						if ((gameTimerFast==4) || (gameTimerFast==8) || (gameTimerFast==16) /*|| (gameTimerFast==12) || (gameTimerFast==16)*/ )// on va tirer
						{
							createAlienShoot(this_alien->indexMvt,(*s_x),(*a_py));								
							if (this_alien->indexMvt == 1) this_alien->indexMvt = 14; else this_alien->indexMvt = 1;												
						}					
					}
					
					if (gameTimerFast==4)
					{
						globalUse1++;	// Réutilisation de cette variable
						//center_string(2,str(globalUse1));
						if (globalUse1==3)
						{
							if (*a_nbMvt==1) (*s_x)-=24; else (*s_x)+=24;
							globalUse1=0;
						}
					}
					
					// MARCHE PAS ?!
					//if ((gameTimerFast>0) && (gameTimerFast<5)) (*a_py=203); else (*a_py=120); // Cloacking !!
				}
				else			// Mouvement du MIDBOSS1
				if ((*a_mvt)==2) 
				{
					nextLevel = S_TRUE; // NextLevel Possible en cas de mort du boss
					
					//alien[a].nbMvt=0;			// Mouvement de type IA pour le boss
					//alien[a].indexMvt=1;		// On va réutiliser ces variables pour le mouvement	
					
					if (gameTimerFast==0) (*a_nbMvt)++;
					if ((*a_nbMvt)==0)
					{
						//(*a_nbMvt) = 0;
						createAlien(MINIALIEN1,116,16,MVT_MINI1);
						createAlien(MINIALIEN1,124,16,MVT_MINI1);
						createAlien(MINIALIEN1,116,24,MVT_MINI2);
						createAlien(MINIALIEN1,124,24,MVT_MINI3);
						(*a_nbMvt)++;
					} else
					if ((*a_nbMvt)==6)
					{
						createAlien(MINIALIEN1,116,16,MVT_MINI6);
						createAlien(MINIALIEN1,124,16,MVT_MINI7);
						createAlien(MINIALIEN1,116,24,MVT_MINI4);
						createAlien(MINIALIEN1,124,24,MVT_MINI5);
						(*a_nbMvt)++;
					} else
					if ((*a_nbMvt)==20) (*a_nbMvt) = 0;
				}
				
			}
		}
		else		// Il n'est plus en zone visible, on le désactive
		{
			(*a_py)=204;
			(*s_y) = 204;

			//nbObjectInLevel--;
			
			if ((*s_pattern) == 84) // Si la comète est en bas de l'écran, on passe en mode BOSS1
			{
				destroyAllAlienShoot();
				destroyAllAliens();
				
				createAlien(BOSS1,48,80,MVT_BOSS1);			
			}
		}	
		
		
		/*if ( (currentFlicker==2) && ((*a_flicker)==S_TRUE) && ((*a_py)>minflickery))
		(*s_y) = 204;
		else*/
		(*s_y) = (*a_py);
		
		
		// Check des collisions avec le joueur
		if ( ((*a_py)>176) && ((*a_py)<197))
		if ((checkPlayerCollisionsWithAliens(*s_x))==S_TRUE) 
		{
			(*a_py) = 204;
			(*s_y) = 204;
			//nbObjectInLevel--;
			/*disable_nmi();
				for (j=0;j<50;j++) // Touché, je suis secoué !!
				{
					sprites[0].x +=2;
					put_vram (0x1b00,sprites,128);
					sprites[0].x -=2;
					put_vram (0x1b00,sprites,128);
				}
				nrj-=50;
			enable_nmi();*/
			shake();
		}
		
		// Check des collisions avec le tir du joueur
		if (shoot.py!=204)
		if ((checkAlienCollisionsWithPlayerShoot((*s_x),(*a_py),(*s_pattern)))==S_TRUE)
		{
			play_sound(4);
			if (player.score<65000)
			{
				sp = (*s_pattern);
				sp = sp >>2;
				if (sp==2) sc = 1;
				else
				if (sp==3) sc = 1;
				else
				if ( (sp==8) || (sp==9) || (sp==10) || (sp==11) ) sc = 1;
				else
				if ( (sp==13) || (sp==14) ) sc = 1;
				else
				if (sp==15) sc = 5;
				else
				if ( (sp==16) || (sp==17) || (sp==18) || (sp==19) ) sc = 3;
				else
				if (sp==21) sc = 8;
				else
				if ( (sp==25) || (sp==26) || (sp==27) ) sc = 5;
				else
				if ( (sp==28) || (sp==29) || (sp==30) || (sp==31) ) sc = 2;
				else
				if ( (sp==32) || (sp==33) ) sc = 4;
				else
				if (sp==34) sc = 2;
				else
				if ( (sp==35) || (sp==36) || (sp==37) || (sp==38) ) sc = 4;
				else
				if ( (sp==40) || (sp==41) ) sc = 1;
				else
				if (sp==39) sc = 2;
				
				player.score+=sc+difficulty;
			}
			
							
				disable_nmi();
				put_frame(&explodeFond,explode_x,explode_y,2,2);
				explode_timer = 30;
				explode_x = (*s_x)>>3;
				explode_y = (*a_py)>>3;
				explodeFond[0] = get_char(explode_x,explode_y);
				explodeFond[1] = get_char(explode_x+1,explode_y);
				explodeFond[2] = get_char(explode_x,explode_y+1);
				explodeFond[3] = get_char(explode_x+1,explode_y+1);			
				if ((*s_pattern) == 84)
				{
					put_frame(&explode4,explode_x,explode_y,2,2);
					delay(5);
				}
				else
					put_frame(&explode1,explode_x,explode_y,2,2);
					
				enable_nmi();
				(*a_py) = 204;
				(*s_y) = 204;
				//nbObjectInLevel--;
				shoot.actif = S_FALSE;
				shoot.py = 204;
				
			// Attention, si l'alien est la comète, créer le boss !!
			if ((*s_pattern) == 84)
			{
				destroyAllAlienShoot();
				destroyAllAliens();
				
				createAlien(BOSS1,48,80,MVT_BOSS1);			
				nextLevel = S_TRUE; // NextLevel Possible en cas de mort du boss
			}

		}
	}

}

void moveAliens(void)
{
	moveAlien(0);
	moveAlien(1);
	moveAlien(2);
	moveAlien(3);
	moveAlien(4);
	moveAlien(5);
	moveAlien(6);
	moveAlien(7);
	moveAlien(8);
	moveAlien(9);
	moveAlien(10);
	moveAlien(11);
	moveAlien(12);
	moveAlien(13);
}

void moveAliensShoots(void)
{
	//minflickery=204;
	moveAlienShoot(0);
	moveAlienShoot(1);
	moveAlienShoot(2);
	moveAlienShoot(3);
	moveAlienShoot(4);
	moveAlienShoot(5);
	moveAlienShoot(6);
	moveAlienShoot(7);
	moveAlienShoot(8);
	moveAlienShoot(9);
	moveAlienShoot(10);
	moveAlienShoot(11);
	moveAlienShoot(12);
	moveAlienShoot(13);
	moveAlienShoot(14);
}

byte gameLoop()
{
	byte i;
	activateNmi=S_TRUE;
	nextLevel = S_FALSE;
	while (1)
	{
		ticks=0;
		calculateNbObject();

		controlPlayer(1);
		moveAliens();
		moveAliensShoots();
		moveShoot();
		
		if (explode_timer!=-1)
		{
			if (explode_timer>0) 
			explode_timer --;
			else
			{
				if (explode_timer==0)
				{	
					disable_nmi();
					put_frame(&explodeFond,explode_x,explode_y,2,2);
					enable_nmi();
				}
				explode_timer = -1;
			}
		}
		
		if (currentFlicker<2) currentFlicker++; else currentFlicker=1;
		if (littleTimer<3) littleTimer++; else littleTimer=1;
		
		if (gameTimerFast<16) gameTimerFast++; 
		else 
		{
			gameTimerFast=0;
			if (nrj>50) nrj-=50; 
				else 
			{
				disable_nmi();
				for (i=2;i<32;i++)
				{
					sprites[i].y=204;
				}
				put_vram (0x1b00,sprites,128); 
				activateNmi=S_FALSE;
				center_string(10,"GAME OVER");
				print_at(3,0,"ENERGY 00000");
				center_string(12,"FINAL SCORE");
				print_at(13,13,"000000");
				print_at(13,13,str(player.score));
				sprites[0].pattern=176;
				put_vram (0x1b00,sprites,128);
				enable_nmi();
				delay(60);
				pause();
				break;
			}

			if (nbObjectInLevel2!=0)
			{
				if (gameTimerSlow<65000)
				gameTimerSlow++;
				else
				gameTimerSlow = 0;
			}
			
			readTimeLine();			
		} 
		
		if (nbObjectInLevel2==0)
		{
			if (gameTimerSlow<65000)
			gameTimerSlow++;
			else
			gameTimerSlow = 0;
			
			readTimeLine();
		}
		
		if ( (nextLevel==S_TRUE) && (nbObjectInLevel2==0) ) return GO_NEXTLEVEL;

		if (ticks==0) delay(1);
		/*if (nbObjectInLevel2<7) delay(1); else delay(0); */
	}
	
	return GO_GAMEOVER;
}

byte gameLoop2Players()
{
	byte i;
	activateNmi=S_TRUE;
	nextLevel = S_FALSE;
	while (1)
	{
		calculateNbObject();

		controlPlayer(1);
		moveAliens();
		moveAliensShoots();
		moveShoot();
		
		if (explode_timer!=-1)
		{
			if (explode_timer>0) 
			explode_timer --;
			else
			{
				if (explode_timer==0)
				{	
					disable_nmi();
					put_frame(&explodeFond,explode_x,explode_y,2,2);
					enable_nmi();
				}
				explode_timer = -1;
			}
		}
		
		if (currentFlicker<2) currentFlicker++; else currentFlicker=1;
		if (littleTimer<3) littleTimer++; else littleTimer=1;
		
		if (gameTimerFast<16) gameTimerFast++; 
		else 
		{
			gameTimerFast=0;
			if (nrj>50) nrj-=50; 
				else 
			{
				disable_nmi();
				for (i=2;i<32;i++)
				{
					sprites[i].y=204;
				}
				put_vram (0x1b00,sprites,128); 
				activateNmi=S_FALSE;
				center_string(10,"GAME OVER");
				print_at(3,0,"ENERGY 00000");
				center_string(12,"FINAL SCORE");
				print_at(13,13,"000000");
				print_at(13,13,str(player.score));
				sprites[0].pattern=176;
				put_vram (0x1b00,sprites,128);
				enable_nmi();
				pause();
				break;
			}

			if (nbObjectInLevel2!=0)
			{
				if (gameTimerSlow<65000)
				gameTimerSlow++;
				else
				gameTimerSlow = 0;
			}
			
			readTimeLine();			
		} 
		
		if (nbObjectInLevel2==0)
		{
			if (gameTimerSlow<65000)
			gameTimerSlow++;
			else
			gameTimerSlow = 0;
			
			readTimeLine();
		}
		
		if ( (nextLevel==S_TRUE) && (nbObjectInLevel2==0) ) return GO_NEXTLEVEL;

		if (nbObjectInLevel2<7) delay(1); else delay(0); 
	}
	
	return GO_GAMEOVER;
}


void dockin(byte p)
{

	byte i,j;
/*	screen_off();
	disable_nmi();
	for (i=0;i<32;i++)
	for (j=0;j<24;j++)
	put_char(i,j,32);
	
	load_patternrle(PATTERNRLE);
	duplicate_pattern();
	
	rle2vram(COLORRLE,coltab);
	rle2vram(COLORRLE,coltab+2048);
	rle2vram(COLORRLE,coltab+4096);	
	changeFontColor(15,5);
	enable_nmi();*/
	
	disable_nmi();
	screen_off();
	for (i=0;i<32;i++)
	for (j=0;j<24;j++)
	put_char(i,j,32);
	changeFontColor(15,1);
	screen_on();
	enable_nmi();
	play_sound(5);
	for (i=0;i<8;i++)
	{
		delay(8);
		disable_nmi();
		if (p==1)
			center_string(10,"DOCKING TIME PLAYER 1");
		else
			center_string(10,"DOCKING TIME PLAYER 2");
		center_string(12,"GET READY");
		enable_nmi();
		delay(8);
		disable_nmi();
		center_string(12,"         ");
		enable_nmi();
	}
	stop_sound(5);
	//nrj+=200;
	prepareArrierePlan();
	changeFontColor(7,1);
	
}

void credits()
{
	byte i,j;
	screen_off();
	disable_nmi();
	for (i=0;i<32;i++)
	for (j=0;j<24;j++)
	put_char(i,j,32);
	//rle2vram(TITLENAMERLE,chrtab);	
	
	load_patternrle(PATTERNRLE);
	duplicate_pattern();
	
	/* Chargement des couleurs */
	rle2vram(COLORRLE,coltab);
	rle2vram(COLORRLE,coltab+2048);
	rle2vram(COLORRLE,coltab+4096);	
	changeFontColor(15,5);
	center_string(1,"OZMA WARS");
	center_string(2,"ADAPTATION BY MICHEL LOUVET 2011");
	center_string(3,"CHECK OUT MY OTHER GAMES");
	center_string(4,"PUZZLI");
	center_string(5,"BOMB N BLAST");
	center_string(6,"LOCK N CHASE");
	center_string(8,"BFG-GAMEPASSION.BLOGSPOT.COM");
	screen_on();
	
	enable_nmi();

	while(1)
	{
		if (keypad_1==1) {difficulty = -1;nbjoueurs=1;break;}
		if (keypad_1==2) {difficulty = 0;nbjoueurs=1;break;}
		if (keypad_1==3) {difficulty = 2;nbjoueurs=1;break;}
		if (keypad_1==4) {difficulty = 5;nbjoueurs=1;break;}
		if (keypad_1==5) {difficulty = -1;nbjoueurs=2;break;}
		if (keypad_1==6) {difficulty = 0;nbjoueurs=2;break;}
		if (keypad_1==7) {difficulty = 2;nbjoueurs=2;break;}
		if (keypad_1==8) {difficulty = 5;nbjoueurs=2;break;}
	}

	//disable_nmi();
}

void menu()
{
	byte i,j,easter;
	screen_off();
	disable_nmi();
	easter=0;
	for (i=0;i<32;i++)
	for (j=0;j<24;j++)
	put_char(i,j,32);
	//rle2vram(TITLENAMERLE,chrtab);	
	
	load_patternrle(PATTERNRLE);
	duplicate_pattern();
	
	/* Chargement des couleurs */
	rle2vram(COLORRLE,coltab);
	rle2vram(COLORRLE,coltab+2048);
	rle2vram(COLORRLE,coltab+4096);	
	changeFontColor(15,5);
	print_at(5,1,"TO SELECT GAME OPTION,");
	print_at(5,3,"PRESS BUTTON ON KEYPAD.");
	print_at(5,6,"1 = SKILL 1/ONE PLAYER");
	print_at(5,8,"2 = SKILL 2/ONE PLAYER");
	print_at(5,10,"3 = SKILL 3/ONE PLAYER");
	print_at(5,12,"4 = SKILL 4/ONE PLAYER");
	print_at(5,14,"5 = SKILL 1/TWO PLAYER");
	print_at(5,16,"6 = SKILL 2/TWO PLAYER");
	print_at(5,18,"7 = SKILL 3/TWO PLAYER");
	print_at(5,20,"8 = SKILL 4/TWO PLAYER");
	screen_on();
	
	enable_nmi();

	while(1)
	{
		if (keypad_1==1) {difficulty = -1;nbjoueurs=1;break;}
		if (keypad_1==2) {difficulty = 0;nbjoueurs=1;break;}
		if (keypad_1==3) {difficulty = 2;nbjoueurs=1;break;}
		if (keypad_1==4) {difficulty = 5;nbjoueurs=1;break;}
		if (keypad_1==5) {difficulty = -1;nbjoueurs=2;break;}
		if (keypad_1==6) {difficulty = 0;nbjoueurs=2;break;}
		if (keypad_1==7) {difficulty = 2;nbjoueurs=2;break;}
		if (keypad_1==8) {difficulty = 5;nbjoueurs=2;break;}
		if (joypad_1 & LEFT)
		{
			if (keypad_1==9) {easter=1;break;}
		}
	}

	if (easter==1) credits();
	//disable_nmi();
}




void main(void)
{
	byte i,j;
	

	
	activateNmi=S_FALSE;
	cheat=0;

	screen_mode_2_bitmap();
	set_snd_table(snd_table);
	showSplash();
	rle2vram(SPATTERNRLE,sprtab);
	while(1)
	{
		activateNmi=S_FALSE;	
		gameTimerFast = 5;
		difficulty = -1;
		gameTimerSlow = 0;
		nrj = 15000;
	
		currentFlicker = 1;
		littleTimer = 1;
		explode_timer = 0;
		explode_x = 0;
		explode_y = 0;
		explodeFond[0] = 32;
		explodeFond[1] = 32;
		explodeFond[2] = 32;
		explodeFond[3] = 32;
	
		currentEtoileCaractere = 136;
		currentEtoileColorPosition = 1;
		currentEtoileColorPosition8=8;
		currentCycle = 0;
		initSpriteLibre();
		menu();							// Affiche le Menu
		screen_off();
		disable_nmi();
		
		//load_patternrle(PATTERNRLE);
		//duplicate_pattern();
		rle2vram(COLORRLE,coltab);
		rle2vram(COLORRLE,coltab+2048);
		rle2vram(COLORRLE,coltab+4096);
		
		changeFontColor(7,1);
		
		for (i=0;i<32;i++)
		for (j=0;j<24;j++)
		put_char(i,j,32);
		
		screen_on();
		enable_nmi();
		
		initPlayer();

		
		currentLevel = 0;
		gameTimerSlow = 0;
		
		player.score = 0;
		
		// Version 1 joueurs
		if (nbjoueurs==1)
		{
			while (1)
			{
				activateNmi=S_FALSE;	
				initSpriteLibre();
				reinitPlayer();
				initLevel();
				initAlien();
				currentEtoileCaractere = 136;
				currentEtoileColorPosition = 1;
				currentEtoileColorPosition8=8;
				currentCycle = 0;
				if ( (currentLevel==0) || (currentLevel==1) || (currentLevel==4) || (currentLevel==6) ) dockin(1); 
				if (gameLoop()==GO_GAMEOVER) break;
				currentLevel ++;
				gameTimerSlow = 0;
				if (currentLevel==9) currentLevel = 0;
			}
		}
		else
		{
			currentPlayer = 1;
			nbPlayerAlive=2;
			
			// Initialisation des donneés à "sauvegarder" (pour le joueur 2 au départ)
			save_currentLevel = currentLevel;
			save_nrj = nrj;
			save_score = 0;
			
			// VERSION 2 JOUEURS A CODER
			while (1)
			{
				activateNmi=S_FALSE;	
				initSpriteLibre();
				reinitPlayer();
						if (currentPlayer==1) 
						{
							sprites[0].colour = 7;
						}
						else 
						{
							sprites[0].colour = 11;
						}						
				
				initLevel();
				initAlien();
				currentEtoileCaractere = 136;
				currentEtoileColorPosition = 1;
				currentEtoileColorPosition8=8;
				currentCycle = 0;
				
				if ( (currentLevel==0) || (currentLevel==1) || (currentLevel==4) || (currentLevel==6) ) dockin(currentPlayer); 
				
				if (gameLoop()==GO_GAMEOVER) // Un joueur est mort 
				{
					if (nbPlayerAlive==2)	// Si il y avait encore 2 joueurs
					{
							nbPlayerAlive = 1;	// Il en reste plus qu'un
							currentLevel = save_currentLevel; // Et on le remet ou il était
							nrj = save_nrj;
							player.score = save_score;	

							if (currentPlayer==1) // Quel est le joueur vivant ?
								currentPlayer=2; 
							else 
								currentPlayer=1;
					}
					else
					{
						// Game over des 2 joueurs
						break;
					}									
				}
				else
				{
					if (nbPlayerAlive==1)
						currentLevel++;
				}
				// Ici, on va swaper de joueurs si il y en à 2 de vivant et qu'on est fin de niveau!!!
				if (nbPlayerAlive==2)
				{
					if ( (currentLevel==0) || (currentLevel==3) || (currentLevel==5) || (currentLevel==8) )
					{
						tmp_currentLevel = currentLevel;
						tmp_nrj = nrj;
						tmp_score = player.score;												
						
						currentLevel = save_currentLevel;
						nrj = save_nrj;
						player.score = save_score;
						
						save_currentLevel = tmp_currentLevel+1;
						save_nrj = tmp_nrj;
						save_score = tmp_score;
						
						if (currentPlayer==1) 
							currentPlayer =2; 
						else 
							currentPlayer=1;					
					}
					else
					currentLevel++;
				}
				

					
				gameTimerSlow = 0;
				if (currentLevel==9) currentLevel = 0;
			}			
		}
	}
	
}

void nmi(void)
{				
	++ticks;
	if (activateNmi==S_TRUE)
	{
		if (gameTimerFast==0)
		{
			cycleArrierePlan();
			print_at(10,0,str(nrj));
			print_at(24,0,str(player.score));
			//print_at(24,0,str(difficulty));
		}	
		else
		{
			if (currentFlicker==2) put_vram (0x1b00,sprites,128); 
			else 
			{
				memcpyb(bsprites,sprites+16,64);
				memcpyb(bsprites+16,sprites,64);
				put_vram (0x1b00,bsprites,128);				
			}
		}
	}
}
