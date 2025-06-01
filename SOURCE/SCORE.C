//Scores and Bonuses

#ifndef _M_SCOR_
#define _M_SCOR_

#include "decl.h"

void CheckIncrementLife()
{
 if(lives < MAXPOSLIVES)
 {
  if(score > LIFEGIVINGSCORE)
  {
  lives++;
  score=0;
  }
 }
}

void upcolscore(int i)
{
if(colls[i].active)
{
if(colls[i].type==CA)
{
if(colls[i].spec)
{
ammo[colls[i].spec]+=cgammo[colls[i].spec];
}
else 
{
bdamage[colls[i].spec]+=BPI;              //Increase Power Of Bullet !
}
score+=cgascore[colls[i].spec];
}
else if(colls[i].type==CO)                //Others
{
active+=cglife[colls[i].spec];
if(active>MAXLIFE){active=MAXLIFE;}
lives+=cglives[colls[i].spec];
if(lives>MAXPOSLIVES){lives=MAXPOSLIVES;}
score+=cgiscore[colls[i].spec];
}
colls[i].active=0;                        //De-Activate
scored=1;
}
}

void UpdateScore(int type)
{
 score += GENMULT * enemydam[type];
 scored=1;
 if(score > MAXSCORE)
 {
  score=MAXSCORE;
 }
 CheckIncrementLife(); 
} 


#endif //_M_SCOR_

