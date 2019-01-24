#ifndef _UTIL_H_
#define _UTIL_H_

#ifdef DEBUG
#  define DEBUG_PRINTF(args...) printf( args );
#else
   // Don't print anything
#  define DEBUG_PRINTF(args...) 
#endif


#endif
