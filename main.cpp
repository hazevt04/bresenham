#include "Point.h"
#include "Line.h"
#include "ImageData.h"
#include "PNGRenderer.h"
#include "BresenhamLineDrawer.h"

#include <iomanip>
#include <ctime>

#define NUM_LINES 100

int main( int argc, char* argv[] ) {
   
   ulong width = 1000;
   ulong height = 1000;
   ulong line_color = ImageData::BLACK;
   std::string filename = "temp.png";
   ulong background_color = ImageData::WHITE;
   ImageData* image_data = new ImageData( width, height, filename, background_color );

   BresenhamLineDrawer* bresenham_line_drawer = new BresenhamLineDrawer( image_data );

   Point* start_points[NUM_LINES];
   Point* end_points[NUM_LINES];
   Line*  lines[NUM_LINES];

   std::clock_t start_time;
   double total_duration = 0.0;

   start_time = std::clock();
   for ( int index = 0; index < NUM_LINES; index++ ) {
      ulong x0 = 20 + ( index * 10 );
      ulong y0 = 40;
      ulong x1 = 100 + ( index * 10 );
      ulong y1 = 100;
      start_points[ index ] = new Point( x0, y0 ); 
      end_points[ index ] = new Point( x1, y1 );
      lines[ index ] = new Line( start_points[ index ], end_points[ index ], line_color );
   
      bresenham_line_drawer->draw( lines[ index ] );
   }
   total_duration = ( std::clock() - start_time ) / ( double ) CLOCKS_PER_SEC;
   std::cout << "Total Duration " << std::setprecision(3) << total_duration 
      << " seconds." << std::endl;

   PNGRenderer* renderer = new PNGRenderer( image_data );

   renderer->render( );

   delete renderer;
   
   for ( int index = 0; index < NUM_LINES; index++ ) {
      delete lines[ index ];
      delete end_points[ index ];
      delete start_points[ index ];
   }
   
   delete image_data;
   return 0;
}
