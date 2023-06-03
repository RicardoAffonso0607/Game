#include "pch.h"
#include "Entidade/Personagem/Personagem.h"

Personagem::Personagem() :
	attack_timer(sf::Time::Zero),
	movable(true),
	retarder(false),
	damageable(true),
	projected(false),
	colidiu_baixo(false),
	colidiu_cima(false),
	flying(false),
	atacou(false),
	facing_left(false)
{
	sf::Clock clock_ini;
	clock = clock_ini;
}

Personagem::~Personagem()
{
}

void Personagem::getGunType()
{
	return gun_type;
}

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

bool Personagem::getMovable()
{ 
	return movable; 
}

bool Personagem::getAttacker()
{ 
	return attacker; 
}

bool Personagem::getRetarder()
{ 
	return retarder; 
}

bool Personagem::getDamageable()
{ 
	return damageable; 
}

bool Personagem::getFacingLeft()
{ 
	return facingLeft; 
}

bool Personagem::getProjetil()
{ 
	return projected; 
}

float Personagem::getDamage()
{ 
	return damage; 
}

float Personagem::getMass()
{ 
	return mass; 
}

float Personagem::setAtacou()
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