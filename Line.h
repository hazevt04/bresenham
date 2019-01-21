#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include <utility>

#include "ImageData.h"
#include "Point.h"

class Line {
   public:
      Line( ) { }
      Line( Point* start_point, Point* end_point, ulong color=ImageData::BLACK ) {
         this->start_point = *start_point;
         this->end_point = *end_point;
         this->color = color;
      }
      ~Line() { }
      Point get_start_point( ) { return this->start_point; }      
      Point get_end_point( ) { return this->end_point; }
      ulong get_color( ) { return this->color; }
      void  set_start_point( Point start_point ) {
         this->start_point = start_point;
      }      
      void  set_end_point( Point end_point ) {
         this->end_point = end_point;
      }
      void display( ) {
         std::cout << "Line is from "
            << this->start_point.get_display_str()
            << " to "
            << this->end_point.get_display_str()
            << std::endl;
      }
   private:
      Point start_point;    
      Point end_point;    
      ulong color;
};


#endif
