#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	const bool Retardante::attacker = false;
	const bool Retardante::retardant = true;

	Retardante::Retardante()
	{
	}

	Retardante::~Retardante()
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