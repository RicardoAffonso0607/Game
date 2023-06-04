#pragma once

#include "Entidade/Entidade.h"

class Arma : public Entidade
{
protected:
	bool attacker = false;
	
	static const bool damageable = false;
	static const bool ghost = false;
	static const bool movable = true;
	static const bool retardant = false;

public:
	Arma();
	virtual ~Arma();

	bool getAttacker() /*override*/;
	void setAttacker() /*override*/;

	bool getDamageable() const /*override*/;
	bool getGhost() const /*override*/;
	bool getMovable() const /*override*/;
	bool getRetardant() const /*override*/;
};