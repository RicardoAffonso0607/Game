#include "pch.h"
#include "Entidade/Obstaculo/Obstaculo.h"

Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

bool Obstaculo::getDamageable() const
{
	return damageable;
}

bool Obstaculo::getGhost() const
{
	return ghost;
}

bool Obstaculo::getMovable() const
{
	return movable;
}