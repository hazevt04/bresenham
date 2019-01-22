#include <iostream>
#include <iomanip>
#include <cmath>

#include "Line.h"
#include "ImageData.h"
#include "BresenhamLineDrawer.h"

void BresenhamLineDrawer::original_draw( Line* line ) {

   Point start_point = line->get_start_point( );
   Point end_point = line->get_end_point( );
   ulong color = line->get_color( );
   ulong x1 = end_point.get_x( );
   ulong x0 = start_point.get_x( );
   ulong y1 = end_point.get_y( );
   ulong y0 = start_point.get_y( );
   
   double delta_x = (double)x1 - (double)x0;
   double delta_y = (double)y1 - (double)y0;
   double delta_err = fabs( ( delta_y / delta_x ) );
   ulong delta_err_sign = std::signbit(delta_err) ? 0 : 1;

   double error = 0.0;
   ulong y = y0;
   
   std::cout << "delta_y is " << std::setprecision(4) << delta_y << std::endl;
   std::cout << "delta_x is " << std::setprecision(4) << delta_x << std::endl;
   std::cout << "delta_err is " << std::setprecision(4) << delta_err << std::endl;
   std::cout << "delta_err_sign is " << delta_err_sign << std::endl;

   for ( ulong index = x0; index < x1; index++ ) {
      this->image_data->Setpixel( index, y, color );
      error = error + delta_err;

      std::cout << "Index: " << std::fixed << index 
         << ": y is " << y << std::endl;
      std::cout << "Index: " << std::fixed << index 
         << ": error is " << std::setprecision(4) << error << std::endl;
      if ( error >= 0.5 ) {
         y += ( delta_err_sign * 1 );
         error -= 1.0;
         std::cout << "\tIndex: " << std::fixed << index 
            << ": y changed to " << y << std::endl;
         std::cout << "\tIndex: " << std::fixed << index 
            << ": error after decrement is " << std::setprecision(4) << error << std::endl;
      }      
   } // end of for ( ulong index = x0; index < x1; index++ ) {
}

void BresenhamLineDrawer::integer_draw( Line* line ) {

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
   
   std::cout << "delta_y is " << delta_y << std::endl;
   std::cout << "delta_x is " << delta_x << std::endl;
   std::cout << "two_delta_y is " << two_delta_y << std::endl;
   std::cout << "two_delta_x is " << two_delta_x << std::endl;
   std::cout << "delta_upper is " << delta_upper << std::endl;

   for ( ulong index = x0; index < x1; index++ ) {
      this->image_data->Setpixel( index, y, color );
      std::cout << "Index: " << std::fixed << index 
         << ": y is " << y << std::endl;

      // TODO: Get rid of branch
      if ( delta_upper > 0 ) {
         y++;
         delta_upper -= two_delta_x;
         std::cout << "\tIndex: " << std::fixed << index 
            << ": delta_upper reduced to " << delta_upper << std::endl;
         std::cout << "\tIndex: " << std::fixed << index 
            << ": y changed to " << y << std::endl;
      }
      delta_upper += two_delta_y;
      std::cout << "\tIndex: " << std::fixed << index 
         << ": delta_upper increased to " << delta_upper << std::endl;

   } // end of for ( ulong index = x0; index < x1; index++ ) {
}



void BresenhamLineDrawer::draw( Line* line ) {
   std::cout << "Calling " << __func__ << "()." << std::endl;
   line->display( );

   //original_draw( line );
   integer_draw( line );
}


