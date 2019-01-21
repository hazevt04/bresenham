#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <sstream>
#include <string>

typedef unsigned long ulong;

class Point {
   public:
      Point( ) { }
      ~Point( ) { }
      Point( ulong  x, ulong y ) { 
         this->x = x;
         this->y = y;

         this->display_str = "(";
         this->display_str += std::to_string( x );
         this->display_str += ", ";
         this->display_str += std::to_string( y );
         this->display_str += ")";
      }
      ulong get_x( ) { return this->x; }
      ulong get_y( ) { return this->y; }

      void display( ) {
         std::cout << "(" << x << ", " << y << ")";
      }
      std::string get_display_str( ) {
         return this->display_str;
      }
   private:
      ulong x;
      ulong y;
      std::string display_str;
};

#endif
