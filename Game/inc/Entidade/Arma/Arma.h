#pragma once

#include "Entidade/Entidade.h"

class Arma : public Entidade
{
protected:
	bool attacker;
	
	static const bool damageable;
	static const bool ghost;
	static const bool movable;
	static const bool retardant;

public:
	Arma();
	virtual ~Arma();

	bool getAttacker() override;
	bool setAttacker() override;

	bool getDamageable() const override;
	bool getGhost() const override;
	bool getMovable() const override;
	bool getRetardant() const override;
};