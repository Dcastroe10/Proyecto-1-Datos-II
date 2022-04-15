#include "tarjetas.h"


#include <QtDebug>

void tarjetas::set_image(char array[] )
{
    //memset(image,0,sizeof(image));
    memcpy(image,array,40000);
    //printf("%s\n", image);


}

char* tarjetas::get_image(){
    return image;
}


void tarjetas::set_ID(int num){
    ID = num;
}

int tarjetas::get_ID(){
    return ID;
}
