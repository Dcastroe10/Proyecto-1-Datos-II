#ifndef TARJETAS_H
#define TARJETAS_H

#include <iostream>
#include <string>
#include<stdio.h>





class tarjetas
{

public:
void set_image(char*);
void set_ID(int);


char* get_image();
int get_ID();



private:
char image [40000];
int ID;



};

#endif // TARJETAS_H
