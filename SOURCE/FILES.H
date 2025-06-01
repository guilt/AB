//File Names Header .

#ifndef _M_FILES_
#define _M_FILES_

#include "sysdefs.h"

//Files .
char CFGFILE[STRB]={"data\\global\\allegro.cfg"};
char FIni[STRB]={"data\\default.ini"};
char FLog[STRB]={"gamelog.txt"};
char FHsc[STRB]={"data\\global\\hscores.txt"};
char FLogo[STRB]={"data\\global\\logo.bmp"};
char FFont[STRB]={"data\\global\\font.ttf"};
char FShip[STRB]={"data\\hero\\ship%02d.bmp"};
char FShipBlink[STRB]={"data\\hero\\shipb%02d.bmp"};
char FBlank[STRB]={"data\\hero\\shblank.bmp"};
char FBullets[STRB]={"data\\bullets\\bull%02d%02d.bmp"};
char FEBullets[STRB]={"data\\ebullets\\ebul%02d%02d.bmp"};
char FCAmmo[STRB]={"data\\collec\\ammo\\am%02d%02d.bmp"};
char FCOthers[STRB]={"data\\collec\\others\\col%02d%02d.bmp"};
char FEnemies[STRB]={"data\\enemies\\enem%02d%02d.bmp"};
char FExplosions[STRB]={"data\\explode\\explo%02d.bmp"};
char FIcons[STRB]={"data\\stat\\icon%02d.bmp"};
char FMusic[STRB]={"data\\music\\music%02d.mus"};
char FMMusic[STRB]={"data\\music\\mmusic.mus"};
char FSCollec[STRB]={"data\\sfx\\scollec.wav"};
char FSWon[STRB]={"data\\sfx\\won.wav"};
char FShoot[STRB]={"data\\sfx\\shoot%02d.wav"};
char FEShoot[STRB]={"data\\sfx\\eshoot%02d.wav"};
char FExplodeSound[STRB]={"data\\sfx\\explode.wav"};
char FExplodeDied[STRB]={"data\\sfx\\gexplode.wav"};
char FShot[STRB]={"scr%05d.pcx"};

void ThillaLangadi(char str[], char whosout, char whosin)
{
 int i=0;
 for(;str[i];i++){if(str[i]==whosout){str[i]=whosin;}}
}

void lociconvert(char str[])
{
 ThillaLangadi(str,ADEL,DEL); ThillaLangadi(str,ASPC,SPC);
}

void alociconvert(char str[])
{
 ThillaLangadi(str,DEL,ADEL); ThillaLangadi(str,SPC,ASPC);
}

int fexist(char filename[]) //Bad Routine to Do a File Check ....
{
int oflag=0;
FILE *fp;fp=fopen(filename,"rb");
if(fp){fclose(fp);oflag=1;}  //Pretty Slow ,but less painful than stat .
return oflag;
}

void normalise()
{
lociconvert(CFGFILE);
lociconvert(FIni);
lociconvert(FLog);
lociconvert(FHsc);
lociconvert(FLogo);
lociconvert(FFont);
lociconvert(FShip);
lociconvert(FShipBlink);
lociconvert(FBlank);
lociconvert(FBullets);
lociconvert(FEBullets);
lociconvert(FCAmmo);
lociconvert(FCOthers);
lociconvert(FEnemies);
lociconvert(FExplosions);
lociconvert(FIcons);
lociconvert(FMusic);
lociconvert(FMMusic);
lociconvert(FSCollec);
lociconvert(FSWon);
lociconvert(FShoot);
lociconvert(FEShoot);
lociconvert(FExplodeSound);
lociconvert(FExplodeDied);
lociconvert(FShot);
}

void denormalise()
{
alociconvert(CFGFILE);
alociconvert(FIni);
alociconvert(FLog);
alociconvert(FHsc);
alociconvert(FLogo);
alociconvert(FFont);
alociconvert(FShip);
alociconvert(FShipBlink);
alociconvert(FBlank);
alociconvert(FBullets);
alociconvert(FEBullets);
alociconvert(FCAmmo);
alociconvert(FCOthers);
alociconvert(FEnemies);
alociconvert(FExplosions);
alociconvert(FIcons);
alociconvert(FMusic);
alociconvert(FMMusic);
alociconvert(FSCollec);
alociconvert(FSWon);
alociconvert(FShoot);
alociconvert(FEShoot);
alociconvert(FExplodeSound);
alociconvert(FExplodeDied);
alociconvert(FShot);
}

#endif //_M_FILES_
