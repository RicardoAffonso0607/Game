#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculo {
	namespace Retardante {
		Retardante::Retardante(sf::Vector2f pos, int id) : Obstaculo(pos, id), slowness(3)
		{
			movable = false;
			attacker = false;
			retarder = true;
			damageable = false;
		}

		Retardante::~Retardante()
		{
		}
	}
}