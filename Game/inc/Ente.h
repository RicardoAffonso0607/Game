#pragma once

#include "Gerenciador/Grafico.h"

/* Lista de IDs

*/

class Ente
{
protected:
	unsigned int id;
	
	static Gerenciador::Grafico* pGerGraf;

public:
	Ente();
	Ente(int id);
	virtual ~Ente();

	unsigned int getId() { return id; }

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) { pGerGraf = pauxGerGraf; }
};