#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	Inerte::Inerte()
	{
	}

	Inerte::~Inerte()
	{
	}

	bool Inerte::getAttacker() const
	{
		return attacker;
	}

	bool Inerte::getRetardant() const
	{
		return retardant;
	}
}