#ifndef _IMAGEDATA_H_
#define _IMAGEDATA_H_

#include <string>

typedef unsigned long ulong;

class ImageData {
   public:
      ImageData( ulong num_iterations, std::string filename, 
            ulong background_color );
      ImageData( ulong width, ulong height, std::string filename, 
            ulong background_color );
      ~ImageData();
      
      void Setpixel( ulong idx, ulong val );
      void Setpixel( ulong x, ulong y, ulong val );
      void Setpixels( ulong* pixels ) { this->pixels = pixels; }

      void Setwidth( ulong width ) { this->width = width; }
      void Setheight( ulong height ) { this->height = height; }
      void Setnum_pixels( ulong num_pixels ) { 
         this->num_pixels = num_pixels; 
      }
      void Setfilename( ulong filename ) { 
         this->filename = filename; 
      }
      void Setbackground_color( ulong background_color ) {
         this->background_color = background_color;
      }

      ulong* Getpixels( ) { return pixels; }
      ulong Getwidth( ) { return width; }
      ulong Getheight( ) { return height; }
      ulong Getnum_pixels( ) { return num_pixels; }
      ulong Getbackground_color( ) { return background_color; }
      std::string Getfilename( ) { return filename; } 

      static const ulong WHITE   = 0xffffffL;
      static const ulong BLACK   = 0x000000L;
      static const ulong RED     = 0xff0000L;
      static const ulong YELLOW  = 0xffff00L;
      static const ulong BLUE    = 0x0080ffL;
      static const ulong GREEN   = 0x00ff00L;
      static const ulong ORANGE  = 0xff8000L;
      static const ulong PURPLE  = 0x7f00ffL;
      static const ulong BROWN   = 0x663300L;
      static const ulong GRAY    = 0x808080L;
      static const ulong PINK    = 0xffccccL;

   private:
      ulong* pixels;
      ulong width;
      ulong height;
      ulong num_pixels;
      ulong background_color;
      std::string filename;
};

#endif
