//Hero's Bullet Routines .

#ifndef _M_BULL_
#define _M_BULL_

#include "decl.h"
#include "collec.c"
#include "collisio.c"
#include "effects.c"
#include "sounds.c"
#include "score.c"

void onetimebullinit()
{
curbul=0;
for(i=0;i<NUMBULLTYPES;i++)
{
bdamage[i]=dbdamage[i];
ammo[i]=dammo[i];
}
}

void bullinit()
{
 for(i=0;i<MAXBULLETS;i++)
 {
  bullets[i].active=0;
  bullets[i].type=0;
 }
}

void clipbullets()
{
int i;
for(i=0;i<NUMBULLTYPES;i++)
{
if(i&&ammo[i]>maxammo[i]){ammo[i]=maxammo[i];}
if(bdamage[i]>maxbdamage[i]){bdamage[i]=maxbdamage[i];}
}
}

//Change Bullets .
void change_bulltype()
{
if(key[KEY_0]||key[KEY_0_PAD]){curbul=9;}
if(key[KEY_9]||key[KEY_9_PAD]){curbul=8;}
if(key[KEY_8]||key[KEY_8_PAD]){curbul=7;}
if(key[KEY_7]||key[KEY_7_PAD]){curbul=6;}
if(key[KEY_6]||key[KEY_6_PAD]){curbul=5;}
if(key[KEY_5]||key[KEY_5_PAD]){curbul=4;}
if(key[KEY_4]||key[KEY_4_PAD]){curbul=3;}
if(key[KEY_3]||key[KEY_3_PAD]){curbul=2;}
if(key[KEY_2]||key[KEY_2_PAD]){curbul=1;}
if(key[KEY_1]||key[KEY_1_PAD]){curbul=0;}
if(key[KEY_Q]){curbul+=NUMBULLTYPES-1;curbul%=NUMBULLTYPES;}
if(key[KEY_W]){curbul++;curbul%=NUMBULLTYPES;}
if(curbul>=MAXBULLTYPES||curbul>=NUMBULLTYPES){curbul=0;} //Clipping .
}

//Set Movements of Bullets .
void setbspec(int i)
{
    setrand();
    bullets[i].spec1=bdir[bullets[i].type]; //Type and Direction
    if(bullets[i].spec1)
    {
    bullets[i].spec2=((gen%(SPEC2*blimit[bullets[i].type]))/blimit[bullets[i].type]);
    }
}

//Funky Bullets Movements !
void displace(int i)
{
  if(bullets[i].spec1==H)             //Horizontal
  {
  bullets[i].x+=xbspeed[bullets[i].type];
  }
  else if(bullets[i].spec1==V)        //V-Shaped
  {
   bullets[i].x+=xbspeed[bullets[i].type];
   if(bullets[i].spec2==D)
   {
   bullets[i].y+=ybspeed[bullets[i].type];
   }
   else if(bullets[i].spec2==U)
   {
   bullets[i].y-=ybspeed[bullets[i].type];
   }
  }     
  else if(bullets[i].spec1==Y)        //Vertical
  {
   if(bullets[i].spec2==D)
   {
   bullets[i].y+=ybspeed[bullets[i].type];
   }
   else if(bullets[i].spec2==U)
   {
   bullets[i].y-=ybspeed[bullets[i].type];
   }   
  }
  else if(bullets[i].spec1==J)        //Jagged
  {
   bullets[i].x+=xbspeed[bullets[i].type]; 
   if(bullets[i].spec2==D)
   {
   bullets[i].y+=(nofg()*ybspeed[bullets[i].type]);
   }
   else if(bullets[i].spec2==U)
   {
   bullets[i].y-=(nofg()*ybspeed[bullets[i].type]);
   }   
   }
}

void genbullet()
{
 for(i=0;i<numbullets[curbul];i++)
 {
  if(bullets[i].active==0&&!((gen+1)%blimit[bullets[i].type])) 
  { 
   if((!bullets[i].type)||(bullets[i].type && ammo[bullets[i].type]))
   {
    if(bullets[i].type) 
    {
     ammo[bullets[i].type]--;
     if(ammo[bullets[i].type]<0)
     {ammo[bullets[i].type]=0;bullets[i].type=0;curbul=0;}
    }
    bullets[i].y=(shipy+(HHEIGHT/2));bullets[i].x=shipx+HWIDTH;
    bullets[i].type=0;
    if(ammo[curbul])
    bullets[i].type=curbul;
    else
    curbul=0;
    bullets[i].active=1;
    setbspec(i);
    setrand();
    bullets[i].bbs=bullbs[bullets[i].type]
    [((gen+rand()%(bframes[bullets[i].type]*BMUL[bullets[i].type]))/BMUL[bullets[i].type])];         
    sndshoot();
    break;
   }
  }
 }
}

void updatebullets()
{
 for(i=0;i<numbullets[curbul];i++)
 {
  if(bullets[i].active)
  { 
   bullets[i].bbs=bullbs[bullets[i].type]
   [((gen%(bframes[bullets[i].type]*BMUL[bullets[i].type]))/BMUL[bullets[i].type])];         
   if(!collide(bullets[i].x,bullets[i].y,BWIDTH(i),BHEIGHT(i),getminx(),getminy(),getmaxx(),getmaxy()))
   {
    bullets[i].active=0;
   }
  }
}
clipbullets();
if(!ammo[curbul])
{ 
curbul=0;
}
}

void updatebulletsandenemies()
{
for(i=0;i<numbullets[curbul];i++)
{
 if(bullets[i].active)
 {
  for(j=0;j<NUMENEMIES;j++)
  {
  if(enemies[j].active)
   {
    if(collide(bullets[i].x,bullets[i].y,BWIDTH(i),BHEIGHT(i),
    enemies[j].x,enemies[j].y,EWIDTH(j),EHEIGHT(j))) //Enemy is Dying !
    {
     bullets[i].active = 0;
     enemies[j].active-= bdamage[bullets[i].type];
     if(enemies[j].active <= 0)
     {
     kills+=enemylives[enemies[i].type]; //Hopefully works
     enemies[j].active=0;enemies[j].explframe=0;
     UpdateScore(enemies[j].type); //Score and Generate Collectible as Well !
     genecollec(enemies[j].type,enemies[j].x+(EWIDTH(j)/2),enemies[j].y+(EHEIGHT(j)/2));
     }  
    }
   }
  }
 }
}
}  
  
void drawbullets()
{
for(i=0;i<numbullets[curbul];i++)
 {
  if(bullets[i].active)
  {
  masked_blit(bullets[i].bbs,dbuffer,0,0,bullets[i].x,bullets[i].y,BWIDTH(i),BHEIGHT(i));
   displace(i);
 }
 }
}

#endif //_M_BULL_
