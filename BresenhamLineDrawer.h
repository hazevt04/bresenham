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
   private:
      void original_draw( Line* line );
      void integer_draw( Line* line );
      ImageData* image_data;      
};


#endif
