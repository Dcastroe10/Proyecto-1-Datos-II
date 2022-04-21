#include "tarjetas.h"


#include <QtDebug>

/**
 * @brief tarjetas::set_image Le asigna al objeto tarjeta la imagen en bits
 * @param array
 */
void tarjetas::set_image(char array[] )
{
    QImage imagen_prueba (array);
    int tamaño = imagen_prueba.sizeInBytes();
    memcpy(this->image,imagen_prueba.bits(),tamaño);
}

/**
 * @brief tarjetas::get_image
 * @return el array de bits correspondiente a la imagen
 */
char* tarjetas::get_image(){
    return image;
}

/**
 * @brief tarjetas::set_ID se le asigna un número para poder utilizarlos a la hora de comparar si son parejas
 * @param num
 */
void tarjetas::set_ID(int num){
    ID = num;
}

/**
 * @brief tarjetas::get_ID
 * @return el identificador de la tarjeta
 */
int tarjetas::get_ID(){
    return ID;
}
