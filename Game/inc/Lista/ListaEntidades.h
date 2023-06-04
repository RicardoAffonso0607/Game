#pragma once

#include "Lista/Lista.h"
#include "Entidade/Entidade.h"

class ListaEntidades
{
private:
	Lista<Entidade> Lista;

public:
	ListaEntidades();
	~ListaEntidades();

	int getSize() { return Lista.getTamanho(); }
	Entidade* getEntity(int pos) { return Lista.getItem(pos); }
	void push(Entidade* pE) { Lista.push(pE); }
	void pop(Entidade* pE) { Lista.pop(pE); }
	void clear() { Lista.clear(); }

	void attackAll();
	void moveAll();
	void drawAll();
};