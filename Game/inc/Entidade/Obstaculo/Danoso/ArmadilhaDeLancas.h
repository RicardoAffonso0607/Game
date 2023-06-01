#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

class ArmadilhaDeLancas : public Danoso
{
private:

public:
	ArmadilhaDeLancas(sf::Vector2f pos, int id);
	~ArmadilhaDeLancas();
};