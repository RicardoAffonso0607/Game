#pragma once

#include "Lista/Lista.h"
#include "Lista/Elemento.h"
#include "Entidade/Entidade.h"

class ListaEntidades
{
private:
	Lista<Entidade> Lista;

public:
	ListaEntidades();
	~ListaEntidades();
};

