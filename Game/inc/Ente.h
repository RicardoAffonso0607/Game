#pragma once

#include "Gerenciador/Grafico.h"

class Ente
{
protected:
	int id;
	sf::RectangleShape body;
	static Gerenciador::Grafico* pGerGraf;

public:
	Ente();
	~Ente();
	int getId() { return id; }

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) { pGerGraf = pauxGerGraf; }
	void draw() { pGerGraf->desenhaElemento(body); }
};

