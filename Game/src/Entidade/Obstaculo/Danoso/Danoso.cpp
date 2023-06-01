#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculo {
	namespace Danoso {
		Danoso::Danoso(sf::Vector2f pos, int id) : Obstaculo(pos, id), damage(1)
		{
			movable = false;
			attacker = true;
			retarder = false;
			damageable = false;
		}

		Danoso::~Danoso()
		{
		}
	}
}