#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int idEditorial;
	char nombre[51];

}eEditorial;

eEditorial* editorial_new();
eEditorial* editorial_newParametros(char* idEditorial, char* nombre);
int editorial_setId(eEditorial* this, int idEditorial);
int editorial_getId(eEditorial* this, int* idEditorial);
int editorial_setNombre(eEditorial* this, char* nombre);
int editorial_getNombre(eEditorial* this, char* nombre);

#endif /* EDITORIAL_H_ */
