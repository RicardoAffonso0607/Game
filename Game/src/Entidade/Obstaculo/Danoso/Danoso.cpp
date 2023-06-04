#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
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