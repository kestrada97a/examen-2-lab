#ifndef LIBRO_H_
#define LIBRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
	int id;
	char titulo[101];
	char autor[101];
	float precio;
	int idEditorial;

}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial);
void libro_delete(eLibro* this);
int libro_setId(eLibro* this, int id);
int libro_getId(eLibro* this, int* id);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_getAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, float precio);
int libro_getPrecio(eLibro* this, float* precio);
int libro_setIdEditorial(eLibro* this, int idEditorial);
int libro_getIdEditorial(eLibro* this, int* idEditorial);
int libro_sortByAutor(void* primerDato, void* segundoDato);

#endif /* LIBRO_H_ */
