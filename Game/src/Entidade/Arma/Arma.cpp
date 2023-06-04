#include "pch.h"
#include "Entidade/Arma/Arma.h"

Arma::Arma()
{
}

Arma::~Arma()
{
}

bool Arma::getAttacker()
{
	return attacker;
}

void Arma::setAttacker()
{
	attacker = !attacker;
}

bool Arma::getDamageable() const
{
	return damageable;
}

bool Arma::getGhost() const
{
	return ghost;
}

bool Arma::getMovable() const
{
	return NULL;//movable;
}

bool Arma::getRetardant() const
{
	return retardant;
}