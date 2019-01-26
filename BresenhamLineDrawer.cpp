#include <stdio.h>
#include <cmath>

#include "util.h"
#include "Line.h"
#include "ImageData.h"
#include "BresenhamLineDrawer.h"

void BresenhamLineDrawer::draw_vertical( Line* line ) {

   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x0 = start_point.get_x( );
   ulong y1 = end_point.get_y( );
   ulong y0 = start_point.get_y( );

   for ( ulong index = y0; index < y1; index++ ) {
      this->image_data->Setpixel( x0, index, color );
      DEBUG_PRINTF( "Index %lu: x is %lu\n", index, x0 );
   }
}

void BresenhamLineDrawer::draw_horizontal( Line* line ) {

   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x1 = end_point.get_x( );
   ulong x0 = start_point.get_x( );
   ulong y0 = start_point.get_y( );

   for ( ulong index = x0; index < x1; index++ ) {
      this->image_data->Setpixel( index, y0, color );
      DEBUG_PRINTF( "Index %lu: x is %lu\n", index, y0 );
   }
}


void BresenhamLineDrawer::draw_low( Line* line ) {

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
   long yi = 1;
   
   DEBUG_PRINTF( "delta_y is %ld\n", delta_y );
   DEBUG_PRINTF( "delta_x is %ld\n", delta_x );
   DEBUG_PRINTF( "two_delta_y is %ld\n", two_delta_y );
   DEBUG_PRINTF( "two_delta_x is %ld\n", two_delta_x );
   DEBUG_PRINTF( "color is %lu\n", color );
   
   if ( delta_y < 0 ) {
      yi = -1;
      delta_y = -delta_y;
   }
   long delta_upper = two_delta_y - delta_x;
   DEBUG_PRINTF( "delta_upper is %ld\n", delta_upper );
   ulong y = y0;

   for ( ulong index = x0; index <= x1; index++ ) {
      this->image_data->Setpixel( index, y, color );
      DEBUG_PRINTF( "Index %lu: y is %lu\n", index, y );

      // TODO: Get rid of branch
      if ( delta_upper > 0 ) {
         y += yi;
         delta_upper -= two_delta_x;
      
         DEBUG_PRINTF( "Index %lu: y incremented to %lu\n", index, y );
         DEBUG_PRINTF( "Index %lu: delta_upper changed to %ld\n", index, delta_upper );

      }
      delta_upper += two_delta_y;
      DEBUG_PRINTF( "Index %lu: delta_upper increased to %ld\n", index, delta_upper );
      
   } // end of for ( ulong index = x0; index < x1; index++ ) {
}


void BresenhamLineDrawer::draw_high( Line* line ) {

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
   long xi = 1;
   
   DEBUG_PRINTF( "delta_y is %ld\n", delta_y );
   DEBUG_PRINTF( "delta_x is %ld\n", delta_x );
   DEBUG_PRINTF( "two_delta_y is %ld\n", two_delta_y );
   DEBUG_PRINTF( "two_delta_x is %ld\n", two_delta_x );
   DEBUG_PRINTF( "color is %lu\n", color );
   
   if ( delta_x < 0 ) {
      xi = -1;
      delta_x = -delta_x;
   }
   long delta_upper = two_delta_x - delta_y;
   DEBUG_PRINTF( "delta_upper is %ld\n", delta_upper );
   ulong x = x0;

   for ( ulong index = y0; index <= y1; index++ ) {
      this->image_data->Setpixel( x, index, color );
      DEBUG_PRINTF( "Index %lu: x is %lu\n", index, x );

      // TODO: Get rid of branch
      if ( delta_upper > 0 ) {
         x += xi;
         delta_upper -= two_delta_y;
      
         DEBUG_PRINTF( "Index %lu: x incremented to %lu\n", index, x );
         DEBUG_PRINTF( "Index %lu: delta_upper changed to %ld\n", index, delta_upper );

      }
      delta_upper += two_delta_x;
      DEBUG_PRINTF( "Index %lu: delta_upper increased to %ld\n", index, delta_upper );
      
   } // end of for ( ulong index = x0; index < x1; index++ ) {

}

void BresenhamLineDrawer::draw( Line* line ) {

   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x1 = end_point.get_x( );
   ulong x0 = start_point.get_x( );
   ulong y1 = end_point.get_y( );
   ulong y0 = start_point.get_y( );
   
   Line* reversed_line = new Line( &end_point, &start_point, color );
  
   if ( ( y1 == y0 ) && ( x1 != x0 ) ) {
      draw_horizontal( line );
   } else if ( ( x1 == x0 ) && ( y1 != y0 ) ) {
      draw_vertical( line );
   } else {
      if ( abs( y1 - y0 ) < abs( x1 - x0 ) ) {
         if ( x0 > x1 ) {
            draw_low( reversed_line );
         } else {
            draw_low( line );
         }
      } else {
         if ( y0 > y1 ) {
            draw_high( reversed_line );
         } else {
            draw_high( line );
         }
      } // end of if ( abs( y1- y0 ) < abs( x1 - x0 ) ) {
   } // end of if ( ( y1 == y0 ) && ( x1 != x0 ) ) {
   
   delete reversed_line;
}



