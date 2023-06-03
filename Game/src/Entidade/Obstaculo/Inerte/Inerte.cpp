#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	Inerte::Inerte() :
		attacker(false),
		retardant(false)
	{
	}

	Inerte::~Inerte()
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