#include "Point.h"
#include "Line.h"
#include "ImageData.h"
#include "PNGRenderer.h"
#include "BresenhamLineDrawer.h"

#include <iomanip>
#include <ctime>

#define NUM_LINES 4

int main( int argc, char* argv[] ) {
   
   ulong width = 1000;
   ulong height = 1000;
   std::string filename = "temp.png";
   ulong background_color = ImageData::BLACK;
   ImageData* image_data = new ImageData( width, height, filename, background_color );

   BresenhamLineDrawer* line_drawer = new BresenhamLineDrawer( image_data );

   Point* start_points[NUM_LINES];
   Point* end_points[NUM_LINES];
   ulong line_colors[NUM_LINES];
   Line*  lines[NUM_LINES];

   std::clock_t start_time;
   double total_duration = 0.0;

   std::cout << "Drawing "<< NUM_LINES <<" lines and outputting to " << filename << std::endl;

   start_points[ 0 ] = new Point( 500, 50 ); 
   end_points[ 0 ] = new Point( 500, 950 );
   line_colors[ 0 ] = ImageData::RED;

   start_points[ 1 ] = new Point( 50, 500 ); 
   end_points[ 1 ] = new Point( 950, 500 );
   line_colors[ 1 ] = ImageData::GREEN;

   start_points[ 2 ] = new Point( 182, 182 ); 
   end_points[ 2 ] = new Point( 818, 818 );
   line_colors[ 2 ] = ImageData::BLUE;
   
   start_points[ 3 ] = new Point( 182, 818 );
   end_points[ 3 ] = new Point( 818, 182 ); 
   line_colors[ 3 ] = ImageData::YELLOW;

   start_time = std::clock();
   for ( int index = 0; index < NUM_LINES; index++ ) {
      lines[ index ] = new Line( start_points[ index ], end_points[ index ], line_colors[ index ] );
   
      line_drawer->draw( lines[ index ] );
   }
   total_duration = ( std::clock() - start_time ) / ( double ) CLOCKS_PER_SEC;
   std::cout << "Total Duration " << std::setprecision(5) << total_duration 
      << " seconds." << std::endl;

   PNGRenderer* renderer = new PNGRenderer( image_data );

   renderer->render( );

   delete renderer;
   
   for ( int index = 0; index < NUM_LINES; index++ ) {
      delete lines[ index ];
      delete end_points[ index ];
      delete start_points[ index ];
   }
   
   delete line_drawer;
   delete image_data;
   return 0;
}
