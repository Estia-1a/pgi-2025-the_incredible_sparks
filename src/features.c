#include <estia-image.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"
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
    /*printf("channel count %d",channel_count);*/
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

 

 

