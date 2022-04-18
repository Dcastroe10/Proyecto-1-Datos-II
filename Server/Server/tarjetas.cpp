#include "tarjetas.h"


#include <QtDebug>

void tarjetas::set_image(char array[] )
{
    QImage imagen_prueba (array);
    int tamaño = imagen_prueba.sizeInBytes();
    char image_to_send[tamaño];
    memcpy(this->image,imagen_prueba.bits(),tamaño);
    //qDebug()<<tamaño;
    //printf("%s\n", this->image);
    //memset(image,0,sizeof(image));
    //memcpy(image,array,40000);


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
