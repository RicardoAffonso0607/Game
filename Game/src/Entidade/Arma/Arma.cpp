
#include "pch.h"
#include "Entidade/Arma/Arma.h"

const bool Arma::damageable = false;// danific�vel?
const bool Arma::ghost = true;// atravessa objetos?
const bool Arma::movable = true;// � m�vel?

Arma::Arma() :
	facing_left(false)
{
}

Arma::~Arma()
{
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

void Arma::setEsquerda()
{
	facing_left = true;
}

void Arma::setDireita()
{
	facing_left = false;
}