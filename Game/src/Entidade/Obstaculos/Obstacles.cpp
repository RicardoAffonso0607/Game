#include "pch.h"
#include "../../../inc/Entidade/Obstaculos/Obstacles.h"

Obstacles::Obstacles(sf::Vector2f pos, int id) : Entidade(id)
{
	this->pos = pos;
}

Obstacles::~Obstacles()
{
}
