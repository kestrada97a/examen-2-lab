#ifndef PARSER_H_
#define PARSER_H_
#include "libro.h"
#include "editorial.h"
#include "LinkedList.h"
int parser_libroFromText(FILE* pFile, LinkedList* pArrayListLibro);
int parser_editorialFromText(FILE* pFile, LinkedList* pArrayListEditorial);
int parser_libroFromBinary(FILE* pFile, LinkedList* pArrayListLibro);
int parser_editorialFromBinary(FILE* pFile, LinkedList* pArrayListEditorial);
int saveLibroAsText(LinkedList* pArrayListLibro, FILE* path);
int saveEditorialAsText(LinkedList* pArrayListEditorial, FILE* path);
int saveLibroAsBinary(LinkedList* pArrayListLibro, FILE* path);
int saveEditorialAsBinary(LinkedList* pArrayListEditorial, FILE* path);

#endif
