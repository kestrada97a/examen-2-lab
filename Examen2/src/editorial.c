#include "editorial.h"

//brief Crea memoria para un nuevo elemento editorial
//param void
//param void
//return pEditorial
eEditorial* editorial_new()
{
	eEditorial* pEditorial;
	pEditorial= (eEditorial*)malloc(sizeof(eEditorial));

	return pEditorial;
}

//brief	agrega los datos al puntero del editorial
//param  todos son tipo char: idEditorial, nombre
//return pLibro
eEditorial* editorial_newParametros(char* idEditorial, char* nombre)
{
	eEditorial* pEditorial;
	pEditorial=editorial_new();
	if(idEditorial!=NULL && nombre!=NULL)
	{
		editorial_setId(pEditorial, atoi(idEditorial));
		editorial_setNombre(pEditorial, nombre);
	}
	return pEditorial;
}

//brief agrega un id a un elemento editorial
//param int id
//return int
int editorial_setId(eEditorial* this, int idEditorial)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->idEditorial=idEditorial;
		rtn=1;
	}

	return rtn;
}

//brief selecciona un id de un elemento editorial
//param int id
//retur int
int editorial_getId(eEditorial* this, int* idEditorial)
{
	int rtn=-1;
	if(this!=NULL && idEditorial!=NULL)
	{
		*idEditorial=this->idEditorial;
		rtn=1;
	}
	return rtn;
}

//brief agrega un nombre a un elemento editorial
//param int id
//retur int
int editorial_setNombre(eEditorial* this, char* nombre)
{
	int rtn=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		rtn=1;
	}
	return rtn;
}

//brief selecciona un nombre de un elemento editorial
//param int id
//retur int
int editorial_getNombre(eEditorial* this, char* nombre)
{
	int rtn=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		rtn=1;
	}
	return rtn;
}
