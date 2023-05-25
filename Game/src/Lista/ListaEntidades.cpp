#include "pch.h"
#include "../../inc/Lista/ListaEntidades.h"

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
		Lista[i]->move();
	}
}

void ListaEntidades::drawAll()
{
	int i;
	for (i = 0; i < Lista.getTamanho(); i++)
	{
		Lista[i]->draw();
	}
}

