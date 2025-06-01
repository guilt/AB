//Screenshots !

#ifndef _M_SHOTS_
#define _M_SHOTS_
 
#include "decl.h" 
#include "files.h"
#include "flog.c"

void doshot()
{
int k=0,sdone=0;
char fname[STRB];
for(;!sdone;k++)
{
sprintf(fname,FShot,k+1);
if(!fexist(fname))
{
if(!save_bitmap(fname,dbuffer,pal))
{sdone=1;sprintf(logmsg,"Screenshot written to : %s",fname);ininwrite=1;logwrite();} //Ok ,Done !
}
}
}

void doshandle()
{
if(key[KEY_PRTSCR]){rest(SDT);} //This may prevent guys from Print-Screening over time ....
else if(key[KEY_F12]){doshot();}
else{return;}
clear_keybuf();
}

#endif //_M_SHOTS_
