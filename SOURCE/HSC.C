//High Scores Loop

#ifndef _M_HSC_
#define _M_HSC_

#include "decl.h"
#include "fhsc.c"

//High Scores Loop .
void hscloop()
{
 int u;
 if(NUMHSC<=0){return;}
 dosorthsc();
 clear_keybuf();
 while(1)
 {
  cls();
  updatestarfield();
  drawstarfield();
  masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
  sprintf(buff,"%s",menu[HSCMNO]); //As of Now .
  alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET-(FSIZE+VERTSPC),
  activecol);
  sprintf(buff,HSCSTRNAME);
  alfont_textout_aa(dbuffer,alfy,buff,HSCNX,YMENUOFFSET,activecol);
  sprintf(buff,HSCSTRLEVEL);
  alfont_textout_centre_aa(dbuffer,alfy,buff,HSCLX,YMENUOFFSET,activecol);
  sprintf(buff,HSCSTRSCORE);
  alfont_textout_aa(dbuffer,alfy,buff,HSCSX,YMENUOFFSET,activecol);
  for(u=NUMHSC-1;u>=0;u--)
  {
  sprintf(buff,"%s",Players[u].name);
  alfont_textout_aa(dbuffer,alfy,buff,HSCNX,YMENUOFFSET+((u+1)*(FSIZE+VERTSPC)),passivecol);
  sprintf(buff,"%u",Players[u].level);
  alfont_textout_aa(dbuffer,alfy,buff,HSCLX,YMENUOFFSET+((u+1)*(FSIZE+VERTSPC)),passivecol);
  sprintf(buff,SCOFORMAT,Players[u].score);
  alfont_textout_aa(dbuffer,alfy,buff,HSCSX,YMENUOFFSET+((u+1)*(FSIZE+VERTSPC)),passivecol);
  //As of Now .
  }
  if(keypressed())
  {
  doshandle();
  evshandle();
  if(key[KEY_ESC]){break;}
  }
  render();
  }
  clear_keybuf();
}

//Enter HighScores here :
void enterhsc()
{
 char name[NAMELEN+1]={""},c=0,done=0;
 int i,len=0;
 rest(GST);
 if(!determine(level,lives,score,active))return;
 strcpy(buff,STRNNONE); //Initialize .
 strcpy(name,STRNNONE);
 for(;buff[len];len++);
 while(1)
 {
  cls();
  updatestarfield();
  drawstarfield();
  masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
  sprintf(buff,STRCHSCNAME);
  alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET-(FSIZE+VERTSPC),
  activecol);
  for(i=0;i<len;i++)
  {
  buff[i]=name[i];
  }
  buff[i]=0;
  alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET,passivecol);
  //As of Now .
  if(keypressed())
  {
  doshandle(); //Allow only Shots .
  if(done&&c==END)
  {
  break;
  }
  if(done&&!*name)
  {
  break;
  }
  c=END;c=strgetch();
  if(!done&&c==END)
  {
  name[len]=name[NAMELEN]=0;done=1;
  }
  else if(!done&&c==BSP) {if(len>0)len--;}
  else if(!done&&len<NAMELEN)
  {
  if(c!=END&&c!=BSP)
  name[len++]=c;
  }
  clear_keybuf();
  }
  render();
  }
  clear_keybuf();
  if(!*name){strcpy(name,STRNNONE);}
  addscore(name);
  hscloop();
}

#endif //_M_HSC_

