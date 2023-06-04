#include "pch.h"
#include "Entidade/Obstaculo/Obstaculo.h"

const bool Obstaculo::damageable = false;
const bool Obstaculo::ghost = false;
const bool Obstaculo::movable = false;

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