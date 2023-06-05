#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

const bool Personagem::movable = true;// móvel
const bool Personagem::damageable = true;// danificável
const bool Personagem::ghost = false;// não é atravessável por objetos

Personagem::Personagem() :
	atacou(false),
	attacker(false),
	allow_jump(true),
	colidiu_baixo(false),
	colidiu_cima(false),
	flying(false),
	facing_left(false),
	jumped(false),
	jumped_height(0.f),
	vel(sf::Vector2f(0.f, 0.f)),
	attack_instant(sf::Time::Zero),
	life(0)
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