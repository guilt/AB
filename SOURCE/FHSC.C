//High Scores Algos

#ifndef _M_FHSC_
#define _M_FHSC_

#include "decl.h"
#include "pal.c"

void hscwrite()
{
if(hscfp){fprintf(hscfp,"%s\n",hscmsg);}
}

//Needed for Fixing Stuff .
void initrandhsc()
{
if(NUMHSC<=0)return;
setrand();
for(i=0;i<NUMHSC;i++)
{
 Players[i].win=(rand()%2);
 Players[i].level=(NUMLEVELS-1);
 if(!Players[i].win)
 {
 Players[i].level=(rand()%NUMLEVELS);
 }
 Players[i].lives=(rand()%MAXPOSLIVES);
 Players[i].score=(rand()%LIFEGIVINGSCORE);Players[i].score/=GENMULT;Players[i].score*=GENMULT;
 Players[i].life=((rand()%MAXLIFE)+1);
}
}

//Bubble-Sorting Loop : Done ,Thanks to Nikhil .
void dosorthsc()
{
int i,j;
if(NUMHSC<=0)return;
for(i=0;i<NUMHSC-1;i++)
 for(j=i+1;j<NUMHSC;j++)
  if
  (

  (Players[i].win<Players[j].win)

  ||
  
  (
  Players[i].win==Players[j].win&&
  Players[i].level<Players[j].level
  )

  ||

  (
  Players[i].win==Players[j].win&&
  Players[i].level==Players[j].level&&
  Players[i].lives<Players[j].lives
  )

  ||

  (
  Players[i].win==Players[j].win&&
  Players[i].level==Players[j].level&&
  Players[i].lives==Players[j].lives&&
  Players[i].score<Players[j].score
  )

  ||

  (
  Players[i].win==Players[j].win&&
  Players[i].level==Players[j].level&&
  Players[i].lives==Players[j].lives&&
  Players[i].score==Players[j].score&&
  Players[i].life<Players[j].life
  )

  ||

  (
  Players[i].win==Players[j].win&&
  Players[i].level==Players[j].level&&
  Players[i].lives==Players[j].lives&&
  Players[i].score==Players[j].score&&
  Players[i].life<Players[j].life
  )

  ||

  (
  Players[i].win==Players[j].win&&
  Players[i].level==Players[j].level&&
  Players[i].lives==Players[j].lives&&
  Players[i].score==Players[j].score&&
  Players[i].life==Players[j].life&&
  strcmp(Players[i].name,Players[j].name)>0
  )

  )

  {
  temp=Players[i];
  Players[i]=Players[j];
  Players[j]=temp;
  }
}

void readhsc()
{
 int i=0;
 hscfp = fopen(FHsc,"r");
 if(!hscfp)
 {
  sprintf(logmsg,"Couldn't Read Scores file : %s",FHsc);logwrite();
  hscnwrite=1;return;
 }
sprintf(logmsg,"Reading Scores file : %s",FHsc);logwrite();
fscanf(hscfp," %d",&NUMHSC);
if(NUMHSC<0){NUMHSC=0;}if(NUMHSC>MAXHSC){NUMHSC=MAXHSC;}
for(;i<NUMHSC;i++)
 {
  fscanf(hscfp,"%s",Players[i].name);ThillaLangadi(Players[i].name,ASPC,SPC);
  fscanf(hscfp," %d %d %d %d %d",&Players[i].win,&Players[i].level,&Players[i].lives,
  &Players[i].score,&Players[i].life);
  Players[i].name[NAMELEN]=0;
 }
 fclose(hscfp);
sprintf(logmsg,"Read Scores file : %s",FHsc);logwrite();
dosorthsc();
}

int determine(unsigned int level,unsigned int lives,unsigned int score,unsigned int life)
{
int i,flag=0;
if(NUMHSC<=0){NUMHSC=0;flag=1;}
if(NUMHSC<MAXHSC){flag=1;}
for(i=0;i<NUMHSC;i++)
{
  if
  (

  (Players[i].win<win)
  
  ||
  
  (
  Players[i].win==win&&
  Players[i].level<level
  )

  ||

  (
  Players[i].win==win&&
  Players[i].level==level&&
  Players[i].lives<lives
  )

  ||

  (
  Players[i].win==win&&
  Players[i].level==level&&
  Players[i].lives==lives&&
  Players[i].score<score
  )

  ||

  (
  Players[i].win==win&&
  Players[i].level==level&&
  Players[i].lives==lives&&
  Players[i].score==score&&
  Players[i].life<=life
  )

  )

  {
   flag=1;break;
  }

}
if(!scored){flag=0;}
return flag;
}

void addscore(char name[])
{
if(NUMHSC<0)return;
if(NUMHSC<=MAXHSC)
{
name[NAMELEN]=0;
strcpy(Players[NUMHSC].name,name);
Players[NUMHSC].win=win;
Players[NUMHSC].level=level;
Players[NUMHSC].lives=lives;
Players[NUMHSC].score=score;
Players[NUMHSC].life=0;
if(active>0)
Players[NUMHSC].life=active;
NUMHSC++;hscnwrite=1;
}
dosorthsc();
if(NUMHSC>MAXHSC)
{
NUMHSC=MAXHSC; //Truncated !
}
}

void writehsc()
{
 int i=0;
 if(!hscnwrite||!NUMHSC)
 {
  sprintf(logmsg,"Needn't Write Scores file : %s",FHsc);logwrite();
  return;
  }
 hscfp = fopen(FHsc,"w");
 if(!hscfp)
 {
  sprintf(logmsg,"Couldn't Write Scores file : %s",FHsc);logwrite();
  return;
 }
 sprintf(logmsg,"Writing Scores file : %s",FHsc);logwrite();
 sprintf(hscmsg,"%d",NUMHSC);hscwrite();
 for(;i<NUMHSC;i++)
 {
 Players[i].name[NAMELEN]=0;
 ThillaLangadi(Players[i].name,SPC,ASPC);
 sprintf(hscmsg,"%s %d %d %d %d %d",Players[i].name,Players[i].win,
 Players[i].level,Players[i].lives,
 Players[i].score,Players[i].life);
 hscwrite();
 }
 sprintf(logmsg,"Wrote Scores file : %s",FHsc);logwrite();
 fclose(hscfp);
}

#endif //_M_FHSC_

