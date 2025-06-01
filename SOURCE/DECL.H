//Declarations .

#ifndef _M_DECL_
#define _M_DECL_

//Headers
#include "sysdefs.h"
#include "ver.h"

//General
#define RAND  64
#define FSIZE 20
#define NUMMENUITEMS 5
#define VERTSPC 10
#define HORIZSPC 10
#define YMENUOFFSET ((logo->h)*2 + VERTSPC)
#define nofg() ((2*(gen%2))-1)
#define PI 3.141592653 //Enough Precision !!!
#define GST 1000

//Double Buffer .
#define RFT 5 //Corrected Value.
#define render() {blit(dbuffer,screen,0,0,0,0,XRES,YRES);rest(RFT);}
#define cls() clear_bitmap(dbuffer) 

//Effects
#define DC 200
#define MAXSTARS 300
#define SSPEED 1
#define PARAMS (NUM_COLORS/LAYERS)
#define FREQUENCY 500
#define LAYERS 8
#define MAXEXPLODE 10
#define PNOEX 0
#define PEX   1
#define YPDIR 6
#define YNDIR -YPDIR
#define NODIR 0
#define XPDIR 0.75
#define XNDIR -XPDIR

//Enemy
#define MUL  2
#define ETABNUM 360
#define ENEMYXLIMIT (XRES)
#define NUMENEMIES  20
#define MAXENEMYTYPES  120
#define EHEIGHT(i) (enemies[i].enemybs->h)
#define EWIDTH(i) (enemies[i].enemybs->w)
#define MAXENEMYFRAMES 6
#define EMTYPES 3
#define EH      0
#define ES      1 
#define EL      2

//Enemy's Bullets
#define MAXEBULLTYPES 10
#define MAXEBULLETS 80
#define MAXEBFRAMES 4
#define EBHEIGHT(i) (ebullets[i].bbs->h)
#define EBWIDTH(i) (ebullets[i].bbs->w)

//Hero
#define MAXSHFRAMES 10
#define MAXSHBLFRAMES 10
#define HHEIGHT shipbs[shipframe]->h
#define HWIDTH shipbs[shipframe]->w
#define EBFD -1

//Score
#define GENMULT 15
#define LIFEGIVINGSCORE 20000
#define MAXSCORE 99999999

//Hero's Bullets
#define MAXBULLTYPES 10
#define MAXBULLETS 80
#define MAXBFRAMES 4
#define SPEC1 3  //Always 0
#define H     0
#define V     1
#define Y     2
#define J     3
#define SPEC2 2
#define U     0
#define D     1
#define BHEIGHT(i) (bullets[i].bbs->h)
#define BWIDTH(i) (bullets[i].bbs->w)

//Collectibles
#define MAXCOLLEC 30
#define MAXCFRAMES 8
#define CPARAM1 10
#define CPARAM2 11
#define CPARAM3 17
#define COLTYPES 2
#define CA 0
#define BPI 0.5
#define CO 1
#define MAXCOLTYPES 20
#define CHEIGHT(i) (colls[i].cbs->h)
#define CWIDTH(i) (colls[i].cbs->w)

//Statistics
#define NUMICONS 4
#define MEDI 0
#define MEDIX 0
#define MEDIY 0
#define LIF 1
#define LIFX 0
#define LIFY (MEDIX+IWIDTH(MEDI)+VERTSPC)
#define SCO 2
#define SCOX 0
#define SCOY (getmaxy()-FSIZE-1)
#define LEV 3
#define LEVX (getmidx())
#define LEVY 0
#define IHEIGHT(i) (icons[i]->h)
#define IWIDTH(i) (icons[i]->w)
#define AMMOX (getmidx())
#define AMMOY (getmaxy()-FSIZE-1)

//Scores
#define MAXHSC 10
#define HSCMNO 2
#define HSCNX 10
#define HSCLX (getmidx()*1.2)
#define HSCSX (getmidx()*1.6)
#define NAMELEN 30

//Credits
#define CREDMNO 3
#define MSPEED 1
#define NLINES 90
#define NTIMES ((NLINES*(FSIZE+SSPC))/MSPEED)
#define CRMUL XRES/4
#define SSPC (FSIZE/4)
#define MAXCVAL 256

//Options
#define NUMOPTMENUITEMS 4
#define STATES 2

//Levels
#define MAXLEVELS 20

//Shots
#define SDT 3000

//Videos
#define MAXVIDEOS 20
#define VIDDT 1000

//General
int i,j,done;
unsigned int gen;
char TITLE[STRB]={""};

//Credits
int readable=1;
//Please Do Not Change ....
const char names[NLINES][STRB]={
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"Game Design, Programming,..",
"",
"V Karthik \"Guilt\" Kumar",
"Nikhil \"Niks\" Karnad",
"",
"",
"Support and Libraries",
"",
"Inspired by: Johan Pietz",
"Allegro: alleg.sourceforge.net",
"JGMOD: Jefferey Guan Foo Wah",
"DUMB: Ben Davis, Robert J Ohannessian and Julien Cugniere",
"DUMBOGG: Sven",
"Ogg Vorbis: xiph.org ",
"AllegroFont: Javier Gonzalez and Doug Eleveld",
"",
"",
"Our Dear Friends",
"",
"Abilash \"Abi\"",
"Adarsh \"Adu\"",
"Anand \"KPoo\"",
"Anand \"Miss\"",
"Arun",
"Arun \"Paal Pandi\"",
"Arun \"Strings\" Vijay",
"Balakrishnan \"Balkoo\"",
"Chandramouli \"Mezhi\"",
"Deepak \"Goundar\"",
"Ganesh@Baskaran \"Gaba\"",
"Gautham \"Thalai\"",
"Gurulakshmanan \"Guru\"",
"Karthikeyan \"Kama\"",
"Karthikeyan \"Patti\"",
"Kaushik \"Vetti\" Narayanan",
"Koushiik",
"Laxmikanth \"Mech\"",
"Madhu \"Palli\"",
"Madhu \"Upili\"",
"Prakash \"Baadu\"",
"Prasanna \"Kapa\"",
"Prashant \"Pachu\"",
"Raghuraman \"B ra\"",
"Ramakrishnan \"Mottai\"",
"Renju",
"Shameem \"Appu\"",
"Srinidhi \"Gultu\"",
"Sriram \"Alladi\"",
"Sudharsan \"Sucha\"",
"Suudhan \"Semi\"",
"Swagath \"Golt\"",
"Ravi",
"Vasanth Kumar",
"Vevek \"Pondy\"",
"Vinu",
"",
"",
"The Rest",
"",
"Almighty",
"Family",
"ANC",
"Munnaji/Nagarji Redi",
"One Typhoon Web-Cam",
"MOD Archives",
"XMMS/Winamp",
"Action Arcade Adventure Set",
"Microsoft Paint",
"GCC and Dev-C++",
"Horse Shelters",
"and, of course, Cut-Copy-Paste ;)",
"",
"",
"We Thank You For Playing ...",
"",
"",
"",
"",
"",
""
};

//Options .
int osel=0;
char omenu[NUMOPTMENUITEMS][STRB]={
{"SFX : %s"}
,{"Music : %s"}
,{"Statistics : %s"}
,{"Master Volume : %3u"}
//,{"MIDI Volume : %3u"}
}
;
char flaSTR[STATES][STRB]={{"Off"},{"On"}};

//UDF
char UNISTR[STRB]={"Method Not Implemented Yet"};

//Videos
DATAFILE *dataf;
SAMPLE *vidsample;
void *flidata;
struct video
{
char filename[STRB],password[STRB];
int an,vn;
}
videos[MAXVIDEOS]= //Video Data .
{
{"data\\videos\\allegro.vid","AfterBurn Video",0,1},
};
int vidw,vidh,vidx,vidy; //Used .
int numvideos=1; //Number .
int ALLEGRO_LOGO=0; //Indices .

//Log
FILE *logfp = NULL;
char logmsg[STRB];

//Ini
int ininwrite=0;
FILE *inifp = NULL;
char inimsg[STRB];

//HSc
int hscnwrite=0;
FILE *hscfp = NULL;
char hscmsg[STRB];
char HSCSTRNAME[STRB]={"Name"},HSCSTRLEVEL[STRB]={"Level"},HSCSTRSCORE[STRB]={"Score"},
     STRCHSCNAME[STRB]={"You have achieved a High Score !! Enter your name... "},
     STRNNONE[NAMELEN+1]={"Anonymous"};

//Statistics
int sflag=1;
BITMAP *icons[NUMICONS];
char buff[STRB];

//Levels
int NUMLEVELS=5;
unsigned int rkills[MAXLEVELS]={50,75,100,125,150};
char LEVSTR[STRB]={"Level Clear"},WINSTR[STRB]={"You've Won"};

//Scores
int NUMHSC=10;
char SCOFORMAT[STRB]={"%08u"};
struct Player
{
 char name[NAMELEN+1];
 unsigned int win, level, lives, score, life;
}Players[MAXHSC+1]=
{
{"Pachu",0,0,0,0,0},
{"B ra",0,0,0,0,0},
{"Kaushik",0,0,0,0,0},
{"Alladi",0,0,0,0,0},
{"Vinu",0,0,0,0,0},
{"Niks",0,0,0,0,0},
{"Mezhi",0,0,0,0,0},
{"Koushiik",0,0,0,0,0},
{"Mottai",0,0,0,0,0},
{"Guilt",0,0,0,0,0}
},temp;

//Menu
ALFONT_FONT *alfy;
BITMAP *logo;
int activecol=0, passivecol=0, govcol=0, sel=0, mdone=0;
char menu[NUMMENUITEMS][STRB]={"Play","Options","High Scores","Credits","Exit"};

//Sounds
#ifdef DUMB
//From Bruce Perry .
static AL_DUH_PLAYER *volatile adp=NULL;
static int volatile semaphore=0;
#endif //DUMB

MUSIC *music[MAXLEVELS],*mmusic;
int serr=0,merr=0,gm=0,plsounds=1,plmusic=1;

//Display 
BITMAP *dbuffer;

//Bullets
int curbul,NUMBULLTYPES=6;
SAMPLE *shoot[MAXBULLTYPES];
BITMAP *bullbs[MAXBULLTYPES][MAXBFRAMES];
int numbullets[MAXBULLTYPES]={35,25,20,20,20,8,0,0,0,0},
    xbspeed[MAXBULLTYPES]={16,20,18,15,0,0,0,0,0,0}, //< Thinnest FrameWidth of Enemy !
    ybspeed[MAXBULLTYPES]={0,10,0,5,20,0,0,0,0,0},    //< Thinnest FrameHeight of Enemy !
    bframes[MAXBULLTYPES]={2,2,2,4,4,1,0,0,0,0},
    blimit[MAXBULLTYPES]={1,2,3,3,1,2,0,0,0,0},
    BMUL[MAXBULLTYPES]={2,4,3,4,6,1,1,1,1,1},
    bdir[MAXBULLTYPES]={H,J,H,V,Y,H,H,H,H,H},
    dammo[MAXBULLTYPES]={-1,50,50,100,100,40,0,0,0,0},
    maxammo[MAXBULLTYPES]={-1,3000,3000,2500,2000,400,0,0,0,0},
    ammo[MAXBULLTYPES];
double dbdamage[MAXBULLTYPES]={1,2,3,4,7,9,0,0,0,0},
       maxbdamage[MAXBULLTYPES]={50,40,40,40,45,60,0,0,0,0},
       bdamage[MAXBULLTYPES];
char bullnames[MAXBULLTYPES][STRB]=
{"Fire Fury","Poison Pint","Lightning Lash","Icy Impulse","Vertical Ventura","Mega Mine",
"","","",""},INFISTR[STRB]={"Infinite"};
struct bullholder
{
int x,y;
int active,type;
int spec1,spec2; //Directional
BITMAP *bbs;
}
bullets[MAXBULLETS];

//Collectibles
int COLNUMS=5;
BITMAP *bammobs[MAXBULLTYPES][MAXCFRAMES];
BITMAP *colbs[MAXCOLTYPES][MAXCFRAMES];
int cglife[MAXCOLTYPES]={30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cglives[MAXCOLTYPES]={0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cgiscore[MAXCOLTYPES]={450,1050,3500,8000,12000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cgframes[MAXCOLTYPES]={4,4,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cgfmul[MAXCOLTYPES]={40,40,20,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int cclife[MAXCOLTYPES]={200,400,350,350,250,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int cgammo[MAXBULLTYPES]={0,300,250,150,200,100,0,0,0,0};
int cgascore[MAXBULLTYPES]={100,25,20,20,30,35,0,0,0,0};
int caframes[MAXBULLTYPES]={4,4,4,4,4,4,0,0,0,0};
int cafmul[MAXBULLTYPES]={40,40,40,40,40,40,0,0,0,0};
int calife[MAXBULLTYPES]={600,800,800,800,400,300,0,0,0,0};
struct collectibleholder
{
int x,y;
int active,type,spec;
BITMAP *cbs;
}colls[MAXCOLLEC];

//Effects
SAMPLE *burst;
char GOVSTR[STRB]={"Game Over"},PAUSESTR[STRB]={"Game Paused"},
QDSTR[STRB]={"Quit (Y/N) ?"},KEYSTR[STRB]={"Press any Key to Continue"};
int starcolors[LAYERS],NUMSTARS=288,NUMEXPLODE=10;
struct starholder
{
int x,y,state;
}stars[MAXSTARS];
BITMAP *explodeframe[MAXEXPLODE];

//Hero
char STRNONE[STRB]={"???"};
int SHBLFRAMES=3,SHFRAMES=5,PARAM=10,MAXBLAF=10,MAXLIFE=100,MAXLIVES=3,
MAXPOSLIVES=10,SHSPEED=8,shipx,shipy,shipframe,shipblframe,active,lives,blaf,scored,
kills,level,win;
BITMAP *cur,*shipbl[MAXSHBLFRAMES],*shipbs[MAXSHFRAMES],*shipblank;
SAMPLE *died,*scollec,*won;

//Score
unsigned int score=0;

//Enemy
int ENEMYTYPES=11; //With Thanks to Nikhil !
BITMAP *enemyanims[MAXENEMYTYPES][MAXENEMYFRAMES];
int enemylives[MAXENEMYTYPES]={1,4,3,2,2,1,3,2,1,2,4};
int enemyframes[MAXENEMYTYPES]={4,4,4,2,1,2,2,3,1,1,1};
int FMUL[MAXENEMYTYPES]={25,30,60,40,1,40,40,40,1,1,1};
int enemydam[MAXENEMYTYPES]={2,10,7,5,2,3,10,4,5,5,10};
int emove[MAXENEMYTYPES]={0,1,1,1,1,0,0,0,0,0,0};
int ebtype[MAXENEMYTYPES]={-1,0,1,-1,2,-1,3,-1,-1,-1,4};
int elmap[MAXLEVELS][MAXENEMYTYPES]= // A Mapping to check if enemies are
                                     // available .
{
{1,0,0,1,0,1,0,1,0,0,0},
{1,1,0,0,0,0,1,0,0,1,0},
{1,0,1,0,1,0,1,0,0,1,0},
{1,1,1,0,1,1,1,0,1,1,0},
{1,1,1,1,1,1,1,1,1,1,1}
};
double enemyxsp[MAXENEMYTYPES]={2.5,2.25,2.5,3,2,4,3,2.25,3,3.5,2.25},
       enemyysp[MAXENEMYTYPES]={0,55,45,35,25,0,0,0,0,0,0};
double sintable[ETABNUM],costable[ETABNUM];
struct enemyholder
{
 int x, active, type,explframe,enemymot,espec;
 double y;
 BITMAP *enemybs;
}enemies[NUMENEMIES];

//Enemy Bullets
int curebul,NUMEBULLTYPES=5;
SAMPLE *eshoot[MAXEBULLTYPES];
BITMAP *ebullbs[MAXEBULLTYPES][MAXEBFRAMES];
int xebspeed[MAXEBULLTYPES]={10,15,30,15,25,0,0,0,0,0}, //<FrameWidth of Hero !
    ebframes[MAXEBULLTYPES]={1,1,1,1,1,0,0,0,0,0},
    eblimit[MAXEBULLTYPES]={10,15,20,5,15,0,0,0,0,0},
    EBMUL[MAXEBULLTYPES]={1,1,1,1,1,1,1,1,1,1};
double ebdamage[MAXEBULLTYPES]={8,5,9,7,10,0,0,0,0,0};
struct ebullholder
{
int x,y,type,active;
BITMAP *bbs;
}
ebullets[MAXEBULLETS];

//Palette
PALETTE pal;

double orparam=0.4,ogparam=0.6,obparam=0.55,rparam,gparam,bparam,   //Greenish-Cyan .
       orsparam=-1,ogsparam=-1,obsparam=-1,rsparam,gsparam,bsparam, //Random .
       orgparam=1,oggparam=0,obgparam=0,rgparam,ggparam,bgparam;    //Red .

int acr=255,acg=255,acb=210,
    pcr=128,pcg=64,pcb=0;

//P.S : Multiply all values by the highest possible individual palette value (i.e. 255) - Ta Da !

#endif //_M_DECL_
