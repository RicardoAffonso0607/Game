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
		if(Lista.getItem(i) && Lista.getItem(i)->getMovable())
			Lista.getItem(i)->move();
		if (Lista.getItem(i) && Lista.getItem(i)->getDamageable() && Lista.getItem(i)->getLife() <= 0) {
			//if (((Lista.getItem(i)->getId() >= 1 && Lista.getItem(i)->getId()<=9)||(Lista.getItem(i)->getId() >= 61 && Lista.getItem(i)->getId()<=69)) && Lista.getItem(i)->getArma())
			//	pop(Lista.getItem(i)->getArma());
			pop(Lista.getItem(i));
		}
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