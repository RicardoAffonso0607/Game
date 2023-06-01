#pragma once

#include "Entidade/Obstaculo/Inerte/Inerte.h"

class ArbustoSeco : public Inerte
{
private:

public:
	ArbustoSeco(sf::Vector2f pos, int id);
	~ArbustoSeco();
};