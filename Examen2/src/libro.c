#include "libro.h"

//brief Crea memoria para un nuevo elemento libro
//param void
//param void
//return pLibro

eLibro* libro_new()
{
	eLibro* pLibro;
	pLibro = (eLibro*) malloc (sizeof(eLibro));

	return pLibro;
}

//brief	agrega los datos al puntero del libro
//param  todos son tipo char: id, titulo, autor, precio, idEditorial
//return pLibro
eLibro* libro_newParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial)
{
	eLibro* pLibro;
	pLibro = libro_new();

	if(pLibro!=NULL && id!=NULL && titulo!=NULL && autor!=NULL && precio!=NULL && idEditorial!=NULL)
	{
		libro_setId(pLibro, atoi(id));
		libro_setTitulo(pLibro, titulo);
		libro_setAutor(pLibro, autor);
		libro_setPrecio(pLibro, atof(precio));
		libro_setIdEditorial(pLibro, atoi(idEditorial));

	}

	return pLibro;
}

//brief eliminar un elemento libro
//param eLibro* this
//return void
void libro_delete(eLibro* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

//brief agrega un id a un elemento libro
//param int id
//return int
int libro_setId(eLibro* this, int id)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->id=id;
		rtn = 1;
	}
	return rtn;
}

//brief selecciona un id de un elemento libro
//param int id
//retur int
int libro_getId(eLibro* this, int* id)
{
	int rtn=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn=1;
	}
	return rtn;
}

//brief agrega un titulo a un elemento libro
//param int id
//retur int
int libro_setTitulo(eLibro* this, char* titulo)
{
	int rtn=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
		rtn=1;
	}
	return rtn;
}

//brief selecciona un titulo de un elemento libro
//param int id
//retur int
int libro_getTitulo(eLibro* this, char* titulo)
{
	int rtn=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		rtn=1;
	}
	return rtn;
}

//brief agrega un autor a un elemento libro
//param int id
//retur int
int libro_setAutor(eLibro* this, char* autor)
{
	int rtn=-1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor,autor);
		rtn=1;
	}
	return rtn;
}

//brief selecciona un autor de un elemento libro
//param int id
//retur int
int libro_getAutor(eLibro* this, char* autor)
{
	int rtn=-1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor,this->autor);
		rtn=1;
	}
	return rtn;
}

//brief agrega un precio a un elemento libro
//param int id
//retur int
int libro_setPrecio(eLibro* this, float precio)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->precio=precio;
		rtn=1;
	}
	return rtn;
}

//brief selecciona un precio de un elemento libro
//param int id
//retur int
int libro_getPrecio(eLibro* this, float* precio)
{
	int rtn=-1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		rtn=1;
	}
	return rtn;
}

//brief agrega un idEditorial a un elemento libro
//param int id
//retur int
int libro_setIdEditorial(eLibro* this, int idEditorial)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->idEditorial=idEditorial;
		rtn=1;
	}
	return rtn;
}

//brief selecciona un idEditorial de un elemento libro
//param int id
//retur int
int libro_getIdEditorial(eLibro* this, int* idEditorial)
{
	int rtn=-1;
	if(this!=NULL && idEditorial!=NULL)
	{
		*idEditorial=this->idEditorial;
		rtn=1;
	}
	return rtn;
}

//brief ordena libros por autor
//param void* primerDato, void* segundoDato
int libro_sortByAutor(void* primerDato, void* segundoDato)
{
	eLibro* autorUno;
	eLibro* autorDos;
	int rtn=-1;
	autorUno=(eLibro*) primerDato;
	autorDos=(eLibro*) segundoDato;
	if(autorUno !=NULL && autorDos!=NULL)
	{
		rtn=strcmp(autorUno->autor,autorDos->autor);
	}
	return rtn;

	int comparacion= -1;

}
