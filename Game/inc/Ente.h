#pragma once
#include "Gerenciador/Grafico.h"

class Ente
{
protected:
	int id;
	static Gerenciador::Grafico* pGerGraf;
	sf::RectangleShape body;

public:
	Ente();
	~Ente();

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) { pGerGraf = pauxGerGraf; }
	void draw() { pGerGraf->desenhaElemento(body); }
};

