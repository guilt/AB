//Game Loop .

#include "pal.c"
#include "sounds.c"
#include "enemy.c"
#include "bullets.c"
#include "ebullets.c"
#include "hero.c"
#include "effects.c"
#include "stat.c"
#include "collec.c"
#include "fini.c"
#include "flog.c"
#include "hsc.c"
#include "options.c"
#include "level.c"
#include "udf.c"
#include "credits.c"
#include "vid.c"

void initetable()
{
int i;
sintable[0]=0;costable[0]=1;
for(i=1;i<ETABNUM;i++)
{
 sintable[i] = sin((i*PI*2)/ETABNUM);
 costable[i] = cos((i*PI*2)/ETABNUM);
}
for(i=(ETABNUM-1);i>0;i--)
{
 sintable[i] -= sintable[i-1]; //Relativise ....
 costable[i] -= costable[i-1];
}
}

void onetimegameinit()
{
score=0;
scored=0;
level=0;
win=0;
gm=1;
lives=MAXLIVES;
onetimebullinit();
playmusic();
}

void gameinit()
{
gen=1,active=MAXLIFE,
shipy=YRES/2,shipx=0,shipframe=0,shipblframe=0,serr=0,done=0,blaf=0,kills=0;
for(i=0;i<MAXCOLLEC;i++){colls[i].active=0;}
clear_keybuf();
bullinit();
ebullinit();
enemyinit();
genenemies();
}

void chknew()
{
 if(done==2||win==1)done=1;
 if(!active&&lives){restartmsg();gameinit();}
}

void chklevel()
{
 if(kills>rkills[level])
 {
 if(levincrement())
 {
 kills=0;
 gameinit();
 playmusic();
 }
 }
}

void update()
{
if(!done)
{
  updatestarfield();
  updatebullets();
  updateenemies();
  updateebullets();
  updatecollec();
  updatebulletsandenemies();
  UpdateHero();
  updateebulletsandhero();
}
}

void draw()
{
  cls();
  drawstarfield();
  drawbullets();
  drawenemies();
  drawebullets();
  drawhero();
  drawcollec();
  drawstat();
  render();
}

//Timing .
void updategen()
{
gen++;
}

void reupdate()
{
  updeclife();
  chknew();
  chklevel();
  updategen();
  evhandle();
}

//Game Loop.
void gloop()
{
 onetimegameinit();
 gameinit();
 while(done!=1)
 { 
  update();
  draw();
  reupdate();
  }
 gameover();
 enterhsc();
}

//Hopefully Works .
int errhandler(const char msg[])
{
sprintf(logmsg,"%s",msg);
logwrite();unload();iniclose();
sprintf(logmsg,"Quitting Prematurely ....");logwrite();
logclose();alfont_exit();music_exit();allegro_exit();return E_ERR;
}
