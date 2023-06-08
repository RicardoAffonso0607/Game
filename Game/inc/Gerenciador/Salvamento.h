#pragma once
#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
	private:
ListaEntidades* list_ent;
multimap<unsigned int, vector> dados;

public:
Salvamento();
		~Salvamento();
static void save();
	};
}

