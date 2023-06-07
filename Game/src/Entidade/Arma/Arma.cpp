
#include "pch.h"
#include "Entidade/Arma/Arma.h"

const bool Arma::damageable = false;// danificável?
const bool Arma::ghost = true;// atravessa objetos?
const bool Arma::movable = false;// é móvel?
const bool Arma::retardant = false;// é retardante?

Arma::Arma() :
	facing_left(false),
	pColidiu(nullptr)
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

void Arma::move()
{

}

void Arma::setEntColidiu(Entidade* pauxColidiu)
{
	this->pColidiu = pauxColidiu;
}

void Arma::setColidiu()
{
	this->colidiu = true;
}

bool Arma::getRetardant() const
{
	return retardant;
}