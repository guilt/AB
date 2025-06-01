//Credits Loop

#ifndef _M_CRED_
#define _M_CRED_

#include "decl.h"

//Credits Loop
void credloop()
{

 int i=0,j,ddone;
 int calcx,calcy;
 double usedx;
 int credgrayval,credcol;
 
 clear_keybuf();

 while(1)
 {
  cls();
  updatestarfield();
  drawstarfield();
  masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
  sprintf(buff,"%s",menu[CREDMNO]); //As of Now .
  alfont_textout_centre(dbuffer,alfy,buff,getmidx(),YMENUOFFSET-(FSIZE+VERTSPC),
  activecol);

  if(i<=NTIMES) i++;
  else i=0;
    
  ddone=0;  
  usedx=sintable[i%ETABNUM]*CRMUL;
  for(j=0;j<NLINES&&!ddone;j++)
  {
  credgrayval=(rand()%((MAXCVAL/2)+1))+(MAXCVAL/2);
  credcol=makecol(credgrayval,credgrayval,credgrayval);
  calcy=getmidy()-(i*MSPEED)+(j*(FSIZE+SSPC));
  calcx=(int)usedx;
  if(calcy>=getminy()&&calcy<=getmaxy())
  {
  sprintf(buff,"%s",names[j]); //As of Now .
  alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx()-calcx,YMENUOFFSET-(VERTSPC)+calcy, credcol);
  usedx+=sintable[(j+i)%ETABNUM]*CRMUL;
  }
  else if(calcy>getmaxy())
  {
  ddone=1;
  }
  }
  
  //Till Here
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

#endif //_M_CRED_

