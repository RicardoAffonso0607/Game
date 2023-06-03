#pragma once

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

class Projetil : public Entidade
{
private:
	Inimigo* pCaster;

	Arma* pArma;

	static const bool attacker;
	static const bool movable;
	static const bool damageable;
	static const bool ghost;
	
public:
	Projetil();
	virtual ~Projetil();

	void setCaster(Inimigo* caster);
	void setArma(Arma* gun);
};
