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
		if(Lista.getItem(i)->getMovable())
			Lista.getItem(i)->move();
	}
}

void ListaEntidades::attackAll()
{
	int i;
	for (i = 0; i < Lista.getTamanho(); i++)
	{
		if (Lista.getItem(i)->getAttacker())
			Lista.getItem(i)->attack();
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