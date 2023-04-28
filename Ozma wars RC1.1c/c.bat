path c:\sdcc\bin
@echo off
sdcc -mz80 -c --std-c99 --opt-code-speed bios0.c
del bios0.lst
del bios0.sym
del bios0.asm
sdcc -mz80 -c --std-c99 --opt-code-speed bios1.c
del bios1.lst
del bios1.sym
del bios1.asm
sdcc -mz80 -c --std-c99 --opt-code-speed charset.c
del charset.lst
del charset.sym
del charset.asm
sdcc -mz80 -c --std-c99 --opt-code-speed levels.c
del levels.lst
del levels.sym
del levels.asm
sdcc -mz80 -c --std-c99 --opt-code-speed main.c
del main.lst
del main.sym
del main.asm
sdasz80 -o music.rel music.s
sdcc -mz80 -c --std-c99 --opt-code-speed sprites.c
del sprites.lst
del sprites.sym
del sprites.asm
pause
