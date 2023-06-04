#pragma once

#include "Entidade/Entidade.h"

class Projetil : public Entidade
{
protected:
	static const bool attacker = true;
	static const bool movable = true;
	static const bool damageable = false;
	static const bool ghost = false;

	bool facing_left;
	
public:
	Projetil();
	virtual ~Projetil();

	void setFacingLeft() override;
	void unsetFacingLeft() override;
};
