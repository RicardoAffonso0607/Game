#pragma once

#include "Lista.h"
#include "Elemento.h"
#include "Entidade.h"

class Lista_Entidades
{
private:
	Lista<Entidade> Lista;

public:
	Lista_Entidades();
	~Lista_Entidades();
};

