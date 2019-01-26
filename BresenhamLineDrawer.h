#ifndef _BRESENHAMLINEDRAWER_H_
#define _BRESENHAMLINEDRAWER_H_

#include "Line.h"
#include "LineDrawer.h"
#include "ImageData.h"

class BresenhamLineDrawer: public LineDrawer {
   public:
      BresenhamLineDrawer( ) { };
      ~BresenhamLineDrawer( ) { };
      BresenhamLineDrawer( ImageData* image_data ) { 
         this->image_data = image_data;
      }
      ImageData* get_image_data( ) { return this->image_data; }
      void draw( Line* line );
   protected:
      void draw_high( Line* line );
      void draw_low( Line* line );
      ImageData* image_data;      
};


#endif
