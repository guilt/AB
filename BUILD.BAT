@REM Requires Linking of Allegro, AlFont and DUMB.
@ECHO OFF

REM UPX Compression
SET UPX_EXE=upx
SET UPX_FLAGS=--best --nrv2e --strip-relocs=0 --overlay=strip

REM Use MinGW
SET CC=gcc
SET RC=windres
SET LD=gcc
SET DEFINES=-DDEL -DADEL -DDUMB
SET CFLAGS=-O2 -Wall -fomit-frame-pointer
SET CLFLAGS=-static -static-libgcc -static-libstdc++ -m32 -mwindows
SET LIBS=-lalfont -laldmb -ldumb -lalleg

MKDIR OBJ
CD OBJ

ECHO Resource Compiling ...
%RC% ..\RC\MAIN.RC -o MAINICON.OBJ

ECHO Compiling ...
%CC% %CFLAGS% %CLFLAGS% %DEFINES% -c ..\SOURCE\MAIN.C -o MAIN.OBJ

CD..

ECHO Linking ...
%LD% %CLFLAGS% -o AB.EXE OBJ\*.* %LIBS%

ECHO UPX Compression ...
%UPX_EXE% %UPX_FLAGS% AB.EXE

ECHO Build Finished.
