#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	Danoso::Danoso() :
		attacker(true),
		retardant(false)
	{
	}

	Danoso::~Danoso()
	{
	}

	bool Retardante::getAttacker() const
	{
		return attacker;
	}

	bool Retardante::getRetardant() const
	{
		return retardant;
	}
}