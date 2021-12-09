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
	char auxiliar[20];
	int corroboracion;
	int flagMenu=-1;
	LinkedList* pArrayListLibro=NULL;
	LinkedList* pArrayListEditorial=NULL;
	LinkedList* pArrayListMinotauro=NULL;
	LinkedList* pArrayListConDescuento=NULL;
	pArrayListLibro=ll_newLinkedList();
	pArrayListEditorial=ll_newLinkedList();
	pArrayListMinotauro=ll_newLinkedList();
	pArrayListConDescuento=ll_newLinkedList();
	int contadorQuinientos;
	float acumuladorPearson;

	do
	{
		menu();
		opcion=ingresarEnteroConMaximo("Ingrese opcion: ", 8);
		switch(opcion)
		{
		case 1:
			pedirString("Ingrese archivo que desea abrir: ", auxiliar);
			if(strcmp(auxiliar,"Libro.csv")==0)
			{
				corroboracion=controller_loadLibroFromText("libro.csv", pArrayListLibro);
				MensajeDeError(corroboracion, "Carga completa.\n", "error, en la carga.\n");
			}
			else
			{
				printf("error en la carga\n");
			}
			flagMenu=1;
			break;
		case 2:
			pedirString("Ingrese archivo que desea abrir: ", auxiliar);
			if(strcmp(auxiliar,"Editorial.csv")==0)
			{
				corroboracion=controller_loadEditorialFromText("editorial.csv", pArrayListEditorial);
				MensajeDeError(corroboracion, "Carga completa.\n", "error, en la carga.\n");
			}
			else
			{
				printf("error en la carga\n");
			}
			flagMenu=1;
			break;
		case 3:
			if(flagMenu==1)
			{
			corroboracion=controller_sortLibro(pArrayListLibro);
			MensajeDeError(corroboracion, "Carga completa\n", "error, en la carga.\n");
			}
			else
			{
				printf("Debe cargar libros primero");
			}
			break;
		case 4:
			imprimirLista(pArrayListLibro,pArrayListEditorial);
			break;
		case 5:
			pArrayListMinotauro=ll_filter(pArrayListLibro,filtroMinotauro);
			corroboracion=imprimirLibrosFiltrados(pArrayListMinotauro);
			if(corroboracion==1)
			{
				corroboracion=controller_saveListAsTxt("Minotauro.csv", pArrayListMinotauro);
				MensajeDeError(corroboracion, "Carga completa\n","error en la carga.\n");
			}
			break;
		case 6:
			pArrayListConDescuento=ll_map(pArrayListLibro, filtroPlanetaXXI);

			corroboracion=imprimirLibrosFiltrados(pArrayListConDescuento);
			if(corroboracion==1)
			{
				corroboracion=controller_saveListAsTxt("mapeado.csv", pArrayListConDescuento);
				MensajeDeError(corroboracion, "Carga completa\n","error en la carga.\n");
			}

			break;
		case 7:
			contadorQuinientos=ll_count(pArrayListLibro,libro_acumulador_contador,&acumuladorPearson);
			printf("hay %d libros que cuestan más de $500\n",contadorQuinientos);

			break;
		case 8:
			ll_count(pArrayListLibro,libro_acumulador_contador,&acumuladorPearson);
			printf("La suma total de los precios PEARSON es $%.2f\n",acumuladorPearson);
			break;
		}





	}while(opcion!=9);

	ll_deleteLinkedList(pArrayListLibro);
	ll_deleteLinkedList(pArrayListEditorial);
	ll_deleteLinkedList(pArrayListMinotauro);
	ll_deleteLinkedList(pArrayListConDescuento);


	return EXIT_SUCCESS;
}
