#pragma once

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

class Projetil : public Entidade
{
private:
	Disparador* caster;
	float damage;

public:
	Projetil(sf::Vector2f pos, int id);
	~Projetil();

	void setCaster(Disparador* pCaster) { caster = pCaster; }
	Disparador* getCaster() { return caster; }

	void move();
	void attack();
};