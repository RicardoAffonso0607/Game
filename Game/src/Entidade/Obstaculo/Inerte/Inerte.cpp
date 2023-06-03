#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	Inerte::Inerte() :
		retardant(false),
		attacker(false)
	{
	}

	Inerte::~Inerte()
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