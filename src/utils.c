#include <estia-image.h>
#include <stddef.h>
#include <stdio.h>
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

void save_bmp(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *f;
    int filesize = 54 + 3 * width * height;
    unsigned char bmpfileheader[14] = {
        'B', 'M', filesize, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    unsigned char bmpinfoheader[40] = {
        40, 0, 0, 0, width, 0, 0, 0, height, 0, 0, 0,
        1, 0, 24, 0
    };
    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);
 
    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);
 
    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);
 
    f = fopen(filename, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);
 
    // BMP stores pixels bottom to top
    for (int y = height - 1; y >= 0; y--) {
        fwrite(pixels + y * width * 3, 3, width, f);
        // Padding to multiple of 4 bytes per line
        unsigned char padding[3] = {0, 0, 0};
        fwrite(padding, 1, (4 - (width * 3) % 4) % 4, f);
    }
 
    fclose(f);
}