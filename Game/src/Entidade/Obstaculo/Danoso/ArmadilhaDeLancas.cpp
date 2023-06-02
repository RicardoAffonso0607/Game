#include "pch.h"
#include "Entidade/Obstaculo/Danoso/ArmadilhaDeLancas.h"

namespace Obstaculos {
	namespace Danosos {
		ArmadilhaDeLancas::ArmadilhaDeLancas(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		ArmadilhaDeLancas::~ArmadilhaDeLancas()
		{

		}
	}
}