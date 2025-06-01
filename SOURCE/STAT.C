//Statistics .

#ifndef _M_STAT_
#define _M_STAT_

#include "decl.h"

#define chstat() {sflag=(1-sflag);ininwrite=1;}

void drawstat()
{
 int i;
 if(sflag)
 {
 masked_blit(icons[MEDI],dbuffer,0,0,MEDIX,MEDIY,IWIDTH(MEDI),IHEIGHT(MEDI));
 masked_blit(icons[SCO],dbuffer,0,0,SCOX,SCOY,IWIDTH(SCO),IHEIGHT(SCO));
 masked_blit(icons[LEV],dbuffer,0,0,LEVX,LEVY,IWIDTH(LEV),IHEIGHT(LEV));
 for(i=0;i<lives;i++)
 {
 masked_blit(icons[LIF],dbuffer,0,0,LIFX+(i*IWIDTH(LIF)),LIFY,IWIDTH(LIF),IHEIGHT(LIF));
 }
 if(active>0){sprintf(buff,"%3u",active);}else{sprintf(buff,"%s",STRNONE);}
 alfont_textout(dbuffer,alfy,buff,(IWIDTH(MEDI)+MEDIX+HORIZSPC),MEDIY,activecol);
 sprintf(buff,SCOFORMAT,score);
 alfont_textout(dbuffer,alfy,buff,(IWIDTH(SCO)+SCOX+HORIZSPC),SCOY,activecol);
 sprintf(buff,"%u",level);
 alfont_textout(dbuffer,alfy,buff,(IWIDTH(LEV)+LEVX+HORIZSPC),LEVY,activecol);
 if(!curbul) sprintf(buff,"%s (%s)",bullnames[curbul],INFISTR);
 else sprintf(buff,"%s (%3d)",bullnames[curbul],ammo[curbul]);
 alfont_textout(dbuffer,alfy,buff,AMMOX,AMMOY,activecol);
 }
}

#endif //_M_STAT_
