#include <stdio.h>
#include <cmath>

#include "util.h"
#include "Line.h"
#include "ImageData.h"
#include "BresenhamFasterLineDrawer.h"

void BresenhamFasterLineDrawer::draw( Line* line ) {

   // Uses ulong instead of double like super class (BresenhamLineDrawer)
   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x1 = end_point.get_x( );
   ulong x0 = start_point.get_x( );
   ulong y1 = end_point.get_y( );
   ulong y0 = start_point.get_y( );
   
   long delta_x = x1 - x0;
   long delta_y = y1 - y0;
   long two_delta_y = delta_y << 1;
   long two_delta_x = delta_x << 1;
   long delta_upper = two_delta_y - delta_x;
   ulong y = y0;
   
   DEBUG_PRINTF( "delta_y is %ld\n", delta_y );
   DEBUG_PRINTF( "delta_x is %ld\n", delta_x );
   DEBUG_PRINTF( "two_delta_y is %ld\n", two_delta_y );
   DEBUG_PRINTF( "two_delta_x is %ld\n", two_delta_x );
   DEBUG_PRINTF( "delta_upper is %ld\n", delta_upper );

   for ( ulong index = x0; index < x1; index++ ) {
      this->image_data->Setpixel( index, y, color );
      DEBUG_PRINTF( "Index %lu: y is %lu\n", index, y );

      // TODO: Get rid of branch
      if ( delta_upper > 0 ) {
         y++;
         delta_upper -= two_delta_x;
      
         DEBUG_PRINTF( "Index %lu: y incremented to %lu\n", index, y );
         DEBUG_PRINTF( "Index %lu: delta_upper changed to %ld\n", index, delta_upper );

      }
      delta_upper += two_delta_y;
      DEBUG_PRINTF( "Index %lu: delta_upper increased to %ldf\n", index, delta_upper );

   } // end of for ( ulong index = x0; index < x1; index++ ) {
}



