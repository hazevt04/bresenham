#include <stdio.h>
#include <cmath>

#include "util.h"
#include "Line.h"
#include "ImageData.h"
#include "BresenhamLineDrawer.h"

void BresenhamLineDrawer::draw( Line* line ) {

   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x1 = end_point.get_x( );
   ulong x0 = start_point.get_x( );
   ulong y1 = end_point.get_y( );
   ulong y0 = start_point.get_y( );
   
   double delta_x = ( double )x1 - ( double )x0;
   double delta_y = ( double )y1 - ( double )y0;
   double delta_err = fabs( ( delta_y / delta_x ) );
   //ulong delta_err_sign = std::signbit( delta_err ) ? 0 : 1;
   ulong delta_err_sign = !std::signbit( delta_err );

   double error = 0.0;
   ulong y = y0;
   
   DEBUG_PRINTF( "delta_y is %5.4f\n", delta_y );
   DEBUG_PRINTF( "delta_x is %5.4f\n", delta_x );
   DEBUG_PRINTF( "delta_err is %5.4f\n", delta_err );
   DEBUG_PRINTF( "delta_err_sign is %lu\n", delta_err_sign );

   for ( ulong index = x0; index < x1; index++ ) {
      this->image_data->Setpixel( index, y, color );
      error = error + delta_err;

      DEBUG_PRINTF( "Index: %lu: y is %lu\n", index, y );
      DEBUG_PRINTF( "Index: %lu: error is %5.4f\n", index, error );
      
      if ( error >= 0.5 ) {
         y += ( delta_err_sign * 1 );
         error -= 1.0;
         DEBUG_PRINTF( "\tIndex: %lu: y changed to %lu\n", index, y );
         DEBUG_PRINTF( "Index: %lu: error after decrement is %5.4f\n", index, error );
      }      
   } // end of for ( ulong index = x0; index < x1; index++ ) {
}



