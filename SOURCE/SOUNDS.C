//Sounds .

#ifndef _M_SOUND_
#define _M_SOUND_

#include "decl.h"
#include "flog.c"

#ifdef DUMB

//From Bruce Perry .

static void poll_mod()
{
    ++semaphore;
    al_poll_duh(adp);
    --semaphore;
}

static void stop_mod()
{
AL_DUH_PLAYER *p;
    if (adp)
     {
        p = adp;
        remove_int(poll_mod);
        adp=NULL;
        while(semaphore){yield_timeslice();}
        al_stop_duh(p);
    }
}

static void play_mod(MUSIC *duh,int mloop)
{
    stop_mod();
    adp=al_start_duh(duh,DUMB_CHANNELS,DUMB_POS,DUMB_VOL,DUMB_BUFSIZE,DUMB_FREQ);
    if(adp)install_int_ex(poll_mod,BPS_TO_TIMER(DUMB_REFRESH));
}

#endif //DUMB

void presndinit()
{
reserve_voices(NUMDIGV,NUMMIDV);
set_volume_per_voice(SPV);
#ifdef DUMB
dumb_resampling_quality=DUMB_RES_QUAL;
dumb_it_max_to_mix=DUMB_ITM2M;
dumb_register_packfiles();
#else
fast_loading = FALSE;
enable_m15 = TRUE;
enable_lasttrk_loop = TRUE;
#endif //DUMB
}

void dovol()
{
if(serr) return;
set_volume(DVOL,MVOL);
}

void postsndinit()
{
if(serr) return;
dovol();
#ifndef DUMB
if(install_mod(NUMMODV)<0)
{
 merr=1;
}
#endif //DUMB
}

void stopmusic()
{
if(serr)return;
if(merr)return;
stop_mod();
}

void playmusic()
{
if(serr)return;
if(merr)return;
stopmusic();
if(plmusic)
{
if(gm)
{
play_mod(music[level],MLOOP);
}
else
{
play_mod(mmusic,MLOOP);
}
}
}

void togglemusic()
{
if(serr)return;
if(merr)return;
plmusic=1-plmusic;
if(plmusic)
{
sprintf(logmsg,"Switched Music On ");logwrite();
playmusic();
}
else
{
sprintf(logmsg,"Switched Music Off ");logwrite();
stopmusic();
}
ininwrite=1;
}

void ssndvideo()
{
if(serr)return;
stop_sample(vidsample); 
}

void sndvideo()
{
if(serr)return;
ssndvideo();
if(plsounds)
{
play_sample(vidsample,VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndshoot()
{
if(serr)return;
stop_sample(shoot[curbul]); 
}

void sndshoot()
{
if(serr)return;
ssndshoot();
if(plsounds)
{
play_sample(shoot[curbul],VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndcollec()
{
if(serr)return;
stop_sample(scollec); 
}

void sndcollec()
{
if(serr)return;
ssndcollec();
if(plsounds)
{
play_sample(scollec,VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndeshoot()
{
if(serr||curebul<0)return;
stop_sample(eshoot[curebul]); 
}

void sndeshoot()
{
if(serr||curebul<0)return;
ssndeshoot();
if(plsounds)
{
play_sample(eshoot[curebul],VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndexplode()
{
if(serr)return;
stop_sample(burst);
}

void sndexplode()
{
if(serr)return;
ssndexplode();
if(plsounds)
{
play_sample(burst,VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndwon()
{
if(serr)return;
stop_sample(won);
}

void sndwon()
{
if(serr)return;
ssndwon();
if(plsounds)
{
play_sample(won,VOLUME,PAN,SPEED,SNOLOOP);
}
}

void ssndgexplode()
{
if(serr)return;
stop_sample(died);
}

void sndgexplode()
{
if(serr)return;
ssndgexplode();
if(plsounds)
{
play_sample(died,VOLUME,PAN,SPEED,SNOLOOP);
}
}

void togglesound()
{
if(serr)return;
plsounds=1-plsounds;
if(!plsounds)
{
sprintf(logmsg,"Switched Sounds Off ");logwrite();
ssndcollec();
ssndshoot();
ssndexplode();
ssndgexplode();
ssndeshoot();
ssndwon();
}
else
{
sprintf(logmsg,"Switched Sounds On ");logwrite();
}
ininwrite=1;
}

void evshandle()
{
if(key[KEY_M]){togglemusic();}
if(key[KEY_S]){togglesound();}
}

#endif //_M_SOUND_
