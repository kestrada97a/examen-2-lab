/*
 ============================================================================
 Name        : Examen2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editorial.h"
#include "libro.h"
#include "controller.h"
#include "General.h"
int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int auxId=300;
	int corroboracion;
	int flagMenu=-1;
	int testeo;
	LinkedList* pArrayListLibro=NULL;
	LinkedList* pArrayListEditorial=NULL;
	pArrayListLibro=ll_newLinkedList();
	pArrayListEditorial=ll_newLinkedList();
	char auxxiliar[20];

	do
	{
		menu();
		opcion=ingresarEnteroConMaximo("Ingrese opcion: ", 5);
		switch(opcion)
		{
		case 1:
			pedirString("Ingrese que desea abrir", auxxiliar);
			auxId=controller_loadLibroFromText("C:\Users\brake\Desktop\Examen lab 2\Examen2\src\editorial.csv", pArrayListLibro);
			if(auxId==1)
			{
				printf("nice\n");
			}
			else
			{
				printf("error\n");
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}





	}while(opcion!=5);

	ll_deleteLinkedList(pArrayListLibro);


	return EXIT_SUCCESS;
}