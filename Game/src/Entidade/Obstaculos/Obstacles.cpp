#include "pch.h"
#include "Entidade/Obstaculos/Obstacles.h"

Obstacles::Obstacles(sf::Vector2f pos, int id) : Entidade(id)
{
	this->pos = pos;
}

Obstacles::~Obstacles()
{
}

void Obstacles::move()
{
}

void Obstacles::attack()
{
}