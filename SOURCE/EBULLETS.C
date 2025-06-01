//Enemy Bullet Routines .

#ifndef _M_EBULL_
#define _M_EBULL_

#include "decl.h"
#include "hero.c"
#include "collisio.c"
#include "effects.c"
#include "sounds.c"

void ebullinit()
{
 for(i=0;i<MAXEBULLETS;i++)
 {
  ebullets[i].active=0;
  ebullets[i].type=0;
 }
 curebul=-1;
}

void genebullet(int k)
{
int ldone=0;
 curebul=-1;
 for(i=0;i<MAXEBULLETS&&!ldone;i++)
 {
  if
  (ebullets[i].active==0&&
  ebtype[enemies[k].type]>=0
  &&!((gen+1)%eblimit[ebtype[enemies[k].type]]))
  { 
    curebul=ebullets[i].type=ebtype[enemies[k].type];
    ebullets[i].bbs=ebullbs[ebullets[i].type]
    [((gen%(ebframes[ebullets[i].type]*EBMUL[ebullets[i].type]))/EBMUL[ebullets[i].type])];         
    ebullets[i].x=(enemies[k].x-EBWIDTH(i));
    ebullets[i].y=(enemies[k].y+(EHEIGHT(k)/2));
    if(collide(ebullets[i].x,ebullets[i].y,EBWIDTH(i),EBHEIGHT(i),
    getminx(),getminy(),getmaxx(),getmaxy()))
    {
    ldone=1;
    ebullets[i].active=1;
    sndeshoot();
    }
   }
 }
}

void updateebullets()
{
 for(i=0;i<MAXEBULLETS;i++)
 {
  if(ebullets[i].active)
  { 
   ebullets[i].bbs=ebullbs[ebullets[i].type]
   [((gen%(ebframes[ebullets[i].type]*EBMUL[ebullets[i].type]))/EBMUL[ebullets[i].type])];         
   if(!collide(ebullets[i].x,ebullets[i].y,EBWIDTH(i),EBHEIGHT(i),getminx(),
    getminy(),getmaxx(),getmaxy()))
   {
    ebullets[i].active=0;
   }
  }
}
}

void ebdisplace(int i)
{
ebullets[i].x -= xebspeed[ebullets[i].type]; 
}

void updateebulletsandhero()
{
for(i=0;i<MAXEBULLETS;i++)
{
 if(ebullets[i].active)
 {
    if(collide(ebullets[i].x,ebullets[i].y,EBWIDTH(i),EBHEIGHT(i),
    shipx,shipy,HWIDTH,HHEIGHT)) //Hero is Dying !
    {
     ebullets[i].active = 0;
     blaf=1;
     sndexplode();
     active -= ebdamage[ebullets[i].type];
     if(active<=0){active=EBFD;}
    }
  }
 }
}
  
void drawebullets()
{
for(i=0;i<MAXEBULLETS;i++)
 {
  if(ebullets[i].active)
  {
  masked_blit(ebullets[i].bbs,dbuffer,0,0,ebullets[i].x,ebullets[i].y,
  EBWIDTH(i),EBHEIGHT(i));
  ebdisplace(i);
  }
 }
}

#endif //_M_EBULL_
