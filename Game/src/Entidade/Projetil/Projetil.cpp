#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

const bool Projetil::attacker = true;// causa dano?
const bool Projetil::movable = true;// é móvel?
const bool Projetil::damageable = true;// é danificável?
const bool Projetil::ghost = true;// atravessa objetos?

const sf::Vector2f Projetil::vel = sf::Vector2f(60.f, 0.f);// velocidade

const float Projetil::mass = .3f;// massa

Projetil::Projetil() :
	colidiu(false),
	pColidiu(nullptr),
	facing_left(false),
	life(1)
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

int Projetil::getLife() const
{
	return life;
}

void Projetil::setEsquerda()
{
	facing_left = true;
}

void Projetil::setDireita()
{
	facing_left = false;
}

void Projetil::setEntColidiu(Entidade* pauxColidiu)
{
	pColidiu = pauxColidiu;
}

void Projetil::setColidiu()
{
	colidiu = true;
}

void Projetil::applyDamage(int ent_damage)
{
}

void Projetil::move()
{
	if (facing_left)
		body.move(sf::Vector2f(-vel.x, 0.f));
	else
		body.move(sf::Vector2f(vel.x, 0.f));
	if (colidiu) {
		attack();
		pColidiu = nullptr;
		sfx.setPosition(sf::Vector3f(body.getPosition().x, 0.f, body.getPosition().y));
		sfx.play();
		life = 0;
	}
}