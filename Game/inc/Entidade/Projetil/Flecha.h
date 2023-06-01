#pragma once

#include "Entidade/Projetil/Projetil.h"

class Flecha : public Projetil
{
private:

public:
	Flecha(sf::Vector2f pos, int id);
	~Flecha();
};

