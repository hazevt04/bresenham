#include "Point.h"
#include "Line.h"
#include "ImageData.h"
#include "PNGRenderer.h"
#include "BresenhamLineDrawer.h"

int main( int argc, char* argv[] ) {
   
   ulong width = 400;
   ulong height = 400;
   ulong line_color = ImageData::BLACK;
   std::string filename = "temp.png";
   ulong background_color = ImageData::WHITE;
   ImageData* image_data = new ImageData( width, height, filename, background_color );

   BresenhamLineDrawer* bresenham_line_drawer = new BresenhamLineDrawer( image_data );

   Point* start_point = new Point( 20, 40 ); 
   Point* end_point = new Point( 100, 100 );
   Line* line = new Line( start_point, end_point, line_color );

   bresenham_line_drawer->draw( line );
   
   PNGRenderer* renderer = new PNGRenderer( image_data );

   renderer->render( );

   delete renderer;
   delete line;
   delete end_point;
   delete start_point;
   delete image_data;
   return 0;
}
