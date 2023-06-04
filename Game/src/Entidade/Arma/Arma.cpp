#include "pch.h"
#include "Entidade/Arma/Arma.h"

Arma::Arma()
{
}

Arma::~Arma()
{
}

bool Arma::getAttacker() const
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
	return movable;
}

bool Arma::getRetardant() const
{
	return retardant;
}

void Arma::setFacingLeft()
{
	facing_left = true;
}

void Arma::unsetFacingLeft()
{
	facing_left = false;
}