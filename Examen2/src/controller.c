#include "controller.h"


/** \brief Carga los datos de los libros desde el archivo libro.csv (modo texto).
 *
 * \param path char*
 * \param LinkedList* pArrayListLibro
 * \return int
 *
 */
int controller_loadLibroFromText(char* path, LinkedList* pArrayListLibro)
{
	int idAux=-1;
	FILE* pFile;
	if(pArrayListLibro!=NULL && path!=NULL)
	{
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_libroFromText(pFile, pArrayListLibro);
			idAux=1;
		}
		fclose(pFile);
	}

	return idAux;
}

/** \brief Carga los datos de los libros desde el archivo editorial.csv (modo texto).
 *
 * \param path char*
 * \param LinkedList* pArrayListEditorial
 * \return int
 *
 */
int controller_loadEditorialFromText(char* path,LinkedList* pArrayListEditorial)
{
	int idAux=-1;
	FILE* pFile;
	if(pArrayListEditorial!=NULL && path!=NULL)
	{
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			idAux=parser_editorialFromText(pFile, pArrayListEditorial);
			idAux=1;
		}
		fclose(pFile);
	}
	return idAux;
}

///brief filtra libros alfabeticamente
//param pArrayListLibro
///

int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int rtn=-1;
	printf("ordenando Alfabeticamente por nombre. Espere un momento...\n");
	rtn=ll_sort(pArrayListLibro, libro_sortByAutor, 1);
	return rtn;
}


///brief imprime lista junto con la descripcion de editorial
///lista de libro y lista de editorial
///
int imprimirLista(LinkedList* pArrayListaLibro, LinkedList* pArrayListaEditorial)
{
int rtn=-1;
eLibro* pLibro;
eEditorial* pEditorial;
int id;
char titulo[100];
char autor[51];
float precio;
int idEditorial;
int editorialId;
char nombre[100];
	if(ll_len(pArrayListaLibro)>0)
	{
		printf("ID\t    Titulo        Autor\t\tPrecio\t\tEditorial\n");
		for(int i=0;i<ll_len(pArrayListaLibro);i++)
		{
			pLibro=ll_get(pArrayListaLibro,i);
			if(pLibro!=NULL)
			{
				libro_getId(pLibro, &id);
				libro_getTitulo(pLibro, titulo);
				libro_getAutor(pLibro, autor);
				libro_getPrecio(pLibro, &precio);
				libro_getIdEditorial(pLibro, &idEditorial);

				//printf("%d\t%10s\t%10s\t%5.2f\t\t\%d\n", id,titulo,autor,precio, idEditorial);
				for(int j=0;j<ll_len(pArrayListaEditorial);j++)
				{
					pEditorial=ll_get(pArrayListaEditorial,j);

					editorial_getId(pEditorial, &editorialId);
					editorial_getNombre(pEditorial, nombre);
					if(idEditorial==editorialId)
					{
						printf("%d\t%10s\t%10s\t%5.2f\t\t\%s\n", id,titulo,autor,precio, nombre);
					}
				}
				rtn=1;
			}
		}
	}
	return rtn;
}

///brief imprime 1 solo libro con su descripcion, se usa junto a la funcion de abajo
///lista de libro y el indice del libro a imprimir
///
void imprimirLibro(LinkedList* pArrayList, int i)
{
	eLibro* pLibroAuxiliar;
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
	if(pArrayList!=NULL)
	{
		pLibroAuxiliar=ll_get(pArrayList,i);
		libro_getId(pLibroAuxiliar, &id);
		libro_getTitulo(pLibroAuxiliar, titulo);
		libro_getAutor(pLibroAuxiliar, autor);
		libro_getPrecio(pLibroAuxiliar, &precio);
		libro_getIdEditorial(pLibroAuxiliar, &idEditorial);

		printf("%d\t%8s\t%10s\t%.2f\t\t%d\n",id,titulo,autor,precio,idEditorial);
	}
}

///brief: imprime todos los libros, se usan generalmente para los libros filtrados
///param: list
///
int imprimirLibrosFiltrados(LinkedList* pArrayList)
{
	int rtn=-1;
	if(pArrayList!=NULL && ll_len(pArrayList)>0)
	{
		printf("ID\tTitulo\t\t   Autor\t Precio\t  ID-Editorial\n");
		for(int i=0;i<ll_len(pArrayList);i++)
		{
			imprimirLibro(pArrayList, i);
			rtn=1;
		}
	}
	return rtn;
}

///brief: guarda una lista como texto
///param: path, y la lista a guardar
///
int controller_saveListAsTxt(char* path, LinkedList* this)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && this!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn=saveLibroAsText(this, pFile);
		}
		fclose(pFile);
	}
	return rtn;
}
