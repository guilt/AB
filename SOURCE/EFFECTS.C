//Special Effects .

#ifndef _M_FX_
#define _M_FX_

#include "pal.c"
#include "decl.h"
#include "sounds.c"
#include "shots.c"

void gameover()
{
clear_keybuf();
docolorscale(dbuffer,0,0,XRES,YRES);
gm=0;
stopmusic();
if(!win)
{
sndgexplode();
while(1)
{
alfont_textout_centre(dbuffer,alfy,GOVSTR,getmidx(),getmidy()-FSIZE,govcol);
render();
updgovcol();
gen++;
if(keypressed()){doshandle();if(keypressed()){break;}}
}
rest(GST);
ssndgexplode();
}
else
{
sndwon(); 
while(1)  
{
alfont_textout_centre(dbuffer,alfy,WINSTR,getmidx(),getmidy()-FSIZE,govcol);
render();
updgovcol();
gen++;
if(keypressed()){doshandle();if(keypressed()){break;}}
}
rest(GST);
ssndwon();
}
clear_keybuf();
playmusic();
}

void pex(int fl)
{
 clear_keybuf();
 if(fl)
 { 
 alfont_textout_centre_aa(dbuffer,alfy,QDSTR,getmidx(),getmidy()-FSIZE,activecol);
 }
 else
 {
 alfont_textout_centre_aa(dbuffer,alfy,PAUSESTR,getmidx(),getmidy()-FSIZE,activecol);
 }
 render();
 while(1)
 {
  if(keypressed())
  {
  doshandle();
  if(fl)
  {
  if(key[KEY_Y]){done=2;clear_keybuf();return;}
  if(key[KEY_N]){clear_keybuf();rest(GST);return;}
  if(key[KEY_ESC]){clear_keybuf();rest(GST);return;}
  }
  else
  {
  if(key[KEY_P]){clear_keybuf();rest(GST);return;}  
  }
  }
 }
}

void restartmsg()
{
 clear_keybuf();
 docolorscale(dbuffer,0,0,XRES,YRES);
 sndgexplode();
 alfont_textout_centre_aa(dbuffer,alfy,KEYSTR,getmidx(),getmidy()-FSIZE,activecol);
 render();
 while(1)
 {
 if(keypressed()){doshandle();if(keypressed()){break;}}
 }
 clear_keybuf();
 ssndgexplode();
 rest(GST);
}

void starfieldinit()
{
setrand();
for(i=0;i<NUMSTARS;i++)
{
stars[i].x=rand()%XRES;
stars[i].y=rand()%YRES;
stars[i].state=rand()%LAYERS;
}
}

void updatestarfield()
{
for(i=0;i<NUMSTARS;i++)
{
stars[i].x+=XRES-(SSPEED*(stars[i].state+1));stars[i].x%=XRES;
}
}

void thrashstarfield(int xd,int yd)
{
for(i=0;i<NUMSTARS;i++)
{
stars[i].x+=XRES+(SSPEED*xd);stars[i].x%=XRES;
stars[i].y+=YRES+(SSPEED*yd);stars[i].y%=YRES;
}
}

void drawstarfield()
{
setrand();
for(i=0;i<NUMSTARS;i++)
{
putpixel(dbuffer,stars[i].x,stars[i].y,starcolors[rand()%LAYERS]);
}
}

void CheckExplode(int i)
{
if(enemies[i].explframe >= 0 && enemies[i].explframe < (MUL*NUMEXPLODE) )
{
 if(enemies[i].explframe==0)
 {
  sndexplode();
 }
 enemies[i].enemybs=explodeframe[((int)(enemies[i].explframe/MUL))%NUMEXPLODE];  
 masked_blit(enemies[i].enemybs,dbuffer,0,0,enemies[i].x,enemies[i].y,enemies[i].enemybs->w,enemies[i].enemybs->h); 
}
if(enemies[i].explframe>=0 )
{
 enemies[i].explframe++;
}
}
 
#endif // _M_FX_
