// Enemy Handlers

#include "decl.h"
#include "effects.c"
#include "collisio.c"
#include "ebullets.c"

void enemyinit()
{
 for(i=0;i<NUMENEMIES;i++)
 {
  enemies[i].espec=0;
  enemies[i].active = 0;
  enemies[i].explframe=-1;
 }
 setrand();
}

void genenemies()
{
 setrand();
 for(i=0;i<NUMENEMIES;i++)
 {
   enemies[i].type = rand() % ENEMYTYPES;
   enemies[i].active = enemylives[enemies[i].type];
   enemies[i].enemymot=EH;
   enemies[i].espec=(rand()%ETABNUM);
   if(emove[enemies[i].type]){enemies[i].enemymot=((rand()+gen)%EMTYPES);}
   enemies[i].enemybs = enemyanims[enemies[i].type]
   [(unsigned)(gen%(FMUL[enemies[i].type]*enemyframes[enemies[i].type])
   /FMUL[enemies[i].type])];
   enemies[i].x = XRES + (rand() % ENEMYXLIMIT);
   enemies[i].y = rand() % (YRES-1-EHEIGHT(i));
   enemies[i].explframe=-1;
   for(j=0;j<i;j++)
   {
    if(enemies[j].active && collide(enemies[i].x,enemies[i].y,EWIDTH(i),EHEIGHT(i),
       enemies[j].x,enemies[j].y,EWIDTH(j),EHEIGHT(j)))
     {
     enemies[j].active=0;      
   }
   if(!elmap[level][enemies[j].type]&&enemies[j].active)enemies[j].active=0;
  }
 }
}

void hdisplace(int i)
{
enemies[i].x -= enemyxsp[enemies[i].type];
}

void edisplace(int i)
{
if(enemies[i].enemymot==EH)
{
hdisplace(i);
}
if(enemies[i].enemymot==EL)
{
hdisplace(i);
enemies[i].x -= (enemyxsp[enemies[i].type]*costable[(gen+enemies[i].espec)%ETABNUM]);
enemies[i].y-=  (sintable[(gen+enemies[i].espec)%ETABNUM]*enemyysp[enemies[i].type]);
}
if(enemies[i].enemymot==ES)
{
hdisplace(i);
enemies[i].y-=(sintable[(gen+enemies[i].espec)%ETABNUM]*enemyysp[enemies[i].type]);
}
}

void updateenemies()
{
 int num=0;
 for(i=0;i<NUMENEMIES;i++)
 {
  enemies[i].enemybs = enemyanims[enemies[i].type]
  [(gen%(FMUL[enemies[i].type]*enemyframes[enemies[i].type])/FMUL[enemies[i].type])];
  if(enemies[i].active)
  {
  edisplace(i);
  }
  else
  {
  num++;
  if(enemies[i].explframe>=0 && enemies[i].explframe <(MUL*NUMEXPLODE))
  {
  hdisplace(i);
  }
  }
  if( enemies[i].x < 0 )
  {
   enemies[i].active=0;
   enemies[i].explframe=-1;
  }
 }
 if(num==NUMENEMIES)
 {
  genenemies();
 }
 for(i=0;i<NUMENEMIES;i++)
 {
 if(enemies[i].active)
 {
 genebullet(i);
 }
 }
}

void drawenemies()
{
int i;
 for(i=0;i<NUMENEMIES;i++)
 {
  if(enemies[i].active)
  {
  masked_blit(enemies[i].enemybs,dbuffer,0,0,enemies[i].x,enemies[i].y,enemies[i].enemybs->w,enemies[i].enemybs->h);
  }
  else
  {
  CheckExplode(i); 
  } 
 }
}

