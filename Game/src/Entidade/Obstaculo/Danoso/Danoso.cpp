#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	const bool Danoso::attacker = true;
	const bool Danoso::retardant = false;

	Danoso::Danoso()
	{
	}

	Danoso::~Danoso()
	{
	}

	bool Danoso::getAttacker() const
	{
		return attacker;
	}

	bool Danoso::getRetardant() const
	{
		return retardant;
	}
}