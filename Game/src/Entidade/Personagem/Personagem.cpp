#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

Personagem::Personagem()
{
	sf::Clock clock_ini;
	clock = clock_ini;
}

Personagem::~Personagem()
{
}

//void Personagem::getGunType()
//{
//	return gun_type;
//}

sf::Vector2f Personagem::getPosition()
{
	return body.getPosition();
}

sf::Vector2f Personagem::getEntSize()
{
	return body.getSize();
}

sf::Vector2f Personagem::getVel()
{
	return vel; 
}

sf::Vector2f Personagem::getVelMax()
{ 
	return vel_max;
}

void Personagem::changePosition(sf::Vector2f dif_pos)
{ 
	body.move(dif_pos); 
}

void Personagem::subtractLife(float damaged)
{ 
	life -= damaged; 
}

void Personagem::subtractVelocity(float retarded)
{ 
	vel.x -= retarded; 
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

//bool Personagem::getFacingLeft()
//{ 
//	return facingLeft; 
//}

//bool Personagem::getProjetil()
//{ 
//	return projected; 
//}

int Personagem::getDamage()
{ 
	return damage; 
}

float Personagem::getMass()
{ 
	return mass; 
}

void Personagem::setAtacou()
{
	atacou = true;
}

void Personagem::events()
{
	if (atacou)
		attacker = false;
	if (clock.getElapsedTime() - attack_delay > attack_instant) {
		attack_delay = sf::Time::Zero;
		atacou = false;
	}
}