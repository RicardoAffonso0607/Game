#include "pch.h"
#include "Entidade/Arma/Arma.h"

namespace Armas {
	Arma::Arma() :
		attacker(false),
		damageable(false),
		ghost(true),
		movable(true),
		retardant(false)
	{
	}

	Arma::~Arma()
	{
	}

	bool getAttacker()
	{
		return attacker;
	}

	bool setAttacker()
	{
		attacker = !attacker;
	}

	bool getDamageable() const
	{
		return damageable;
	}

	bool getGhost() const
	{
		return ghost;
	}
	bool getMovable() const
	{
		return movable;
	}

	bool getRetardant() const
	{
		return retardant;
	}
}