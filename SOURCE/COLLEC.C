//Collectibles .

#ifndef _M_COLLEC_
#define _M_COLLEC_

#include "decl.h"
#include "effects.c"
#include "collisio.c"
#include "score.c"

void gencollec(int x,int y)
{
int i,j,done=0;
setrand(); //Generate Items at Random !
for(i=0;i<MAXCOLLEC&&!done;i++)
{
if(!colls[i].active)
{
colls[i].x=x,colls[i].y=y;
colls[i].type=(rand()%COLTYPES);
if(colls[i].type==CA) //Ammo
{
colls[i].spec=(rand()%NUMBULLTYPES);
colls[i].active=calife[colls[i].spec];
colls[i].cbs=bammobs[colls[i].spec]
[((gen%(caframes[colls[i].spec]*cafmul[colls[i].spec]))/cafmul[colls[i].spec])];
}
else if(colls[i].type==CO) //Others
{
colls[i].spec=(rand()%COLNUMS);
colls[i].active=cclife[colls[i].spec];
colls[i].cbs=colbs[colls[i].spec]
[((gen%(cgframes[colls[i].spec]*cgfmul[colls[i].spec]))/cgfmul[colls[i].spec])];
}
done=1;
for(j=0;j<MAXCOLLEC;j++)
{
if(j!=i&&colls[j].active&&collide(colls[i].x,colls[i].y,CWIDTH(i),CHEIGHT(i),colls[j].x,colls[j].y,CWIDTH(j),CHEIGHT(j)))
{
colls[i].active=0; //Deactivate for two collectibles on same spot .
done=0;
}
}
if(collide(colls[i].x,colls[i].y,CWIDTH(i),CHEIGHT(i),shipx,shipy,HWIDTH,HHEIGHT))
{
colls[i].active=0; //Deactivate for collectible and hero on same spot .
done=0;
}
}
}
}

void genecollec(int i,int x,int y)
{
if(((gen%CPARAM1)+enemylives[i])>CPARAM2){gencollec(x,y);}
}

//Some Collectibles can't be reached for : To Frustrate !
void updatecollec()
{
int i;
if(((gen%CPARAM1)+(rand()%CPARAM1))>CPARAM3){setrand();gencollec((rand()%XRES),(rand()%YRES));}
for(i=0;i<MAXCOLLEC;i++)
{
if(colls[i].active)
{
//No checking for Collision of Animated Collectibles - it's done only during generation .
if(colls[i].type==CA) //Ammo
{
colls[i].cbs=bammobs[colls[i].spec]
[((gen%(caframes[colls[i].spec]*cafmul[colls[i].spec]))/cafmul[colls[i].spec])];
}
else if(colls[i].type==CO) //Others
{
colls[i].cbs=colbs[colls[i].spec]
[((gen%(cgframes[colls[i].spec]*cgfmul[colls[i].spec]))/cgfmul[colls[i].spec])];
}
if(!collide(colls[i].x,colls[i].y,CWIDTH(i),CHEIGHT(i),getminx(),
   getminy(),getmaxx(),getmaxy()))
{
colls[i].active=0;
}
else if(collide(colls[i].x,colls[i].y,CWIDTH(i),CHEIGHT(i),shipx,shipy,HWIDTH,HHEIGHT))
{
sndcollec();
upcolscore(i);
}
}
colls[i].active--;
if(colls[i].active<0){colls[i].active=0;}
}
}

void drawcollec()
{
for(i=0;i<MAXCOLLEC;i++)
{
if(colls[i].active)
{
masked_blit(colls[i].cbs,dbuffer,0,0,colls[i].x,colls[i].y,CWIDTH(i),CHEIGHT(i));
}
}
}

#endif //_M_COLLEC_

