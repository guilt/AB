/*Collision Detection*/

#ifndef _M_COLL_
#define _M_COLL_

int insiderect(int x, int y, int x1, int y1, int w1, int h1)
{
 if( x >= x1 && x <= ( x1+w1 ) && y >= y1 && y <= ( y1+h1 ) )
   return 1;
 return 0;
}

int rcollide(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2)
{
 if( insiderect(x1,y1,x2,y2,w2,h2) || 
     insiderect(x1+w1,y1,x2,y2,w2,h2) || 
     insiderect(x1,y1+h1,x2,y2,w2,h2) || 
     insiderect(x1+w1,y1+h1,x2,y2,w2,h2) )
   return 1;
 return 0;
}

int collide(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2)
{
 if(rcollide(x1,y1,w1,h1,x2,y2,w2,h2)||
    rcollide(x2,y2,w2,h2,x1,y1,w1,h1))
    {
    return 1;
    }
 return 0;   
}

#endif  // _M_COLL_
