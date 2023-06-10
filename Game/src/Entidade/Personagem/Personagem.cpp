#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

const bool Personagem::movable = true;// móvel
const bool Personagem::damageable = true;// danificável
const bool Personagem::ghost = false;// não é atravessável por objetos

Personagem::Personagem() :
	atacou(false),
	attacker(false),
	facing_left(false),
	vel(sf::Vector2f(0.f, 0.f)),
	attack_instant(sf::Time::Zero),
	relogio_zero(sf::Time::Zero),
	life(0),
	pColidiu(nullptr),
	colidiu(false)
{
	sf::Clock clock_ini;
	clock = clock_ini;
}

Personagem::~Personagem()
{
}

bool Personagem::getMovable() const
{
	return movable;
}

bool Personagem::getAttacker() const
{
	return attacker;
}

bool Personagem::getDamageable() const
{
	return damageable;
}

sf::Vector2f Personagem::getVel() const
{
	return vel;
}

void Personagem::applyDamage(int ent_damage)
{
	life -= ent_damage;
}

void Personagem::applySlowness(float ent_slowness)
{
	vel.x *= 1.f - ent_slowness;
}

bool Personagem::getFacingLeft() const
{ 
	return facing_left;
}

void Personagem::setAtacou()
{
}

int Personagem::getLife() const
{
	return life;
}

bool Personagem::getGhost() const
{
	return ghost;
}

void Personagem::setDireita()
{
	facing_left = false;
}

void Personagem::setEsquerda()
{
	facing_left = true;
}

bool Personagem::getJumped() const
{
	return jumped;
}

void Personagem::setEntColidiu(Entidade* pauxColidiu)
{
	pColidiu = pauxColidiu;
}

void Personagem::setColidiu()
{
	colidiu = true;
}

void Personagem::setClockZero(sf::Time aux_tempo)
{
	relogio_zero = aux_tempo;
}

sf::Time Personagem::getClock()
{
	return clock.getElapsedTime();
}