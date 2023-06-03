#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	Retardante::Retardante() :
		retardant(true),
		attacker(false)
	{
	}

	Retardante::~Retardante()
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