//Options Loop

#ifndef _M_OPT_
#define _M_OPT_

#include "decl.h"
#include "stat.c"
#include "sounds.c"

//Options Draw Loop .
void DrawOptMenu()
{
 cls();
 updatestarfield();
 drawstarfield();
 masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
 //Initialise .
 buff[0]=0;
 //Statistics .
 sprintf(buff,omenu[2],flaSTR[sflag]);
 if(osel==2)
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(2*(FSIZE+VERTSPC)),activecol);
 else
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(2*(FSIZE+VERTSPC)),passivecol);
 if(!serr)
 {
 //Sound .
 sprintf(buff,omenu[0],flaSTR[plsounds]);
 if(osel==0)
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET,activecol);
 else
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET,passivecol);
 //Music .
 sprintf(buff,omenu[1],flaSTR[plmusic]);
 if(osel==1)
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+FSIZE+VERTSPC,activecol);
 else
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+FSIZE+VERTSPC,passivecol);
 //DIGI Vol .
 sprintf(buff,omenu[3],DVOL);
 if(osel==3)
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(3*(FSIZE+VERTSPC)),activecol);
 else
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(3*(FSIZE+VERTSPC)),passivecol);
 /*
 //MIDI Vol .
 sprintf(buff,omenu[4],MVOL);
 if(osel==4)
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(4*(FSIZE+VERTSPC)),activecol);
 else
 alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET+(4*(FSIZE+VERTSPC)),passivecol);
 */
 }
 render();
}

//Options Loop .
void optloop()
{
int omdone=0;
 do
 {
  clear_keybuf();
  DrawOptMenu();
  if(keypressed())
  {
   if(key[KEY_ESC]) { omdone=1; }
   evshandle();
   doshandle();
   if(key[KEY_UP]) {osel+=NUMOPTMENUITEMS-1;osel%=NUMOPTMENUITEMS;}
   if(key[KEY_DOWN]) { osel++;osel%=NUMOPTMENUITEMS; }
   if(key[KEY_ENTER])
   {
   switch(osel)
   {
   case 0: togglesound();break;
   case 1: togglemusic();break;
   case 2: chstat();break;
   }
   }
   if(key[KEY_RIGHT])
    {
    switch(osel)
    {
     case 3: if(DVOL<VOLUME)DVOL++;DVOL%=(VOLUME+1);dovol();ininwrite=1;break;
    //case 4: if(MVOL<VOLUME)MVOL++;MVOL%=(VOLUME+1);dovol();ininwrite=1;break;
    }
    }
    if(key[KEY_LEFT])
    {
    switch(osel)
    {
    case 3: if(DVOL>0)DVOL+=VOLUME;DVOL%=(VOLUME+1);dovol();ininwrite=1;break;
    //case 4: if(MVOL>0)MVOL+=VOLUME;MVOL%=(VOLUME+1);dovol();ininwrite=1;break;
    }
    }
    }
  clear_keybuf();
 }while(!omdone);
 rest(GST);
 clear_keybuf();
}

#endif //_M_OPT_
