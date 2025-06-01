//Loading and Unloading .

#include "decl.h"
#include "files.h"
#include "flog.c"
#include "fhsc.c"
#include "fini.c"

#ifdef DUMB
void destroy_mod(MUSIC *duh)
{
unload_duh(duh);
}

MUSIC* load_mod(char filename[])
{
MUSIC *duh;
if(!(duh=dumb_load_s3m(filename)))
  if(!(duh=dumb_load_it(filename)))
    if(!(duh=dumb_load_xm(filename)))
	  if(!(duh=dumb_load_mod(filename)))
	    #ifdef DUMBOGG
	    if(!(duh=dumb_load_ogg(filename,DUMBOGGLP)))
        #endif //DUMBOGG
	     return NULL;
return duh;
}
#endif //DUMB

//Release Stuff.
void unload()
{
 sprintf(logmsg,"Unloading : ");logwrite();
 //Scores .
 writehsc();
 //Sounds .
 if(!serr)
 {
  destroy_sample(won);
  destroy_sample(scollec);
  destroy_sample(died);
  destroy_sample(burst);
  for(i=0;i<NUMEBULLTYPES;i++)
  {
  destroy_sample(eshoot[i]);
  }
  for(i=0;i<NUMBULLTYPES;i++)
  {
  destroy_sample(shoot[i]);
  }
  destroy_mod(mmusic);
  for(i=0;i<NUMLEVELS;i++)
  {
  destroy_mod(music[i]);
  }
 }
 //Statistics Icons .
 for(i=0;i<NUMICONS;i++)
 {
  destroy_bitmap(icons[i]);
 }
 //Explosions .
 for(i=0;i<NUMEXPLODE;i++)
 {
  destroy_bitmap(explodeframe[i]);
 }
 //Enemies .
 for(i=0;i<ENEMYTYPES;i++)
 {
  for(j=0;j<enemyframes[i];j++)
  {
   destroy_bitmap(enemyanims[i][j]);
  }
 }
 //Other Collectibles .
 for(i=0;i<COLTYPES;i++)
 {
 for(j=0;j<cgframes[i];j++)
 { 
  destroy_bitmap(colbs[i][j]);
 }
 }
 //Ammo .
 for(i=0;i<NUMBULLTYPES;i++)
 {
 for(j=0;j<caframes[i];j++)
 { 
  destroy_bitmap(bammobs[i][j]);
 }
 }
 //Enemy Bullets .
 for(i=0;i<NUMEBULLTYPES;i++)
 { 
 for(j=0;j<ebframes[i];j++)
 {
  destroy_bitmap(ebullbs[i][j]);
 }
 }  
 //Bullets .
 for(i=0;i<NUMBULLTYPES;i++)
 { 
 for(j=0;j<bframes[i];j++)
 {
  destroy_bitmap(bullbs[i][j]);
 }
 }
 //Ship Blank .
 destroy_bitmap(shipblank);
 //Ship Blink .
 for(i=0;i<SHBLFRAMES;i++)
 {
  destroy_bitmap(shipbl[i]);
 }
 //Ship .
 for(i=0;i<SHFRAMES;i++)
 {
  destroy_bitmap(shipbs[i]);
 }
 //Font .
 alfont_destroy_font(alfy);
 //Logo .
 destroy_bitmap(logo);
 //DBuffer .
 destroy_bitmap(dbuffer);
 sprintf(logmsg,"Unloading Done !");logwrite();
}

void writestatus(void *val,char *msg)
{
if(val)
{
sprintf(logmsg,"%s : OK",msg);
logwrite();
}
else
{
sprintf(logmsg,"Error in processing : %s",msg);
logwrite();unload();iniclose();logclose();alfont_exit();
music_exit();allegro_exit();exit(E_ERR);
}
}

//Load Stuff.
void load()
{
 int i;
 char fname[STRB];
 sprintf(logmsg,"Loading : ");logwrite();
 //DBuffer .
 dbuffer = create_bitmap(XRES,YRES);writestatus(dbuffer,"Double Buffer");
 //Logo .
 logo = load_bitmap(FLogo,pal);writestatus(logo,FLogo);
 //Font .
 alfy = alfont_load_font(FFont);writestatus(alfy,FFont);
 //Ship .
 for(i=0;i<SHFRAMES;i++)
 {
  sprintf(fname,FShip,i+1);
  shipbs[i] = load_bitmap(fname,pal);
  writestatus(shipbs[i],fname);
 }
 //Ship Blink .
 for(i=0;i<SHBLFRAMES;i++)
 {
  sprintf(fname,FShipBlink,i+1);
  shipbl[i] = load_bitmap(fname,pal);
  writestatus(shipbl[i],fname);
 }
 //Ship Blank .
 shipblank = load_bitmap(FBlank,pal);writestatus(shipblank,FBlank);
 //Bullets .
 for(i=0;i<NUMBULLTYPES;i++)
 {
 for(j=0;j<bframes[i];j++)
 {
  sprintf(fname,FBullets,i+1,j+1);
  bullbs[i][j] = load_bitmap(fname,pal);
  writestatus(bullbs[i][j],fname);
 }
 }
 //Enemy Bullets .
 for(i=0;i<NUMEBULLTYPES;i++)
 { 
 for(j=0;j<ebframes[i];j++)
 {
  sprintf(fname,FEBullets,i+1,j+1);
  ebullbs[i][j] = load_bitmap(fname,pal);
  writestatus(ebullbs[i][j],fname);
 }
 }  
 //Ammo .
 for(i=0;i<NUMBULLTYPES;i++)
 {
 for(j=0;j<caframes[i];j++)
 {
  sprintf(fname,FCAmmo,i+1,j+1);
  bammobs[i][j] = load_bitmap(fname,pal);
  writestatus(bammobs[i][j],fname);
 }
 }
 //Other Collectibles .
 for(i=0;i<COLNUMS;i++)
 {
 for(j=0;j<cgframes[i];j++)
 { 
  sprintf(fname,FCOthers,i+1,j+1);
  colbs[i][j] = load_bitmap(fname,pal);
  writestatus(colbs[i][j],fname);
 }
 }
 //Enemies .
 for(i=0;i<ENEMYTYPES;i++)
 {
  for(j=0;j<enemyframes[i];j++)
  {
   sprintf(fname,FEnemies,i+1,j+1);
   enemyanims[i][j] = load_bitmap(fname,pal);
   writestatus(enemyanims[i][j],fname);
  }
 }
 //Explosions .
 for(i=0;i<NUMEXPLODE;i++)
 {
  sprintf(fname,FExplosions,i+1);
  explodeframe[i] = load_bitmap(fname,pal);
  writestatus(explodeframe[i],fname);
 } 
 //Statistics Icons .
 for(i=0;i<NUMICONS;i++)
 {
  sprintf(fname,FIcons,i+1);
  icons[i] = load_bitmap(fname,pal);
  writestatus(icons[i],fname);
 }
 //Sounds .
 if(!serr)
 {
  for(i=0;i<NUMLEVELS;i++)
  {
  sprintf(fname,FMusic,i+1);
  music[i]=load_mod(fname);writestatus(music[i],fname);
  }
  mmusic=load_mod(FMMusic);writestatus(mmusic,FMMusic);
  for(i=0;i<NUMBULLTYPES;i++)
  {
  sprintf(fname,FShoot,i+1);
  shoot[i]=load_sample(fname);
  writestatus(shoot[i],fname);
  }
  for(i=0;i<NUMEBULLTYPES;i++)
  {
  sprintf(fname,FEShoot,i+1);
  eshoot[i]=load_sample(fname);
  writestatus(eshoot[i],fname);
  }
  burst=load_sample(FExplodeSound);writestatus(burst,FExplodeSound);
  died=load_sample(FExplodeDied);writestatus(died,FExplodeDied);
  scollec=load_sample(FSCollec);writestatus(scollec,FSCollec);
  won=load_sample(FSWon);writestatus(won,FSWon);
 }
 //Scores .
 initrandhsc();
 readhsc();
 sprintf(logmsg,"Loading Done !");logwrite();
}
