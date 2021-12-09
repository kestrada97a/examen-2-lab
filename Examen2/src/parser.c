#include "parser.h"

/** \brief Parsea los datos los datos de los libros desde el archivo libro.csv (modo texto).
 *
 * \param path char*
 * \param LinkedList* pArrayListLibro
 * \return int
 *
 */
int parser_libroFromText(FILE* pFile, LinkedList* pArrayListLibro)
{
	int idAux;
	char id[100];
	char titulo[100];
	char autor[100];
	char precio[100];
	char idEditorial[100];
	eLibro* pLibro;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
		pLibro = libro_newParametros(id, titulo, autor, precio, idEditorial);
		ll_add(pArrayListLibro,pLibro);
		libro_getId(pLibro, &idAux);
	}
	return idAux;

}

/** \brief Parsea los datos los datos de las editoriales desde el archivo editorial.csv (modo texto).
 *
 * \param path char*
 * \param LinkedList* pArrayListEditorial
 * \return int
 *
 */
int parser_editorialFromText(FILE* pFile, LinkedList* pArrayListEditorial)
{
	int idAux;
	char idEditorial[25];
	char nombre[100];
	eEditorial* pEditorial;
	fscanf(pFile,"%[^,],%[^\n]\n",idEditorial,nombre);
	while(!feof(pFile))
	{
	fscanf(pFile,"%[^,],%[^\n]\n",idEditorial,nombre);
	pEditorial= editorial_newParametros(idEditorial, nombre);
	ll_add(pArrayListEditorial,pEditorial);
	editorial_getId(pEditorial, &idAux);
	}
	return idAux;
}

/** \brief Parsea los datos los datos de los libros desde el archivo libro.csv (modo binario).
 *
 * \param path char*
 * \param LinkedList* pArrayListLibro
 * \return int
 *
 */
int parser_libroFromBinary(FILE* pFile, LinkedList* pArrayListLibro)
{
	int idAux=-1;
	int i=0;
	eLibro* pLibro;
	while(!feof(pFile))
	{
		pLibro=libro_new();
		fread(pLibro,sizeof(pLibro),1,pFile);
		if(pLibro!=NULL)
		{
			i++;
			pLibro=ll_get(pArrayListLibro,i);
			libro_getId(pLibro,&idAux);
		}
	}
	return idAux;

}

/** \brief Parsea los datos los datos de las editoriales desde el archivo editorial.csv (modo binario).
 *
 * \param path char*
 * \param LinkedList* pArrayListEditorial
 * \return int
 *
 */
int parser_editorialFromBinary(FILE* pFile, LinkedList* pArrayListEditorial)
{
	int idAux=-1;
	int i=0;
	eEditorial* pEditorial;
	while(!feof(pFile))
	{
		pEditorial=editorial_new();
		fread(pEditorial,sizeof(pEditorial),1,pFile);
		if(pEditorial!=NULL)
		{
			i++;
			pEditorial=ll_get(pArrayListEditorial,i);
			editorial_getId(pEditorial, &idAux);
		}
	}
	return idAux;
}

//brief Guarda los datos de los libros en el archivo libro.csv(modo texto)
//param path char
//param LinkedList* pArrayListLibro
//return int
int saveLibroAsText(LinkedList* pArrayListLibro, FILE* path)
{
	int rtn=-1;
	eLibro* pLibro;
	int id;
	char titulo[100];
	char autor[100];
	float precio;
	int idEditorial;
	fprintf(path,"id,titulo,autor,precio,idEditorial\n");
	for(int i=0;i<ll_len(pArrayListLibro);i++)
	{
		pLibro=ll_get(pArrayListLibro,i);
		libro_getId(pLibro,&id);
		libro_getTitulo(pLibro, titulo);
		libro_getAutor(pLibro, autor);
		libro_getPrecio(pLibro, &precio);
		libro_getIdEditorial(pLibro, &idEditorial);
		fprintf(path,"%d,%s,%s,%.2f,%d",id,titulo,autor,precio,idEditorial);
		rtn=1;
	}
	return rtn;
}


//brief Guarda los datos de las editoriales en el archivo editorial.csv(modo texto)
//param path char
//param LinkedList* pArrayListEditorial
//return int
int saveEditorialAsText(LinkedList* pArrayListEditorial, FILE* path)
{
	int rtn=-1;
	eEditorial* pEditorial;
	int idEditorial;
	char nombre[100];
	fprintf(path,"idEditorial,nombre\n");
	for(int i=0;i<ll_len(pArrayListEditorial);i++)
	{
		pEditorial=ll_get(pArrayListEditorial,i);
		editorial_getId(pEditorial, &idEditorial);
		editorial_getNombre(pEditorial, nombre);
		rtn=1;
	}
	return rtn;
}



//brief Guarda los datos de los libros en el archivo libro.csv(modo binario)
//param path char
//param pArrayListLibroLinkedList*
//return int
int saveLibroAsBinary(LinkedList* pArrayListLibro, FILE* path)
{
	int rtn=-1;
	eLibro* pLibro;
	for(int i=0;i<ll_len(pArrayListLibro);i++)
	{
		pLibro=ll_get(pArrayListLibro,i);
		fwrite(pLibro,sizeof(pLibro),1,path);
		rtn=1;
	}
	return rtn;
}

//brief Guarda los datos de las editoriales en el archivo editorial.csv(modo binario)
//param path char
//param LinkedList* pArrayListEditorial
//return int
int saveEditorialAsBinary(LinkedList* pArrayListEditorial, FILE* path)
{
	int rtn=-1;
	eEditorial* pEditorial;
	for(int i=0;i<ll_len(pArrayListEditorial);i++)
	{
		pEditorial=ll_get(pArrayListEditorial,i);
		fwrite(pEditorial,sizeof(pEditorial),1,path);
		rtn=1;
	}

	return rtn;

}

