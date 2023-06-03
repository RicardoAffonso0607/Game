#pragma once

#include "Entidade/Entidade.h"

class Projetil : public Entidade
{
protected:
	static const bool attacker;
	static const bool movable;
	static const bool damageable;
	static const bool ghost;
	
public:
	Projetil();
	virtual ~Projetil();
};
