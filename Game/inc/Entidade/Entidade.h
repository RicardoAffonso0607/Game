#pragma once
#include "../Ente.h"
#include "../Gerenciador/Grafico.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape body;
	static Gerenciador::Grafico* pGerGraf;

public:
	Entidade(int id);
	~Entidade();

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) {pGerGraf = pauxGerGraf; }

	void draw() {pGerGraf->desenhaElemento(body); }
	virtual void move() = 0;
	virtual void attack() = 0;
};

