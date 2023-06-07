
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
	body.setOrigin(body.getSize().x, 0.f);
	body.setScale(-1.f, 1.f);
}

void Arma::setDireita()
{
	facing_left = false;
	body.setOrigin(0.f, 0.f);
	body.setScale(1.f, 1.f);
}

void Arma::move()
{

}

void Arma::setEntColidiu(Entidade* pauxColidiu)
{
	pColidiu = pauxColidiu;
}

void Arma::setColidiu()
{
	colidiu = true;
}

bool Arma::getRetardant() const
{
	return retardant;
}