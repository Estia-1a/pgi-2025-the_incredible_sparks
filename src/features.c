#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

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
