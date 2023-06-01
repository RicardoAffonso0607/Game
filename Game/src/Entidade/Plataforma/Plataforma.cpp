#include "pch.h"
#include "Entidade/Plataforma/Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, int id) : Entidade(id)
{
	movable = false;
	attacker = false;
	retarder = false;
	damageable = false;
	body.setSize(sf::Vector2f(600.0f, 20.0f));
	body.setFillColor(sf::Color::Yellow);
	body.setPosition(pos);
}

Plataforma::~Plataforma()
{

}

void Plataforma::move()
{
}

void Plataforma::attack()
{
}
