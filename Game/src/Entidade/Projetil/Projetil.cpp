#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

const bool Projetil::attacker = true;// causa dano?
const bool Projetil::movable = true;// é móvel?
const bool Projetil::damageable = false;// é danificável?
const bool Projetil::ghost = true;// atravessa objetos?

const sf::Vector2f Projetil::vel = sf::Vector2f(100.f, 0.f);// velocidade

const float Projetil::mass = .01f;// massa

Projetil::Projetil():
	colidiu(false),
	pColidiu(nullptr),
	facing_left(false)
{
}

Projetil::~Projetil()
{
}

bool Projetil::getAttacker() const
{
	return attacker;
}

bool Projetil::getDamageable() const
{
	return damageable;
}

bool Projetil::getGhost() const
{
	return ghost;
}

bool Projetil::getMovable() const
{
	return movable;
}

void Projetil::setEsquerda()
{
	facing_left = true;
}

void Projetil::setDireita()
{
	facing_left = false;
}

void Projetil::move()
{
	if (facing_left)
		body.move(sf::Vector2f(-vel.x, 0.f));
	else
		body.move(sf::Vector2f(vel.x, 0.f));
}