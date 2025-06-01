//UnImplemented Loop

#ifndef _M_UDF_
#define _M_UDF_

#include "decl.h"

//Unimplemented Loop .
void udfloop()
{
 clear_keybuf();
 while(1)
 {
  cls();
  updatestarfield();
  drawstarfield();
  masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
  sprintf(buff,"%s",UNISTR); //As of Now .
  alfont_textout_centre_aa(dbuffer,alfy,buff,getmidx(),YMENUOFFSET-(FSIZE+VERTSPC),
  activecol);
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

#endif //_M_UDF_

