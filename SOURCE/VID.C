//Video Player .

#ifndef _M_VID_
#define _M_VID_

#include "decl.h"
#include "files.h"

//Custom Renderer.
void myrender()
{
vidw=(XRES>(fli_bitmap->w))?(fli_bitmap->w):(XRES);
vidx=(XRES>(fli_bitmap->w))?((XRES-(fli_bitmap->w))/2):0;
vidh=(YRES>(fli_bitmap->h))?(fli_bitmap->h):(YRES);
vidy=(YRES>(fli_bitmap->h))?((YRES-(fli_bitmap->h))/2):0;
blit(dbuffer,screen,0,0,vidx,vidy,vidw,vidh);
}

//Custom Cleanup.
void mycleanup()
{
cls();
clear_keybuf();
}

//Callback.
int interruptcall()
{
myrender();
return keypressed(); 
}

//Player
void playvideo(struct video v)
{
dataf=NULL;
packfile_password(v.password);
lociconvert(v.filename);
dataf=load_datafile(v.filename);
if(!dataf)
{sprintf(logmsg,"Couldn't Process Video file : %s",v.filename);logwrite();return;}
sprintf(logmsg,"Processing Video file : %s",v.filename);logwrite();
if(vidsample)ssndvideo();
vidsample=(SAMPLE *)dataf[v.an].dat;
flidata=dataf[v.vn].dat;
reset_fli_variables();
if(vidsample)
{
sndvideo();
}
if(flidata)
{
mycleanup();
play_memory_fli(flidata,dbuffer,VNOLOOP,interruptcall);
}
rest(VIDDT);
if(vidsample)ssndvideo();
if(!serr)
unload_datafile(dataf);
mycleanup();
}

//Safe Player .
void docinema(int index)
{
if(numvideos<=0)return;
if(index>=numvideos) return;
playvideo(videos[index]);
}

#endif //_M_VID_
