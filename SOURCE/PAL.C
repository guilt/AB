//Palette .

#ifndef _M_PAL_
#define _M_PAL_

#include "decl.h"

void setrand()
{
 int s;
 s=time(NULL);
 srand(s);
}

void docolorscale(BITMAP *src,int x,int y,int w,int h) //Finally Wrote It !
{
int i=0,j,c,d;
for(;i<h;i++)
{
 for(j=0;j<w;j++)
 {
 c=getpixel(src,j+x,i+y);
 d=(getr(c)+getg(c)+getb(c))/3;
 putpixel(src,j+x,i+y,makecol(d*rparam,d*gparam,d*bparam)); //Color Changing ....
 }
}
}

void gencolorinit()
{
setrand();
rparam=orparam;
if(rparam<0) //0.5 to 1 !!!
rparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
gparam=ogparam;
if(gparam<0)
gparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
bparam=obparam;
if(bparam<0)
bparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
setrand();
rgparam=orgparam;
if(rgparam<0) //0.5 to 1 !!!
rgparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
ggparam=oggparam;
if(ggparam<0)
ggparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
bgparam=obgparam;
if(bgparam<0)
bgparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
}

void starcolinit()
{
setrand();
rsparam=orsparam;
if(rsparam<0) //0.5 to 1 !!!
rsparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
gsparam=ogsparam;
if(gsparam<0)
gsparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
bsparam=obsparam;
if(bsparam<0)
bsparam=((double)((rand()%((DC/2)+1))+(DC/2)))/DC;
for(i=0;i<LAYERS;i++)
{
starcolors[i]=makecol((((stars[i].state+1)*PARAMS)*rsparam),
                      (((stars[i].state+1)*PARAMS)*gsparam),
                      (((stars[i].state+1)*PARAMS)*bsparam));
}
}

void setpal()
{
 pal[0].r=pal[0].g=pal[0].b=0; //Blacken .
 set_palette(pal);
 activecol = makecol(acr,acg,acb);
 passivecol = makecol(pcr,pcg,pcb);
}

void updgovcol()
{
 int param = (abs((long)(gen%(NUM_COLORS*2))-NUM_COLORS));
 govcol=makecol((param*rgparam),(param*ggparam),(param*bgparam));
}

#endif // _M_PAL_

