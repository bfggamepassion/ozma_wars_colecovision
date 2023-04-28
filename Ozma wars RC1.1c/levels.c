#include <coleco.h>

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




const byte level1TimeLine[]=
	{
		1,2,							      // En TimeLine 1*16 , il y aura 4 objets à créer
		239,0,ENERGIZER1,MVT_ENERGIZER_NOSHOOT,255,0,ENERGIZER2,MVT_ENERGIZER,	// Posx,Posy,Type d'objet,mvt,*4	
		
		
		25,4,				// En TimeLine 25 4 Objets de type Alien 1
		48,0,ALIEN2,MVT_ALIEN1,
		48*2,0,ALIEN2,MVT_ALIEN2,
		48*3,0,ALIEN2,MVT_ALIEN3,
		48*4,0,ALIEN2,MVT_ALIEN4,
	
		
		
		30,2,		// En TimeLine	30	2 Objects
		48,0,ALIEN1,MVT_ALIEN5,
		48*4,0,ALIEN1,MVT_ALIEN1,//MVT_ALIEN5MIRROR,
		37,1,		// En TimeLine	30	2 Objects
		48*3,0,ALIEN1,MVT_ALIEN5,
		41,1,		
		48*2,0,ALIEN1,MVT_ALIEN5MIRROR,
			
		48,1,
		48+64,0,ALIEN1,MVT_ALIEN5,
		50,2,
		48+32,0,ALIEN1,MVT_DROITSHOOT,
		(48*4) - 32,0,ALIEN1,MVT_ALIEN5MIRROR,
		52,2,
		48+16,0,ALIEN1,MVT_ALIEN5,
		(48*4) - 16,0,ALIEN1,MVT_ALIEN5MIRROR,
		53,2,
		48,0,ALIEN1,MVT_ALIEN5,
		48*4,0,ALIEN1,MVT_ALIEN5MIRROR,
		
		
		64,2,
		48,0,ASTEROID,MVT_AST1,
		48*2,0,ASTEROID,MVT_AST1,
		66,2,
		48*3,0,ASTEROID,MVT_AST1,
		48*4,0,ASTEROID,MVT_AST1,
		68,2,
		48,0,ASTEROID,MVT_AST2,
		48*2,0,ASTEROID,MVT_AST2,
		70,2,
		48*3,0,ASTEROID,MVT_AST2,
		48*4,0,ASTEROID,MVT_AST2,
		71,2,
		48,0,ASTEROID,MVT_AST1,
		48*2,0,ASTEROID,MVT_AST1,
		73,2,
		48*3,0,ASTEROID,MVT_AST1,
		48*4,0,ASTEROID,MVT_AST1,
		
		
		
		
		95,1,
		48,0,ALIEN2,MVT_ALIEN1,//,MVT_DROITSHOOT,
		97,2,
		48*2,0,ALIEN2,MVT_ALIEN2,//,MVT_ALIEN5,
		48*3,0,ALIEN2,MVT_ALIEN3,//,MVT_ALIEN5MIRROR,
		99,1,
		48*4,0,ALIEN2,MVT_ALIEN4,//,MVT_DROITSHOOT,
		
		
		102,1,
		48*4,0,ALIEN1,MVT_DROITSHOOT,//,MVT_DROITSHOOTDIRIGE,
		103,1,
		48*3,0,ALIEN1,MVT_DROITSHOOT,
		104,1,
		48,0,ALIEN1,MVT_DROITSHOOT,
		105,1,
		48*2,0,ALIEN1,MVT_DROITSHOOT,//,MVT_DROITSHOOTDIRIGE,
	
	
		108,2,
		48+16,0,ALIEN3,MVT_ALIEN6,
		48*4-16,0,ALIEN3,MVT_ALIEN6INVERSE,
		
		111+20,2,
		48*2,0,ALIEN3,MVT_ALIEN6,
		48*3,0,ALIEN3,MVT_ALIEN6INVERSE,
		122+50,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,

		133+50,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		144+50,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		
		160+50,4,
		248-(16*3),16,COMETE1,MVT_COMETE,
		248-(16*2),16,COMETE2,MVT_COMETE,
		248-(16*2),0,COMETE3,MVT_COMETE,
		248-16,0,COMETE4,MVT_COMETE,
							
		255};							     // Fin de la timeLine (255*16)
		
const byte level2_1TimeLine[]=
	{
	
		1,2,							      // En TimeLine 1*16 , il y aura 4 objets à créer
		239,0,ENERGIZER1,MVT_ENERGIZER_NOSHOOT,255,0,ENERGIZER2,MVT_ENERGIZER,	// Posx,Posy,Type d'objet,mvt,*4	
		
		25,4,
		0,0,APPARINGALIEN,MVT_APPARINGALIEN,
		48,8,APPARINGALIEN,MVT_APPARINGALIEN,
		48*2,16,APPARINGALIEN,MVT_APPARINGALIEN,
		48*3,24,APPARINGALIEN,MVT_APPARINGALIEN,

		32,4,
		0+16,0,APPARINGALIEN,MVT_APPARINGALIEN,
		48+16,8,APPARINGALIEN,MVT_APPARINGALIEN,
		(48*2)+16,16,APPARINGALIEN,MVT_APPARINGALIEN,
		(48*3)+16,24,APPARINGALIEN,MVT_APPARINGALIEN,
		
		100,1,
		120,0,MIDBOSS1,2,
		
		255};

const byte level2_2TimeLine[]=
	{	
		1,2,
		144,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		112,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		3,2,
		64,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		192,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		5,2,
		144,0,ROTATING,MVT_ROTATINGALIENNEXTLEVEL,
		112,0,ROTATING,MVT_ROTATINGALIENNEXTLEVEL,
		
		255};
	
const byte level2_3TimeLine[]=
	{	
		1,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		3,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		5,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		7,1,
		176,0,SPLITALIEN,MVT_SPLITTER,
		
		20,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,

		31,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		42,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		60,4,
		248-(16*3),16,COMETE1,MVT_COMETE,
		248-(16*2),16,COMETE2,MVT_COMETE,
		248-(16*2),0,COMETE3,MVT_COMETE,
		248-16,0,COMETE4,MVT_COMETE,
		
		255};	
		
const byte level3_1TimeLine[]=
	{
		1,2,							      // En TimeLine 1*16 , il y aura 4 objets à créer
		239,0,ENERGIZER1,MVT_ENERGIZER_NOSHOOT,255,0,ENERGIZER2,MVT_ENERGIZER,	// Posx,Posy,Type d'objet,mvt,*4	
		
		25,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		27,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		29,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		31,1,
		176,0,SPLITALIEN,MVT_SPLITTER,
		
		60,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		62,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		64,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		66,1,
		176,0,SPLITALIEN,MVT_SPLITTER,		
		
		90,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		92,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		94,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		96,1,
		176,0,SPLITALIEN,MVT_SPLITTER,
		
		125,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,

		136,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		147,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		160,2,
		48,0,ALIEN3,MVT_ALIEN6,
		48*4,0,ALIEN3,MVT_ALIEN6INVERSE,
		
		170,2,
		48*2,0,ALIEN3,MVT_ALIEN6,
		48*3,0,ALIEN3,MVT_ALIEN6INVERSE,
		
		175,1,
		120,0,MIDBOSS1,2,
		
		255};

const byte level3_2TimeLine[]=
{	
		1,4,
		248-(16*3),16,COMETE1,MVT_COMETE,
		248-(16*2),16,COMETE2,MVT_COMETE,
		248-(16*2),0,COMETE3,MVT_COMETE,
		248-16,0,COMETE4,MVT_COMETE,		
255};	
		

const byte level4_1TimeLine[]=
{	
		1,2,							      // En TimeLine 1*16 , il y aura 4 objets à créer
		239,0,ENERGIZER1,MVT_ENERGIZER_NOSHOOT,255,0,ENERGIZER2,MVT_ENERGIZER,	// Posx,Posy,Type d'objet,mvt,*4	

		25,4,
		0,0,APPARINGALIEN,MVT_APPARINGALIEN,
		48,8,APPARINGALIEN,MVT_APPARINGALIEN,
		48*2,16,APPARINGALIEN,MVT_APPARINGALIEN,
		48*3,24,APPARINGALIEN,MVT_APPARINGALIEN,

		32,4,
		0+16,0,APPARINGALIEN,MVT_APPARINGALIEN,
		48+16,8,APPARINGALIEN,MVT_APPARINGALIEN,
		(48*2)+16,16,APPARINGALIEN,MVT_APPARINGALIEN,
		(48*3)+16,24,APPARINGALIEN,MVT_APPARINGALIEN,
		
		60,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		62,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		64,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		66,1,
		176,0,SPLITALIEN,MVT_SPLITTER,		
		
		90,4,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48+32,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48+48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48+48+32,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,

		101,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		112,3,
		48,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*2,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		48*3,0,CLOACKINGALIEN,MVT_ALIENCLOACKING,
		
		124,1,
		120,0,MIDBOSS1,2,
		
255};	
		
const byte level4_2TimeLine[]=
{	
		1,1,
		80,0,SPLITALIEN,MVT_SPLITTER,
		3,1,
		112,0,SPLITALIEN,MVT_SPLITTER,
		5,1,
		144,0,SPLITALIEN,MVT_SPLITTER,
		7,1,
		176,0,SPLITALIEN,MVT_SPLITTER,	

		100,2,
		144,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		112,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		103,2,
		160,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		96,0,ROTATING,MVT_ROTATINGALIENNONEXTLEVEL,
		105,2,
		144,0,ROTATING,MVT_ROTATINGALIENNEXTLEVEL,
		112,0,ROTATING,MVT_ROTATINGALIENNEXTLEVEL,				
		
255};	
		
const byte level4_3TimeLine[]=
{	
		1,4,
		248-(16*3),16,COMETE1,MVT_COMETE,
		248-(16*2),16,COMETE2,MVT_COMETE,
		248-(16*2),0,COMETE3,MVT_COMETE,
		248-16,0,COMETE4,MVT_COMETE,		
255};	
		
const byte* levelsTimeLine[]=
{
	level1TimeLine,
	level2_1TimeLine,
	level2_2TimeLine,
	level2_3TimeLine,
	level3_1TimeLine,
	level3_2TimeLine,
	level4_1TimeLine,
	level4_2TimeLine,
	level4_3TimeLine
};		

const char mvtSplitter[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,MVT_SHOOT,8,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,
		1,0,1,
		1,-1,1,		
		1,MVT_SHOOT,1,
		10,-1,+1,
		10,0,+1,
		1,MVT_SHOOT,1,
//		10,1,+1,
//		10,0,+1,
		1,MVT_SPLIT,0, // Type de split = 0
		MVT_LOOP,MVT_LOOP
};

const char mvtMiniSplitter[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,-1,+1,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,1,+1,
		10,0,+1,
		MVT_LOOP,MVT_LOOP
};

const char mvtMiniSplitter2[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,-2,+1,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,1,+1,
		10,0,+1,
		MVT_LOOP,MVT_LOOP
};

const char mvtMiniSplitter3[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,+2,+1,
		10,0,+1,
		1,MVT_SHOOT,1,
		10,1,+1,
		10,0,+1,
		MVT_LOOP,MVT_LOOP
};
const char alientRotatingMvtNextLevel[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		1,MVT_SHOOT,2,
		1,MVT_NEXTLEVEL,MVT_NEXTLEVEL,
		20,0,1,
		1,MVT_SHOOT,7,
		20,0,1,
		1,MVT_SHOOT,1,
		20,0,1,
		1,MVT_SHOOT,2,
		20,0,1,
		1,MVT_SHOOT,7,
		6,0,1,
		20,0,0,
		1,MVT_SHOOT,7,
		1,MVT_LOOP,9, 
		//86,0,+1,
		//1,MVT_FREEZE,MVT_FREEZE,
		MVT_LOOP,MVT_LOOP
};

const char alientRotatingMvtNoNextLevel[] =
{
		1,				// Vitesse : 1 lent
		0,0,0,
		//100,0,+1,
		1,MVT_SHOOT,2,
		30,0,+1,
		1,MVT_SHOOT,1,
		30,0,1,
		1,MVT_SHOOT,7,
		40,0,1,
		1,MVT_SHOOT,1,
		20,0,0,
		1,MVT_SHOOT,7,
		20,0,0,
		1,MVT_SHOOT,7,
		20,0,0,
		1,MVT_LOOP,9, // On revient à 20,0,0 
		MVT_LOOP,MVT_LOOP
};

const char alientMvtNull[] =
{
	255,255
};

// 127 - Fin de mouvement
// 126 - Action : Tirer
const char alienMvt1[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		10,+1,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		20,+0,+1,
		10,-1,+1,
//		1,MVT_SHOOT,1,			// 1 Shoot type 1
		20,+0,+1,
/*		
		25,+0,+1,
		25,+0,+1,
		25,+1,+1,
		1,MVT_SHOOT,1,
		25,+0,+1,
		25,+1,+1,
		25,+0,+1,
*/		
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char alienMvt2[] = // BAS,SHOOT,DROITE,SHOOT,BAS
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		5,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		100,+0,+1,
		3,+0,+1,		
		1,+1,+1,
		1,MVT_LOOP,9,
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char alienMvt3[] = // BAS,SHOOT,GAUCHE,SHOOT,BAS
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		5,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		50,+0,+1,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,
		1,0,1,
		1,0,2,		
		3,+0,+1,		
		1,-1,+2,
		1,MVT_LOOP,9,
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};	
	
const char alienMvt4[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		10,-1,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		20,+0,+1,
		10,+1,+1,
//		1,MVT_SHOOT,1,			// 1 Shoot type 1
		20,+0,+1,		
/*		
		25,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		25,+0,+1,
		25,+0,+1,
		25,-1,+1,
		1,MVT_SHOOT,1,
		25,+0,+1,
		25,-1,+1,
		25,+0,+1,*/
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};

const char alienMvt5[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		25,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		50,+1,+1,
		1,MVT_SHOOT,1,
		100,-1,+1,
		1,MVT_SHOOT,1,
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char alienMvt5Mirror[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		2,				// Vitesse : 1 lent
		0,0,0,
		25,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,1,			// 1 Shoot type 1
		50,-1,+1,
		1,MVT_SHOOT,1,
		100,+1,+1,
		1,MVT_SHOOT,1,
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char ateroidMvt1[] =
{
	1,
	0,0,0,
	10,0,1,
	20,1,1,
	20,-1,1,
	20,1,1,
	20,-1,1,
	100,0,3,
	MVT_LOOP,MVT_LOOP
};

const char ateroidMvt2[] =
{
	1,
	0,0,0,
	10,0,1,
	20,-1,1,
	20,1,1,
	20,-1,1,
	20,1,1,
	100,0,3,
	MVT_LOOP,MVT_LOOP
};

const char ateroidMvt3[] =
{
	3,
	0,0,0,
	2,0,1,
	1,1,1,
	MVT_LOOP,MVT_LOOP
};

const char ateroidMvt4[] =
{
	3,
	0,0,0,
	2,0,1,
	1,-1,1,
	MVT_LOOP,MVT_LOOP
};



const char energizerMvt[] =
{
	1,
	0,0,0,
	1,MVT_PLAYMUSIC,1,
	40,-3,+2,
	5,-2,0,
	1,MVT_STOPMUSIC,1,
	1,MVT_SHOOT,3,   // 1 shoot type energy beam
	100,0,0,
	1,MVT_DESTROY_ALL_SHOOT,0,
	1,MVT_PLAYMUSIC,1,
	35,-3,0,
	1,MVT_STOPMUSIC,1,
	1,MVT_DESTROY,MVT_DESTROY,
	MVT_LOOP,MVT_LOOP
};
	
const char energizerMvtNoShoot[] =
{
	1,
	0,0,0,
	1,0,0,
	40,-3,+2,   // 1 shoot type energy beam
	5,-2,0,
	1,0,0,
	1,0,0,
	100,0,0,
	1,MVT_DESTROY_ALL_SHOOT,0,
	1,0,0,
	35,-3,0,
	1,0,0,
	1,MVT_STOPMUSIC,1,
	1,MVT_DESTROY,MVT_DESTROY,
	MVT_LOOP,MVT_LOOP
};
	
const char mvtDroitShoot[]=
{
	2,
	0,0,0,
	40,0,1,
	1,MVT_SHOOT,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini1[]=
{
	1,
	0,0,0,
	1,MVT_SHOOT,8,
	20,0,1,
	1,MVT_SHOOT,6, // Type 5 lent Type 6 rapide
	50,0,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini2[]=
{
	1,
	0,0,0,
	20,0,1,
	1,MVT_SHOOT,1,
	20,-1,1,
	10,0,1,
	10,1,1,
	10,-1,1,
	1,MVT_SHOOT,1,
	1,MVT_LOOP,15,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini3[]=
{
	1,
	0,0,0,
	20,0,1,
	1,MVT_SHOOT,1,
	20,+1,1,
	10,0,1,
	10,-1,1,
	10,1,1,
	1,MVT_SHOOT,1,
	1,MVT_LOOP,15,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini4[]=
{
	1,
	0,0,0,
	30,-1,1,
	1,MVT_SHOOT,8,
	100,0,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini5[]=
{
	1,
	0,0,0,
	30,+1,1,
	1,MVT_SHOOT,8,
	100,0,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini6[]=
{
	1,
	0,0,0,
	50,-1,1,
	1,MVT_SHOOT,8,
	100,0,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini7[]=
{
	1,
	0,0,0,
	50,1,1,
	1,MVT_SHOOT,8,
	100,0,1,
	MVT_LOOP,MVT_LOOP
};

const char mvtMini8[]=
{
	1,
	0,0,0,
	20,0,1,
	1,MVT_SHOOT,1,
	1,MVT_SHOOT,8,
	MVT_LOOP,MVT_LOOP
};

const char mvtDroitShootDirige[]=
{
	2,
	0,0,0,
	25,0,1,
	1,MVT_SHOOT,2,
	MVT_LOOP,MVT_LOOP
};

const char alienMvt6[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,4,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,
		5,+1,+1,
		1,+2,+1,
		5,+1,+1,
		10,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,4,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,
		5,-1,+1,
		1,-2,+1,
		5,-1,+1,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,		
		
		/*1,+2,+1,
		20,0,+1,
		1,+2,+1,
		20,0,+1,
		1,+2,+1,
		10,0,+1,*/
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char alienMvt6Inverse[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,4,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,
		10,-1,+1,
		10,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,4,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,
		10,+1,+1,				// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,		
/*		10,+0,+1,		// 1* 0,1
		1,MVT_SHOOT,4,			// 1 Shoot type 4 --> auto guidé
		1,MVT_SHOOT,1,
		1,-2,+1,
		20,0,+1,
		1,-2,+1,
		20,0,+1,
		1,-2,+1,
		10,0,+1,*/
		MVT_LOOP,MVT_LOOP			// Fin de mvt
	};
	
const char alienCloackingMvt[] =  // BAS,SHOOT,DROITE,SHOOT,GAUCHE,SHOOT
	{
		1,				// Vitesse : 1 lent
		0,0,0,
		10,+0,+1,		// 1* 0,1
		1,MVT_ANIMATE,MVT_ANIMATE,
		1,MVT_SHOOT,1,
		20,+1,+1,
		1,MVT_ANIMATE,MVT_ANIMATE,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
		1,+1,+1,
		1,0,+1,
//		20,+1,+1,
		1,MVT_ANIMATE,MVT_ANIMATE,
		40,-1,+1,
		1,MVT_SHOOT,1,
		20,0,+1,
		1,MVT_SHOOT,1,
		30,+1,+1,
		//1,MVT_SHOOT,1,
		20,0,+1,		
		1,MVT_SHOOT,1,
		40,-1,+1,
		100,+1,+1,
		100,+1,+1
	};
	
const char mvtComete[] = {
	1,
	0,0,0,
	1,MVT_STOPMUSIC,MVT_STOPMUSIC,
	1,MVT_PLAYMUSIC,2,
	1,-1,+1,
	1,MVT_LOOP,6,
	MVT_LOOP,MVT_LOOP};
	
const char mvtApparingAlien[] = {
	1,
	0,0,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	/*10,+1,+1,*/
	1,MVT_ANIMATE,MVT_ANIMATE,
	1,MVT_SHOOT,1,
	/*10,+1,+1,*/
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,MVT_ANIMATE,MVT_ANIMATE,
	1,MVT_SHOOT,1,
	/*30,0,+1,*/
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,1,1,
	1,1,0,
	1,MVT_ANIMATE,MVT_ANIMATE,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,+1,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,+1,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	20,0,+1,
	1,MVT_SHOOT,1,
	100,0,+1	
};


// mvt 0 à 4 = Mvt géré par l'IA	
const char* alienMvts[] =
{
	alientMvtNull,
	alientMvtNull,	
	alientMvtNull,	
	alientMvtNull,	
	alientMvtNull,		
	energizerMvt,			// 5
	energizerMvtNoShoot,	// 6
	alienMvt1,				// 7
	alienMvt2,				// 8
	alienMvt3,				// 9
	alienMvt4,				// 10
	alienMvt5,
	alienMvt5Mirror,
	ateroidMvt1,
	ateroidMvt2,
	mvtDroitShoot,			// 15
	mvtDroitShootDirige,
	alienMvt6,				//17
	alienMvt6Inverse,
	alienCloackingMvt, // 19
	mvtComete,
	mvtApparingAlien,	// 21
	alientRotatingMvtNextLevel, // 22
	alientRotatingMvtNoNextLevel, // 23
	mvtSplitter,
	mvtMiniSplitter,
	mvtMini1,
	mvtMini2,
	mvtMini3,
	mvtMini4,
	mvtMini5,
	mvtMini6,
	mvtMini7,
	mvtMini8,
	mvtMiniSplitter2,
	mvtMiniSplitter3
	
};
		