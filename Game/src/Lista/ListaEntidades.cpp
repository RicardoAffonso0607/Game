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
<<<<<<< HEAD
		if(Lista.getItem(i)->isMovable())
			Lista.getItem(i)->move();
=======
		Lista[i]->move();
>>>>>>> main
	}
}

void ListaEntidades::drawAll()
{
	int i;
	for (i = 0; i < Lista.getTamanho(); i++)
	{
<<<<<<< HEAD
		Lista.getItem(i)->draw();
	}
}
=======
		Lista[i]->draw();
	}
}

>>>>>>> main
