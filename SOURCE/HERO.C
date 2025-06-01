//Hero .

#ifndef _M_HERO_
#define _M_HERO_

#include "decl.h"
#include "effects.c"
#include "collisio.c"
#include "bullets.c"
#include "stat.c"
#include "shots.c"
#include "sounds.c"
#include "options.c"

void chkdead()
{
if(!active&&!lives){done=1;}
}

void evhandle()
{
if(keypressed())
{
if(key[KEY_ESC]){pex(PEX);}
evshandle();
doshandle();
if(key[KEY_P]){pex(PNOEX);}
if(key[KEY_O]){optloop();}
if(key[KEY_T]) {chstat(); }
if(key[KEY_SPACE]){genbullet();poll_keyboard();}
if(key[KEY_UP])
{
if(shipy>0){shipy-=SHSPEED;}
else thrashstarfield(NODIR,YPDIR);
}
if(key[KEY_DOWN])
{
if(shipy<(YRES-1-SHSPEED-HHEIGHT)){shipy+=SHSPEED;}
else thrashstarfield(NODIR,YNDIR);
}
if(key[KEY_LEFT])
{
if(shipx>0){shipx-=SHSPEED;}
else thrashstarfield(XPDIR,NODIR);
}
if(key[KEY_RIGHT])
{
if(shipx<(XRES-1-SHSPEED-HWIDTH)) {shipx+=SHSPEED;}
else thrashstarfield(XNDIR,NODIR);
}
change_bulltype();
clear_keybuf();
}
shipx%=XRES;shipy%=YRES;
chkdead();
}

void updeclife()
{
if(active<=0){active=0;lives--;}
}

void UpdateHero()
{
 for(i=0;i<NUMENEMIES;i++)
 {
  if(enemies[i].active&&collide(enemies[i].x,enemies[i].y,EWIDTH(i),EHEIGHT(i),shipx,shipy,HWIDTH,HHEIGHT))
  {
   blaf=1;
   enemies[i].active=0;
   enemies[i].explframe=0;
   active-= enemydam[enemies[i].type];
   if(active<0){active=0;}
  } 
 }
}

void drawhero()
{
if(blaf>0)
{
if(active>0)
{
cur=shipblank;
blaf++;
if(blaf==MAXBLAF)
{
blaf=0;
}
}
else
{
cur=shipbs[shipframe];shipframe++;shipframe%=SHFRAMES;
}
}
else
{
if((gen%FREQUENCY)<(SHBLFRAMES*PARAM))
{
cur=shipbl[shipblframe/PARAM];shipblframe++;shipblframe%=(SHBLFRAMES*PARAM);
}
else
{
cur=shipbs[shipframe];
shipframe++;shipframe%=SHFRAMES;
}
}
masked_blit(cur,dbuffer,0,0,shipx,shipy,cur->w,cur->h);
}

#endif //_M_HERO_
