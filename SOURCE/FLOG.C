//File Logging .

#ifndef _M_FLOG_
#define _M_FLOG_

#include "decl.h"
#include "files.h"

void loginit()
{
logfp = fopen(FLog,"w");
}

void logwrite()
{
if(logfp){fprintf(logfp,"%s\n",logmsg);}
}

void logclose()
{
if(logfp) {fclose(logfp);}
}

#endif //_M_FLOG
