//System Declarations .

#ifndef _M_SYSDEFS_
#define _M_SYSDEFS_

//Headers
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "allegro.h"
#include "alfont.h"

#ifdef DUMB
#include "aldumb.h"
#else
#include "jgmod.h"
#endif //DUMB

#ifdef DUMB
#ifdef DUMBOGG
#include "vorbis/vorbisfile.h"
#include "dumbogg.h"
#endif //DUMBOGG
#endif //DUMB

//General
#ifndef DEL
#define DEL '\\' //Change for GNU/Linux etc.
#else
#undef DEL
#define DEL '/'
#endif //DEL
#ifndef ADEL
#define ADEL '/'
#else
#undef ADEL
#define ADEL '\\'
#endif //ADEL
#define ASPC '|'
#define SPC ' '
#define END '\n'
#define BSP '\b'
#define E_OK  0
#define E_ERR -1
#define STRB  80

//GFX
#define GM GFX_AUTODETECT //_FULLSCREEN
#define XRES 640
#define YRES 480
#define BPP 16
#define getmaxx() (XRES-1)
#define getmaxy() (YRES-1)
#define getminx() 0
#define getminy() 0
#define getmidx() XRES/2
#define getmidy() YRES/2
#define NUM_COLORS 256

//Videos
#define VLOOP 1
#define VNOLOOP 0

//Sound
#define SLOOP 1
#define SNOLOOP 0

#define MLOOP TRUE
#define MNOLOOP FALSE

#define SLEFT 0
#define SCENTER 127
#define SRIGHT 255

#define SPSLOW 500
#define SPNORMAL 1000
#define SPFAST 2000

#define DPAN SCENTER
#define SPEED SPNORMAL

#define NUMDIGV 8
#define NUMMIDV 8
#define SPV -1

#ifdef DUMB

#ifdef DUMBOGG
#define DUMBOGGLP 1 //Ogg Loopin' parameter
#endif //DUMBOGG

#define DUMB_MONO 1
#define DUMB_STEREO 2
#define DUMB_CHANNELS DUMB_STEREO

#define DUMB_POS 0
#define DUMB_FREQ 48000 //Or Whatever !
#define DUMB_BUFSIZE 8192 //Or Whatever !

#define DUMB_RES_QUAL 4
#define DUMB_ITM2M 64

#define DUMB_REFRESH (int)((1000*DUMB_BUFSIZE)/DUMB_FREQ) //Should Do the Trick .
#define DUMB_VOL 1.0

#define MUSIC DUH

#define music_exit() dumb_exit()

#else

#define NUMMODV 4

#define MUSIC JGMOD

#define music_exit()

#endif //DUMB

#define DIGMODE DIGI_AUTODETECT
#define MIDMODE MIDI_AUTODETECT

//Maximum Volume .
#define VOLUME 255

//KeyBoard
#define getch() while(!keypressed()){}clear_keybuf()

//For Sound .
unsigned int DVOL=VOLUME,MVOL=VOLUME,PAN=DPAN;

#ifdef ALLEGRO_STATICLINK
//I got this Fund. Straight !
int (*call) () = keypressed;
#else
#define call keypressed
#endif //ALLEGRO_STATICLINK


//Working version : courtesy Nikhil .
int strgetch()
{
int c;
if(keypressed())
{
if(key[KEY_ENTER]||key[KEY_ESC]){return END;}
if(key[KEY_SPACE]||key[KEY_TAB]){return SPC;}
if(key[KEY_BACKSPACE]){return BSP;}
c=readkey();
clear_keybuf();
return (c&0xff);
}
return END;
}

#endif //_M_SYSDEFS_

