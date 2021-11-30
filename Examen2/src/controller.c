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
		}
		fclose(pFile);
	}
	return idAux;
}

int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int rtn=-1;
	printf("ordenando Alfabeticamente por nombre. Espere un momento...\n");
	rtn=ll_sort(pArrayListLibro, libro_sortByAutor, 1);
	return rtn;
}


/*int controller_saveLibroAsText(char* path, LinkedList* pArrayListLibro)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListLibro!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn=saveLibroAsText(pArrayListLibro, pFile);
		}
		fclose(pFile);
	}
	return rtn;
}*/


int controller_loadFromText(char* path , LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales)
{
	//int ultimoIdCargado=-1;
	int rtn = -1;
	char libros[15]="Libro.csv";
	char editoriales[15]="Editorial.csv";
	FILE* pFile;
	if(pll_listaLibros!=NULL && path!=NULL)
	{
		if(strcmp(path,libros)==0)
		{
			pFile = fopen(path, "r");
			if(pFile!=NULL)
			{
				parser_libroFromBinary(pFile ,pll_listaLibros);
				rtn=1;
			}

		}
		if(strcmp(path,editoriales)==0)
		{
			pFile = fopen(path, "r");
			if(pFile!=NULL)
			{
				parser_editorialFromText(pFile, pll_ListaEditorales);
				rtn=1;
			}

		}
		fclose(pFile);
	}
    return rtn;
}
