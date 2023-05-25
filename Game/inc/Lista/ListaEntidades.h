#pragma once

#include "Lista.h"
#include "../Entidade/Entidade.h"

class ListaEntidades
{
private:
	Lista<Entidade> Lista;

public:
	ListaEntidades();
	~ListaEntidades();

	int getSize() { Lista.getTamanho(); }
	Entidade* getEntity(int pos) { Lista.getItem(pos); }
	void push(Entidade* pE) { Lista.push(pE); }
	void pop(Entidade* pE) { Lista.pop(pE); }

	void moveAll();
	void drawAll();
};

