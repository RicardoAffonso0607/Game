#include "pch.h"
#include "Entidade/Plataforma/Plataforma.h"

Plataforma::Plataforma()
{
	body.setSize(sf::Vector2f(600.0f, 20.0f));
	body.setFillColor(sf::Color::Yellow);

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