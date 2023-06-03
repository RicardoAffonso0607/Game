#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	Danoso::Danoso() :
		retardant(false),
		attacker(true)
	{
	}

	Danoso::~Danoso()
	{
	}

	bool Retardante::getRetardant() const
	{
		return retardant;
	}

	bool Retardante::getAttacker() const
	{
		return attacker;
	}
}