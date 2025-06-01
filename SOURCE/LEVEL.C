//High Scores Loop

#ifndef _M_LEV_
#define _M_LEV_

#include "decl.h"
#include "fhsc.c"
#include "fhsc.c"

//Display Msg .
void levdone()
{
clear_keybuf();
alfont_textout_centre(dbuffer,alfy,LEVSTR,getmidx(),getmidy()-FSIZE,activecol);
render();
while(1)
{
if(keypressed()){doshandle();if(keypressed()){break;}}
}
clear_keybuf();
rest(GST);
stopmusic();
}

//High Scores Loop .
int levincrement()
{
if(level<(NUMLEVELS-1)){level++;levdone();return 1;}
if(level==(NUMLEVELS-1)){win=1;done=1;}
return 0;
}

#endif //_M_LEV_

