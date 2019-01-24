#ifndef _BRESENHAMFASTERLINEDRAWER_H_
#define _BRESENHAMFASTERLINEDRAWER_H_

#include "Line.h"
#include "BresenhamLineDrawer.h"
#include "ImageData.h"

class BresenhamFasterLineDrawer: public BresenhamLineDrawer {
   public:
      BresenhamFasterLineDrawer( ) { };
      ~BresenhamFasterLineDrawer( ) { };
      BresenhamFasterLineDrawer( ImageData* image_data ) { 
         this->image_data = image_data;
      }
      void draw( Line* line );
   protected:
      ImageData* image_data;      
};


#endif
