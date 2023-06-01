#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

class Danoso : public Obstaculo
{
private:
	int damage;

public:
	Danoso(sf::Vector2f pos, int id);
	~Danoso();
};