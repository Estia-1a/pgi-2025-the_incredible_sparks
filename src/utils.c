#include <estia-image.h>
#include <stddef.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */


pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y){
    if (x>width || y>height){
        return NULL ;
    }
    if (data==NULL){
        return NULL ;
    }

    return (pixelRGB *) &data[n*(x+y*width)] ; /*x colonne et y ligne*/
}

unsigned char* set_pixel(unsigned char* datadest, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int xdest, const unsigned int ydest, unsigned char* datasrc,const unsigned int xsrc, const unsigned int ysrc){
   if (xdest<width && ydest<height && xsrc<width && ysrc<height){
    datadest[n*(xdest+ydest*width)] = datasrc[n*(xsrc+ysrc*width)];
    datadest[n*(xdest+ydest*width)+1] = datasrc[n*(xsrc+ysrc*width)+1];
    datadest[n*(xdest+ydest*width)+2] = datasrc[n*(xsrc+ysrc*width)+2];
   }
   
    return datadest ;   
}