#include "pch.h"
#include "Entidade/Obstaculo/Obstaculo.h"

Obstaculo::Obstaculo() :
	mass(100.f),
	movable(false),
	ghost(false),
	damageable(false)
{
}

Obstaculo::~Obstaculo()
{
}

bool Obstaculo::getMovable()
{
	return movable;
}

bool Obstaculo::getGhost() const
{
	return ghost
}

bool Obstaculo::getDamageable() const
{
	return damageable;
}

float Obstaculo::getMass()
{
	return mass;
}