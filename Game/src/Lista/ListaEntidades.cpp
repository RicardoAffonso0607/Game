#include "pch.h"
#include "Lista/ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::moveAll()
{
	int i;
	for (i = 0; i < Lista.getTamanho(); i++)
	{
		if(Lista.getItem(i)->isMovable())
			Lista.getItem(i)->move();
	}
}

void ListaEntidades::drawAll()
{
	int i;
	for (i = 0; i < Lista.getTamanho(); i++)
	{
		Lista.getItem(i)->draw();
	}
}