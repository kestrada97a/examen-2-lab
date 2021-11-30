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
int controller_loadFromText(char* path , LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales);

#endif /* CONTROLLER_H_ */