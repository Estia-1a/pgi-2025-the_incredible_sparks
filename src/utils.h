#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/

typedef struct _pixelRGB {
  unsigned char R ;
  unsigned char G ;
  unsigned char B ;
} pixelRGB ;

pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y);
unsigned char* set_pixel(unsigned char* datadest, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int xdest, const unsigned int ydest, unsigned char* datasrc,const unsigned int xsrc, const unsigned int ysrc);
void scale_neargpt(unsigned char *data, int width, int height, float scale, unsigned char **out_data, int *out_width, int *out_height);
#endif
