//File Initialisation .

#ifndef _M_FINI_
#define _M_FINI_

#include "decl.h"
#include "files.h"

void iniopen()
{
int i,j;
inifp = fopen(FIni,"r");
if(!inifp)
{
sprintf(logmsg,"Couldn't Read INI file : %s",FIni);logwrite();
ininwrite=1;return;
}
sprintf(logmsg,"Reading INI file : %s",FIni);logwrite();
//Logo .
fscanf(inifp,"%s",FLogo);
//Font .
fscanf(inifp,"%s",FFont);
fscanf(inifp," %d %d %d",&acr,&acg,&acb);
fscanf(inifp," %d %d %d",&pcr,&pcg,&pcb);
//Ship .
fscanf(inifp,"%s",FShip);
fscanf(inifp," %d %d %d %d %d",&SHFRAMES,&PARAM,&MAXLIFE,&MAXLIVES,&MAXPOSLIVES);
//Ship Blink .
fscanf(inifp,"%s",FShipBlink);
fscanf(inifp," %d",&SHBLFRAMES);
//Ship Blank .
fscanf(inifp,"%s",FBlank);
fscanf(inifp," %d",&MAXBLAF);
//Levels
fscanf(inifp," %d",&NUMLEVELS);
for(i=0;i<NUMLEVELS;i++)
{
fscanf(inifp," %d",&rkills[i]);
}
//Bullets .
fscanf(inifp,"%s",FBullets);
fscanf(inifp," %d",&NUMBULLTYPES);
for(i=0;i<NUMBULLTYPES;i++)
{
fscanf(inifp,"%s",bullnames[i]);
ThillaLangadi(bullnames[i],ASPC,SPC);
fscanf(inifp," %d %d %d %d %d %d %d %d %d %lf %lf",&bframes[i],&BMUL[i],&numbullets[i],
&xbspeed[i],&ybspeed[i],&blimit[i],&bdir[i],&dammo[i],&maxammo[i],&dbdamage[i],
&maxbdamage[i]);
}
//Enemy Bullets .
fscanf(inifp,"%s",FEBullets);
fscanf(inifp," %d",&NUMEBULLTYPES);
for(i=0;i<NUMEBULLTYPES;i++)
{
fscanf(inifp," %d %d %d %d %lf",&ebframes[i],&EBMUL[i],&xebspeed[i],&eblimit[i],&ebdamage[i]);
}
//Ammo .
fscanf(inifp,"%s",FCAmmo);
for(i=0;i<NUMBULLTYPES;i++)
{
fscanf(inifp," %d %d %d %d %d",&caframes[i],&cafmul[i],&calife[i],&cgammo[i],&cgascore[i]);
}
//Other Collectibles .
fscanf(inifp,"%s",FCOthers);
fscanf(inifp," %d",&COLNUMS);
for(i=0;i<COLNUMS;i++)
{
fscanf(inifp," %d %d %d %d %d %d",&cgframes[i],&cgfmul[i],&cglife[i],&cglives[i],&cgiscore[i],&cclife[i]);
}
//Enemies .
fscanf(inifp,"%s",FEnemies);
fscanf(inifp," %d",&ENEMYTYPES);
for(i=0;i<ENEMYTYPES;i++)
{
fscanf(inifp," %d %d %d %d %d %d %lf %lf",&enemyframes[i],&FMUL[i],&enemylives[i],
&enemydam[i],&emove[i],&ebtype[i],&enemyxsp[i],&enemyysp[i]);
}
//Enemy map .
for(i=0;i<NUMLEVELS;i++)
 for(j=0;j<ENEMYTYPES;j++)
{
fscanf(inifp," %d",&elmap[i][j]);
}
//Stars .
fscanf(inifp," %d",&NUMSTARS);
//Explosions .
fscanf(inifp,"%s",FExplosions);
fscanf(inifp," %d",&NUMEXPLODE);
//Statistics Icons .
fscanf(inifp,"%s",FIcons);
//Sounds .
fscanf(inifp,"%s",FMusic);
fscanf(inifp,"%s",FMMusic);
fscanf(inifp,"%s",FShoot);
fscanf(inifp,"%s",FEShoot);
fscanf(inifp,"%s",FExplodeSound);
fscanf(inifp,"%s",FExplodeDied);
fscanf(inifp,"%s",FSCollec);
fscanf(inifp,"%s",FSWon);
fscanf(inifp," %d %d %u %u",&plsounds,&plmusic,&DVOL,&MVOL);
//Scores .
fscanf(inifp,"%s",FHsc);
//Statistics .
fscanf(inifp,"%d",&sflag);
//Videos .
fscanf(inifp,"%d",&numvideos);
for(i=0;i<numvideos;i++)
{
fscanf(inifp,"%s %s %d %d",videos[i].filename,videos[i].password,
&videos[i].an,&videos[i].vn);
ThillaLangadi(videos[i].filename,ADEL,DEL);
ThillaLangadi(videos[i].filename,ASPC,SPC);
ThillaLangadi(videos[i].password,ASPC,SPC);
}
//Strings .
for(i=0;i<NUMMENUITEMS;i++)
{
fscanf(inifp,"%s",menu[i]);ThillaLangadi(menu[i],ASPC,SPC);
}
for(i=0;i<NUMOPTMENUITEMS;i++)
{
fscanf(inifp,"%s",omenu[i]);ThillaLangadi(omenu[i],ASPC,SPC);
}
for(i=0;i<STATES;i++)
{
fscanf(inifp,"%s",flaSTR[i]);ThillaLangadi(flaSTR[i],ASPC,SPC);
}
fscanf(inifp,"%s",GOVSTR);ThillaLangadi(GOVSTR,ASPC,SPC);
fscanf(inifp,"%s",PAUSESTR);ThillaLangadi(PAUSESTR,ASPC,SPC);
fscanf(inifp,"%s",QDSTR);ThillaLangadi(QDSTR,ASPC,SPC);
fscanf(inifp,"%s",KEYSTR);ThillaLangadi(KEYSTR,ASPC,SPC);
fscanf(inifp,"%s",INFISTR);ThillaLangadi(INFISTR,ASPC,SPC);
fscanf(inifp,"%s",STRNONE);ThillaLangadi(STRNONE,ASPC,SPC);
fscanf(inifp,"%s",HSCSTRNAME);ThillaLangadi(HSCSTRNAME,ASPC,SPC);
fscanf(inifp,"%s",HSCSTRLEVEL);ThillaLangadi(HSCSTRLEVEL,ASPC,SPC);
fscanf(inifp,"%s",HSCSTRSCORE);ThillaLangadi(HSCSTRSCORE,ASPC,SPC);
fscanf(inifp,"%s",STRCHSCNAME);ThillaLangadi(STRCHSCNAME,ASPC,SPC);
fscanf(inifp,"%s",STRNNONE);ThillaLangadi(STRNNONE,ASPC,SPC);
fscanf(inifp,"%s",UNISTR);ThillaLangadi(UNISTR,ASPC,SPC);
fscanf(inifp,"%s",LEVSTR);ThillaLangadi(LEVSTR,ASPC,SPC);
fscanf(inifp,"%s",WINSTR);ThillaLangadi(WINSTR,ASPC,SPC);
//Others .
fscanf(inifp," %lf %lf %lf",&orparam,&ogparam,&obparam);
fscanf(inifp," %lf %lf %lf",&orsparam,&ogsparam,&obsparam);
fscanf(inifp," %lf %lf %lf",&orgparam,&oggparam,&obgparam);
fscanf(inifp,"%s",inimsg);
sprintf(logmsg,"Read INI file : %s",FIni);logwrite();
fclose(inifp);
normalise();
}

void iniwrite()
{
if(inifp){fprintf(inifp,"%s\n",inimsg);}
}

void iniclose()
{
int i,j;
double r,g,b;
char tbuf[STRB];
if(!ininwrite)
{
sprintf(logmsg,"Needn't Write INI file : %s",FIni);logwrite();
return;
}
inifp = fopen(FIni,"w");
if(!inifp)
{
sprintf(logmsg,"Couldn't Write INI file : %s",FIni);logwrite();
return;
}
sprintf(logmsg,"Writing INI file : %s",FIni);logwrite();
denormalise();
//Logo .
sprintf(inimsg,"%s",FLogo);iniwrite();
//Font .
sprintf(inimsg,"%s",FFont);iniwrite();
sprintf(inimsg,"%d %d %d",acr,acg,acb);iniwrite();
sprintf(inimsg,"%d %d %d",pcr,pcg,pcb);iniwrite();
//Ship .
sprintf(inimsg,"%s",FShip);iniwrite();
sprintf(inimsg,"%d %d %d %d %d",SHFRAMES,PARAM,MAXLIFE,MAXLIVES,MAXPOSLIVES);
iniwrite();
//Ship Blink .
sprintf(inimsg,"%s",FShipBlink);iniwrite();
sprintf(inimsg,"%d",SHBLFRAMES);iniwrite();
//Ship Blank .
sprintf(inimsg,"%s",FBlank);iniwrite();
sprintf(inimsg,"%d",MAXBLAF);iniwrite();
//Levels
sprintf(inimsg,"%d",NUMLEVELS);iniwrite();
for(i=0;i<NUMLEVELS;i++)
{
sprintf(inimsg,"%d",rkills[i]);iniwrite();
}
//Bullets .
sprintf(inimsg,"%s",FBullets);iniwrite();
sprintf(inimsg,"%d",NUMBULLTYPES);iniwrite();
for(i=0;i<NUMBULLTYPES;i++)
{
ThillaLangadi(bullnames[i],SPC,ASPC);
sprintf(inimsg,"%s",bullnames[i]);iniwrite();
sprintf(inimsg,"%d %d %d %d %d %d %d %d %d %f %f",bframes[i],BMUL[i],numbullets[i],
xbspeed[i],ybspeed[i],blimit[i],bdir[i],dammo[i],maxammo[i],dbdamage[i],
maxbdamage[i]);
iniwrite();
}
//Enemy Bullets .
sprintf(inimsg,"%s",FEBullets);iniwrite();
sprintf(inimsg,"%d",NUMEBULLTYPES);iniwrite();
for(i=0;i<NUMEBULLTYPES;i++)
{
sprintf(inimsg,"%d %d %d %d %f",ebframes[i],EBMUL[i],xebspeed[i],eblimit[i],ebdamage[i]);
iniwrite();
}
//Ammo .
sprintf(inimsg,"%s",FCAmmo);iniwrite();
for(i=0;i<NUMBULLTYPES;i++)
{
sprintf(inimsg,"%d %d %d %d %d",caframes[i],cafmul[i],calife[i],cgammo[i],cgascore[i]);iniwrite();
}
//Other Collectibles .
sprintf(inimsg,"%s",FCOthers);iniwrite();
sprintf(inimsg,"%d",COLNUMS);iniwrite();
for(i=0;i<COLNUMS;i++)
{
sprintf(inimsg,"%d %d %d %d %d %d",cgframes[i],cgfmul[i],cglife[i],cglives[i],cgiscore[i],cclife[i]);
iniwrite();
}
//Enemies .
sprintf(inimsg,"%s",FEnemies);iniwrite();
sprintf(inimsg,"%d",ENEMYTYPES);iniwrite();
for(i=0;i<ENEMYTYPES;i++)
{
sprintf(inimsg,"%d %d %d %d %d %d %f %f",enemyframes[i],FMUL[i],enemylives[i],
enemydam[i],emove[i],ebtype[i],enemyxsp[i],enemyysp[i]);
iniwrite();
}
//Enemy map .
for(i=0;i<NUMLEVELS;i++)
{
for(j=0;j<ENEMYTYPES;j++)
{
if(j)
{
sprintf(inimsg,"%s %d",tbuf,elmap[i][j]);
}
else
{
sprintf(inimsg,"%d",elmap[i][j]);
}
sprintf(tbuf,"%s",inimsg);
}
iniwrite();
}
//Stars .
sprintf(inimsg,"%d",NUMSTARS);iniwrite();
//Explosions .
sprintf(inimsg,"%s",FExplosions);iniwrite();
sprintf(inimsg,"%d",NUMEXPLODE);iniwrite();
//Statistics Icons .
sprintf(inimsg,"%s",FIcons);iniwrite();
//Sounds .
sprintf(inimsg,"%s",FMusic);iniwrite();
sprintf(inimsg,"%s",FMMusic);iniwrite();
sprintf(inimsg,"%s",FShoot);iniwrite();
sprintf(inimsg,"%s",FEShoot);iniwrite();
sprintf(inimsg,"%s",FExplodeSound);iniwrite();
sprintf(inimsg,"%s",FExplodeDied);iniwrite();
sprintf(inimsg,"%s",FSCollec);iniwrite();
sprintf(inimsg,"%s",FSWon);iniwrite();
sprintf(inimsg,"%d %d %u %u",plsounds,plmusic,DVOL,MVOL);iniwrite();
//Scores .
sprintf(inimsg,"%s",FHsc);iniwrite();
//Statistics .
sprintf(inimsg,"%d",sflag);iniwrite();
//Videos .
sprintf(inimsg,"%d",numvideos);iniwrite();
for(i=0;i<numvideos;i++)
{
ThillaLangadi(videos[i].filename,DEL,ADEL);
ThillaLangadi(videos[i].filename,SPC,ASPC);
ThillaLangadi(videos[i].password,SPC,ASPC);
sprintf(inimsg,"%s %s %d %d",videos[i].filename,videos[i].password,
videos[i].an,videos[i].vn);
iniwrite();
}
//Strings .
for(i=0;i<NUMMENUITEMS;i++)
{
ThillaLangadi(menu[i],SPC,ASPC);sprintf(inimsg,"%s",menu[i]);iniwrite();
}
for(i=0;i<NUMOPTMENUITEMS;i++)
{
ThillaLangadi(omenu[i],SPC,ASPC);sprintf(inimsg,"%s",omenu[i]);iniwrite();
}
for(i=0;i<STATES;i++)
{
ThillaLangadi(flaSTR[i],SPC,ASPC);sprintf(inimsg,"%s",flaSTR[i]);iniwrite();
}
ThillaLangadi(GOVSTR,SPC,ASPC);sprintf(inimsg,"%s",GOVSTR);iniwrite();
ThillaLangadi(PAUSESTR,SPC,ASPC);sprintf(inimsg,"%s",PAUSESTR);iniwrite();
ThillaLangadi(QDSTR,SPC,ASPC);sprintf(inimsg,"%s",QDSTR);iniwrite();
ThillaLangadi(KEYSTR,SPC,ASPC);sprintf(inimsg,"%s",KEYSTR);iniwrite();
ThillaLangadi(INFISTR,SPC,ASPC);sprintf(inimsg,"%s",INFISTR);iniwrite();
ThillaLangadi(STRNONE,SPC,ASPC);sprintf(inimsg,"%s",STRNONE);iniwrite();
ThillaLangadi(HSCSTRNAME,SPC,ASPC);sprintf(inimsg,"%s",HSCSTRNAME);iniwrite();
ThillaLangadi(HSCSTRLEVEL,SPC,ASPC);sprintf(inimsg,"%s",HSCSTRLEVEL);iniwrite();
ThillaLangadi(HSCSTRSCORE,SPC,ASPC);sprintf(inimsg,"%s",HSCSTRSCORE);iniwrite();
ThillaLangadi(STRCHSCNAME,SPC,ASPC);sprintf(inimsg,"%s",STRCHSCNAME);iniwrite();
ThillaLangadi(STRNNONE,SPC,ASPC);sprintf(inimsg,"%s",STRNNONE);iniwrite();
ThillaLangadi(UNISTR,SPC,ASPC);sprintf(inimsg,"%s",UNISTR);iniwrite();
ThillaLangadi(LEVSTR,SPC,ASPC);sprintf(inimsg,"%s",LEVSTR);iniwrite();
ThillaLangadi(WINSTR,SPC,ASPC);sprintf(inimsg,"%s",WINSTR);iniwrite();
//Others .
r=g=b=-1;
if(orparam>=0) r=rparam;
if(ogparam>=0) g=gparam;
if(obparam>=0) b=bparam;
sprintf(inimsg,"%f %f %f",r,g,b);iniwrite();
r=g=b=-1;
if(orsparam>=0) r=rsparam;
if(ogsparam>=0) g=gsparam;
if(obsparam>=0) b=bsparam;
sprintf(inimsg,"%f %f %f",r,g,b);iniwrite();
r=g=b=-1;
if(orgparam>=0) r=rgparam;
if(oggparam>=0) g=ggparam;
if(obgparam>=0) b=bgparam;
sprintf(inimsg,"%f %f %f",r,g,b);iniwrite();
//Done .
sprintf(inimsg,"%s INI",TITLE);iniwrite();
normalise();
sprintf(logmsg,"Wrote INI file : %s",FIni);logwrite();
fclose(inifp);
}

#endif //_M_FINI
