#pragma once

#include "Entidade/Projetil/Projetil.h"

class EsferaDeGelo : public Projetil
{
private:

public:
	EsferaDeGelo(sf::Vector2f pos, int id);
	~EsferaDeGelo();
};

