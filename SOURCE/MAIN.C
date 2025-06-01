//Main .
#include "files.h"
#include "time.h"
#include "lunload.c"
#include "flog.c"
#include "menu.c"

//Main ....
int main(int argc,char *argv[])
{
normalise();loginit();beginlog();
if(argc>1){if(argc>2){//For Loading a Non-Default Configuration .
sprintf(logmsg,"Argument Error : Format is %s <File> !",argv[0]);logwrite();logclose();
return(E_ERR);}strcpy(FIni,argv[1]);}normalise();iniopen();allegro_init();
register_trace_handler(errhandler);register_assert_handler(errhandler);
dotitle();install_timer();install_keyboard();
install_mouse();scare_mouse();
if(alfont_init()!=ALFONT_OK)
{sprintf(logmsg,"Font Error !");logwrite();iniclose();logclose();
allegro_exit();exit(E_ERR);}
presndinit();
if(install_sound(DIGMODE,MIDMODE,CFGFILE)){serr=1;}
postsndinit();
if(serr){sprintf(logmsg,"Sound Initialisation Error !");logwrite();}
if(merr){sprintf(logmsg,"Music Initialisation Error !");logwrite();}
set_color_depth(BPP);if(set_gfx_mode(GM,XRES,YRES,0,0))
{sprintf(logmsg,"Graphics Initialisation Error !");logwrite();iniclose();logclose();
alfont_exit();music_exit();allegro_exit();exit(E_ERR);}
load();Menu();unload();alfont_exit();music_exit();allegro_exit();iniclose();
sprintf(logmsg,"Quitting Gracefully ....");logwrite();logclose();
exit(E_OK);
}

//Required !
END_OF_MAIN();
