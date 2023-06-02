#pragma once

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

class Projetil : public Entidade
{
private:
	Inimigos::Disparador* caster;
	float damage;

public:
	Projetil();
	virtual ~Projetil();

	void setCaster(Inimigos::Disparador* pCaster) { caster = pCaster; }
	Inimigos::Disparador* getCaster() { return caster; }

	void move();
	void attack();
};