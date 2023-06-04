#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

const bool Personagem::movable = true;
const bool Personagem::damageable = true;
const bool Personagem::retardant = false;
const bool Personagem::ghost = false;

Personagem::Personagem() :
	atacou(false),
	attacker(false),
	facing_left(true),
	vel(sf::Vector2f(NULL, NULL)),
	attack_instant(sf::Time::Zero),
	life(NULL)
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

bool Personagem::getRetardant() const
{
	return retardant;
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
	return facingLeft; 
}

void Personagem::setAtacou()
{
	atacou = !atacou;
}

int Personagem::getLife() const
{
	return life;
}

bool Personagem::getGhost() const
{
	return ghost;
}

//void Personagem::getGunType()
//{
//	return gun_type;
//}

//void Personagem::events()
//{
//	if (atacou)
//		attacker = false;
//	if (clock.getElapsedTime() - attack_delay > attack_instant) {
//		attack_delay = sf::Time::Zero;
//		atacou = false;
//	}
//}