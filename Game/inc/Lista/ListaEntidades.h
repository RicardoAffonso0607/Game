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

<<<<<<< HEAD
	int getSize() { return Lista.getTamanho(); }
	Entidade* getEntity(int pos) { return Lista.getItem(pos); }
	void push(Entidade* pE) { Lista.push(pE); }
	void pop(Entidade* pE) { Lista.pop(pE); }
=======
	int getSize() { Lista.getTamanho(); }
	Entidade* getEntity(int pos) { Lista.getItem(pos); }
	void push(Entidade* pE) { Lista.push(pE); }
	void pop(Entidade* pE) { Lista.pop(pE); }

	void moveAll();
	void drawAll();
};
>>>>>>> main

	void moveAll();
	void drawAll();

	/* lista da biblioteca */
	//list<Entidade*>::iterator *i;
	//void pushB(Entidade *ent) { list_ent.push_back(ent); }
	//void pushF(Entidade *ent) { list_ent.push_front(ent); }
	//void popB() { list_ent.pop_back(); }
	//void popF() { list_ent.pop_front(); }
	//void rem(Entidade *ent) { list_ent.erase(getPos(ent)); }
	//size_t getSize() { return list_ent.size(); }
	//list<Entidade*>::iterator getPos(Entidade* ent) { return find(list_ent.begin(), list_ent.end(), ent); }
	//Entidade* getInicio() { return list_ent.front(); }
	//Entidade* getFim() { return list_ent.back(); }
	//list<Entidade*> getList() { return list_ent; }
};