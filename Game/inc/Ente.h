#pragma once

#include "Gerenciador/Grafico.h"

/* Lista de IDs

*/

class Ente
{
protected:
	static Gerenciador::Grafico* pGerGraf;

public:
	Ente();
	Ente(int id);
	virtual ~Ente();

	virtual unsigned int getId() const = 0;

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) { pGerGraf = pauxGerGraf; }
};