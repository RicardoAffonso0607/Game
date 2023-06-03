#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	Retardante::Retardante() :
		attacker(false)
		retardant(true)
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