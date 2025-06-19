#include <estia-image.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"
#include <string.h>
 int stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}



void dimension(char *source_path){
    int width=0, height =0, channel_count=0;
    unsigned char *data = NULL;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d,%d",width,height);
    
}

void first_pixel (char *source_path){
    /*int R,G,B;*/ 
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("first_pixel: %d, %d, %d",data[0],data[1],data[2]); 
}

void second_line (char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
   printf("second_line: %d, %d, %d",data[3*width],data[3*width+1],data[3*width+2]); 
}

void print_pixel( char *filename, int x, int y ){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    pixelRGB *pixel ;
    read_image_data(filename, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width,height, channel_count, x, y);
    printf("print_pixel(%d, %d): %d, %d, %d",x,y,pixel->R,pixel->G,pixel->B);
}

void tenth_pixel (char *source_path){
    /*int R,G,B;*/ 
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("tenth_pixel: %d, %d, %d",data[27],data[28],data[29]); 
}
/*Milestone 2: issue #20*/
void max_pixel(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int somme =0;
    int maxpixel =0;
    pixelRGB *pixel ;
    int i,j;  /* i colonne et j ligne */
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            pixel = get_pixel(data, width,height, channel_count, i, j);
            somme = pixel->R + pixel->G + pixel->B ;
           /*printf("la somme est: %d ", somme);*/ 
            if(somme > maxpixel){
                stockcol = i ;
                stocklig = j ;
                stockR = pixel->R ;
                stockG = pixel->G ;
                stockB = pixel->B ;
                maxpixel=somme;
            }
        }
    }
    printf("max_pixel(%d, %d): %d, %d, %d",stockcol, stocklig,stockR,stockG,stockB);
}

/*Milestone 2: issue #19*/
void min_pixel(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int somme =0;
    int minpixel =800;
    pixelRGB *pixel ;
    int i,j;  /* i colonne et j ligne */
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            pixel = get_pixel(data, width,height, channel_count, i, j);
            somme = pixel->R + pixel->G + pixel->B ;
           /*printf("la somme est: %d ", somme);*/ 
            if(somme < minpixel){
                stockcol = i ;
                stocklig = j ;
                stockR = pixel->R ;
                stockG = pixel->G ;
                stockB = pixel->B ;
                minpixel=somme;
            }
        }
    }
    printf("min_pixel(%d, %d): %d, %d, %d",stockcol, stocklig,stockR,stockG,stockB);
}

/*Milestone 2: Issue #18*/
void max_component(char *source_path, char *argcomponent){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;    
    int stockmaxc =0 ;
    pixelRGB *pixel ;
    int i,j;  /* i colonne et j ligne */
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            pixel = get_pixel(data, width,height, channel_count, i, j);
            if(argcomponent[0] == 'R'){
                if(pixel->R > stockmaxc){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->R ;
                stockmaxc = pixel->R ;
                }    
            } 
            if(argcomponent[0] == 'G'){
                if(pixel->G > stockmaxc){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->G ;
                stockmaxc = pixel->G ;
                }    
            } 
            if(argcomponent[0] == 'B'){
                if(pixel->B > stockmaxc){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->B ;
                stockmaxc = pixel->B ;
                }    
            } 
        }
    }
    printf("max_component %c (%d, %d): %d",argcomponent[0],stockcol, stocklig,stock);
}

void min_component(char *source_path, char *argcomponent){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;    
    int stockcol = 0, stocklig =0 , stock = 255;
    pixelRGB *pixel ;
    int i,j;  /* i colonne et j ligne */
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            pixel = get_pixel(data, width,height, channel_count, i, j);
            if(argcomponent[0] == 'R'){
                if(pixel->R < stock){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->R ;
                }    
            }
            if(argcomponent[0] == 'G'){
                if(pixel->G < stock){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->G ;
                }    
            }
            if(argcomponent[0] == 'B'){
                if(pixel->B < stock){
                stockcol = i ;
                stocklig = j ;
                stock = pixel->B ;
                }    
            }
        }
    }
    printf("min_component %c (%d, %d): %d",argcomponent[0],stockcol, stocklig,stock);
}

void stat_report (char *source_path){
    FILE *fichier = fopen("stat_report.txt", "w");
   
    if (fichier == NULL){
        perror("Erreur lors de l'ouverture du fichier");
    }
    max_pixel(source_path);
    fprintf(fichier,"max_pixel(%d, %d): %d, %d, %d \n",stockcol, stocklig,stockR,stockG,stockB);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    min_pixel(source_path);
    fprintf(fichier,"min_pixel(%d, %d): %d, %d, %d \n",stockcol, stocklig,stockR,stockG,stockB);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    max_component(source_path,"R");
    fprintf(fichier,"max_component %c (%d, %d): %d \n",'R',stockcol, stocklig,stock);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    max_component(source_path,"G");
    fprintf(fichier,"max_component %c (%d, %d): %d \n",'G',stockcol, stocklig,stock);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    max_component(source_path,"B");
    fprintf(fichier,"max_component %c (%d, %d): %d \n",'B',stockcol, stocklig,stock);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    min_component(source_path,"R");
    fprintf(fichier,"min_component %c (%d, %d): %d \n",'R',stockcol, stocklig,stock);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    min_component(source_path,"G");
    fprintf(fichier,"min_component %c (%d, %d): %d \n",'G',stockcol, stocklig,stock);
    fprintf(fichier,"\n");
    stockcol = 0, stocklig =0 , stockR =0, stockG = 0, stockB = 0, stock =0 ;
 
    min_component(source_path,"B");
    fprintf(fichier,"min_component %c (%d, %d): %d ",'B',stockcol, stocklig,stock);
 
 
 
    fclose(fichier);
}

void color_red(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i ;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0; i<channel_count * width * height;i++){
       if (i%3 != 0){
        data[i] = 0;
       }
    }
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 3 : Issue #14*/
void color_green(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i ;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0; i<channel_count * width * height;i++){
       if (i%3 == 0){
        data[i] = 0;
        data[i+2] = 0;
       }
       if (i > channel_count * width * height - 2){
        break;
       }
    }
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 3 : Issue #13*/
void color_blue(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i ;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0; i<channel_count * width * height;i++){
       if (i%3 == 0){
        data[i] = 0;
        data[i+1] = 0;
       }
       if (i > channel_count * width * height - 1){
        break;
       }
    }
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 3: Issue #12*/
void color_gray(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i,j ; /* i colonne et j ligne */
    int average =0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            average =round((double)(get_pixel(data, width,height, channel_count, i, j)->R + get_pixel(data, width,height, channel_count, i, j)->G + get_pixel(data, width,height, channel_count, i, j)->B) / 3) ;
            data[channel_count*(i+j*width)]=average;
            data[channel_count*(i+j*width)+1]=average;
            data[channel_count*(i+j*width)+2]=average;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 3: Issue #11*/
void color_invert(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i,j ; /* i colonne et j ligne */
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){          
            data[channel_count*(i+j*width)]=255 - get_pixel(data, width,height, channel_count, i, j)->R ;
            data[channel_count*(i+j*width)+1]=255 - get_pixel(data, width,height, channel_count, i, j)->G ;
            data[channel_count*(i+j*width)+2]=255 - get_pixel(data, width,height, channel_count, i, j)->B ;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 3: Issue#10 */
void color_gray_luminance(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i,j ; /* i colonne et j ligne */
    int average =0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            average =round((double)(0.21 * get_pixel(data, width,height, channel_count, i, j)->R + 0.72 * get_pixel(data, width,height, channel_count, i, j)->G + 0.07 * get_pixel(data, width,height, channel_count, i, j)->B) / 3) ;
            data[channel_count*(i+j*width)]=average;
            data[channel_count*(i+j*width)+1]=average;
            data[channel_count*(i+j*width)+2]=average;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}
 
/*Milestone3 : Issue#1 desaturate*/
void color_desaturate(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i,j ; /* i colonne et j ligne */
    int calcul =0;
    int rouge = 0 , vert = 0 , bleu = 0 ;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0;j<height;j++){
        for (i=0;i<width; i++){
            rouge=get_pixel(data, width,height, channel_count, i, j)->R ;
            vert=get_pixel(data, width,height, channel_count, i, j)->G ;
            bleu=get_pixel(data, width,height, channel_count, i, j)->B ;
 
            calcul=round((double)(fmin(fmin(rouge,vert),bleu) + fmax(fmax(rouge,vert),bleu))/2) ;
            data[channel_count*(i+j*width)]=calcul;
            data[channel_count*(i+j*width)+1]=calcul;
            data[channel_count*(i+j*width)+2]=calcul;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}

/*Milestone 4 Issue #9*/
void rotate_cw(char *source_path){
    unsigned char* datasrc; 
    unsigned char* datadest; 
    int width, height, channel_count; 
    int x, y; 
    int indexsrc, indexdest, new_x, new_y; 
    read_image_data(source_path, &datasrc, &width, &height, &channel_count); 
    int size = width * height * 3; 
    datadest = malloc(size); 
    for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x=height-1-y; 
            new_y=x; 
            indexdest=new_y*height*3+3*new_x; 
            datadest[indexdest]=datasrc[indexsrc]; 
            datadest[indexdest+1]=datasrc[indexsrc+1]; 
            datadest[indexdest+2]=datasrc[indexsrc+2]; 
        }
    }
    
    write_image_data("image_out.bmp", datadest, height, width);
    free(datadest);
}

/*Milestone 4 Issue #8*/
void rotate_acw(char *source_path){
    unsigned char* datasrc; 
    unsigned char* datadest; 
    int width, height, channel_count; 
    int x, y; 
    int indexsrc, indexdest, new_x, new_y; 
    read_image_data(source_path, &datasrc, &width, &height, &channel_count); 
    int size = width * height * 3; 
    datadest = malloc(size); 
    for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x=y;
            new_y=width-1-x; 
            indexdest=new_y*height*3+3*new_x; 
            datadest[indexdest]=datasrc[indexsrc]; 
            datadest[indexdest+1]=datasrc[indexsrc+1]; 
            datadest[indexdest+2]=datasrc[indexsrc+2]; 
        }
    }
    
    write_image_data("image_out.bmp", datadest, height, width);
    free(datadest);
}

//Milestone 4 Issue #7
void mirror_horizontal(char *source_path){
    unsigned char* datasrc; 
    unsigned char* datadest; 
    int width, height, channel_count; 
    int x, y; 
    int indexsrc, indexdest, new_x, new_y; 
    read_image_data(source_path, &datasrc, &width, &height, &channel_count); 
    int size = width * height * 3; 
    datadest = malloc(size); 
    for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x = width - 1 - x;
            new_y=y; 
            indexdest=new_y*width*3+3*new_x; 
            datadest[indexdest]=datasrc[indexsrc]; 
            datadest[indexdest+1]=datasrc[indexsrc+1]; 
            datadest[indexdest+2]=datasrc[indexsrc+2]; 
        }
    }
    
    write_image_data("image_out.bmp", datadest, width, height);
    free(datadest);
}

// Milestone 4 Issue #6
void mirror_vertical(char *source_path){
    unsigned char* datasrc; 
    unsigned char* datadest; 
    int width, height, channel_count; 
    int x, y; 
    int indexsrc, indexdest, new_x, new_y; 
    read_image_data(source_path, &datasrc, &width, &height, &channel_count); 
    int size = width * height * 3; 
    datadest = malloc(size); 
    for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x =x;
            new_y=height - 1 - y; 
            indexdest=new_y*width*3+3*new_x; 
            datadest[indexdest]=datasrc[indexsrc]; 
            datadest[indexdest+1]=datasrc[indexsrc+1]; 
            datadest[indexdest+2]=datasrc[indexsrc+2]; 
        }
    }
    
    write_image_data("image_out.bmp", datadest, width, height);
    free(datadest);
}

void mirror_total(char *source_path){
    unsigned char* datasrc; 
    unsigned char* datadest; 
    int width, height, channel_count; 
    int x, y; 
    int indexsrc, indexdest, new_x, new_y; 
    read_image_data(source_path, &datasrc, &width, &height, &channel_count); 
    int size = width * height * 3; 
    datadest = malloc(size); 
    unsigned char *datatotal= malloc(height*width*channel_count*sizeof(unsigned char));
   // mirror_vertical
    for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x =x;
            new_y=height - 1 - y; 
            indexdest=new_y*width*3+3*new_x; 
            datadest[indexdest]=datasrc[indexsrc]; 
            datadest[indexdest+1]=datasrc[indexsrc+1]; 
            datadest[indexdest+2]=datasrc[indexsrc+2]; 
        }
    }

    //mirror_horizontal
     for (y=0;y<height;y++) { 
        for (x=0;x<width;x++){ 
            indexsrc=y*width*3+3*x; 
            new_x = width - 1 - x;
            new_y=y; 
            indexdest=new_y*width*3+3*new_x; 
            datatotal[indexdest]=datadest[indexsrc]; 
            datatotal[indexdest+1]=datadest[indexsrc+1]; 
            datatotal[indexdest+2]=datadest[indexsrc+2]; 
        }
    }

    write_image_data("image_out.bmp", datatotal, width, height);
    free(datadest);
    free(datatotal);
}

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data = NULL;
    printf("%d %d %d %d",center_x, center_y, crop_width, crop_height);
    int image_width=0, image_height =0, channel_count=0;
    read_image_data(source_path, &data, &image_width, &image_height, &channel_count);
    // Clamp crop size to avoid going outside original image
    int x_start = center_x - crop_width / 2;
    int y_start = center_y - crop_height / 2;
 
    if (x_start < 0) x_start = 0;
    if (y_start < 0) y_start = 0;
    if (x_start + crop_width > image_width) x_start = image_width - crop_width;
    if (y_start + crop_height > image_height) y_start = image_height - crop_height;
 
    // Clamp dimensions in case the crop size is larger than the image
    if (crop_width > image_width) crop_width = image_width;
    if (crop_height > image_height) crop_height = image_height;
 
    // Allocate memory for cropped image
    unsigned char *cropped = malloc(crop_width * crop_height * 3);
    if (!cropped) {
        fprintf(stderr, "Erreur: allocation mémoire échouée\n");
        return;
    }
 
    // Copy pixels line by line
    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            int src_idx = ((y_start + y) * image_width + (x_start + x)) * 3;
            int dst_idx = (y * crop_width + x) * 3;
            memcpy(&cropped[dst_idx], &data[src_idx], 3);
        }
    }
 
    // Save to BMP
    save_bmp("image_out.bmp", cropped, crop_width, crop_height);
    free(cropped);
}

void scale_nearest(char*source_path, float scale) {
    int width, height, channel_count;
    unsigned char*datasrc;
    unsigned char*datadest;
    
    read_image_data(source_path, &datasrc, &width, &height, &channel_count);
 
    int widthdest = (int)(width * scale);
    int heightdest = (int)(height * scale);
 
    if (scale > 0) {
        if (widthdest == 0) widthdest = 1;
        if (heightdest == 0) heightdest = 1;
    }
 
    if (widthdest <=0 || heightdest <=0) {
        printf("Erreur : dimension invalides (scale = %.2f)\n", scale);
        free(datasrc);
        return;
    }
 
    datadest = (unsigned char*)malloc(widthdest * heightdest * channel_count * sizeof(unsigned char));  
 
 
        int y,x,c;
        for (y = 0; y < heightdest; y ++) {
            for (x = 0; x < widthdest; x ++) {
 
                int src_x = (int)((float)x / scale + 0.5f);
                int src_y = (int)((float)y / scale + 0.5f);
               
                if (src_x < 0) src_x = 0;
                if (src_y < 0) src_y = 0;
                if (src_x >= width) src_x = width -1;
                if (src_y >= height) src_y = height -1;
 
 
                int target_pixel_index = (y * widthdest + x)*channel_count;
                int source_pixel_index = (src_y * width + src_x)*channel_count;
 
                for (c=0; c <channel_count; c++) {
                    datadest[target_pixel_index + c]= datasrc[source_pixel_index + c];
                }
               
            }
        }
        write_image_data("image_out.bmp", datadest, widthdest, heightdest);
 
        free(datasrc);
        free(datadest);
}
