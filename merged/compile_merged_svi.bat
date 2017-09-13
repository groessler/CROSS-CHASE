@REM 
set cc65path="C:\Retro\DEV\cc65-snapshot-win32"
@REM 
set mypath="C:\Users\Brizio\Documents\GitHub\PortableChase\merged"
@REM 
set configpath="C:\Users\Brizio\Documents\GitHub\PortableChase\merged\experiments"

@REM set cc65path="D:\personal\cc65-snapshot-win32"
@REM set configpath="D:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE\minimal\cfg"
@REM set mypath="d:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE\minimal"

@REM set cc65path="C:\cc65-snapshot-win32"
@REM set configpath="C:\Users\Brizio\Retro\ASCII-CHASE\merged\cfg"
@REM set mypath="C:\Users\Brizio\Retro\ASCII-CHASE\merged"



set Deliverables=%mypath%\deliverables

mkdir %deliverables% 2> NUL

@REM del %deliverables%\*.prg
@REM del %deliverables%\*.bin
@REM del %deliverables%\*.xex
@REM del %deliverables%\*.tap
del %mypath%\*.o
del %mypath%\atmos\*.o
del %mypath%\c64\*.o
del %mypath%\patch\*.o

cd %cc65path%\bin\

@REM 
cd %mypath%\


@REM CPC HALF-WORKINg
@REM -DDEBUG_CHARACTERS
@REM 

@REM 
zcc +svi  -vn -lndos -D__SVI__ -DVPOKE -create-app -subtype=wav -o  %deliverables%\MINIMAL_svi %mypath%\display_macros.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input_macros.c %mypath%\main.c


@REM zcc +svi  -vn -lndos -D__MTX__ -create-app -subtype=wav -o  %deliverables%\MINIMAL_svi %mypath%\test_a5200.c

del %mypath%\*.o
del %mypath%\atmos\*.o
del %mypath%\c64\*.o
del %mypath%\patch\*.o
