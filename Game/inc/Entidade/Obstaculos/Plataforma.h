#pragma once
#include "Obstacles.h"

class Plataforma : public Obstacles
{
private:

public:
	Plataforma(sf::Vector2f pos, int id);
	~Plataforma();
};

