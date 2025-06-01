//Menu

#include "loop.c"

void FontInit()
{
 alfont_text_mode(-1);
 alfont_set_font_size(alfy,FSIZE);
}

void dotitle()
{
set_window_title(TITLE);
}

void beginlog()
{
sprintf(TITLE,"%s - v%s",VProductName,VProductVersion);
sprintf(logmsg,"%s Log",TITLE);logwrite();
}

void DrawMenu()
{
 int u;
 cls();
 updatestarfield();
 drawstarfield();
 masked_blit(logo,dbuffer,0,0,getmidx()-(logo->w/2),logo->h/4,logo->w,logo->h);
 for(u=0;u<NUMMENUITEMS;u++)
 {
  alfont_textout_centre_aa(dbuffer,alfy,menu[u],getmidx(),YMENUOFFSET+(u*(FSIZE+VERTSPC)),passivecol);
 }
 alfont_textout_centre_aa(dbuffer,alfy,menu[sel],getmidx(),YMENUOFFSET+(sel*(FSIZE+VERTSPC)),activecol);
 render();
}

//Intro Cinematics.
void gameinitvideo()
{
docinema(ALLEGRO_LOGO); 
}

void Menu()
{
 gameinitvideo();
 sprintf(logmsg,"-- Menu Initialising --");logwrite();
 initetable();
 FontInit();
 gencolorinit();
 starfieldinit();
 starcolinit();
 setpal();
 cls();
 clear_keybuf();
 playmusic();
 sprintf(logmsg,"-- Menu Loop --");logwrite();
 do
 {
  DrawMenu();
  if(keypressed())
  {
   if(key[KEY_ESC]) { mdone=1; }
   evshandle();
   doshandle();
   if(key[KEY_UP]) {sel+=NUMMENUITEMS-1;sel%=NUMMENUITEMS;}
   if(key[KEY_DOWN]) { sel++;sel%=NUMMENUITEMS; }
   if(key[KEY_ENTER]) 
   {
    switch(sel)
    {
     case 0: gloop(); break;
     case 1: optloop();break;
     case 2: hscloop();break;
     case 3: credloop();break;
     case 4: mdone=1; break;
    }
    }
   }
  clear_keybuf();
 }while(!mdone);
 stopmusic();
 sprintf(logmsg,"-- Menu Loop Done --");logwrite();
}
