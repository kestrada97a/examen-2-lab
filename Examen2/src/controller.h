#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "parser.h"
#include "libro.h"
#include "editorial.h"
int controller_loadLibroFromText(char* path, LinkedList* pArrayListLibro);
int controller_loadEditorialFromText(char* path,LinkedList* pArrayListEditorial);
int controller_sortLibro(LinkedList* pArrayListLibro);
int imprimirLista(LinkedList* pArrayListaLibro, LinkedList* pArrayListaEditorial);

void imprimirLibro(LinkedList* pArrayList, int i);
int imprimirLibrosFiltrados(LinkedList* pArrayList);
int controller_saveListAsTxt(char* path, LinkedList* this);
#endif /* CONTROLLER_H_ */
