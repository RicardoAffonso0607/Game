#include "pch.h"
#include "Entidade/Obstaculo/Obstaculo.h"

Obstaculo::Obstaculo() :
	damageable(false),
	ghost(false),
	movable(false),
	mass(100.f)
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
	return ghost
}

bool Obstaculo::getMovable()
{
	return movable;
}

float Obstaculo::getMass()
{
	return mass;
}