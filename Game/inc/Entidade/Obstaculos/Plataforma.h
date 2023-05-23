#pragma once

#include "Entidade/Obstaculos/Obstacles.h"

class Plataforma : public Obstacles
{
private:

public:
	Plataforma(sf::Vector2f pos, int id);
	~Plataforma();
};

