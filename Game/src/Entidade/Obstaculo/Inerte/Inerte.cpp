#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculo {
	namespace Inerte {
		Inerte::Inerte(sf::Vector2f pos, int id) : Obstaculo(pos, id)
		{
			movable = false;
			attacker = false;
			retarder = false;
			damageable = false;

			body.setFillColor(sf::Color::Green);
			body.setPosition(pos);
		}

		Inerte::~Inerte()
		{
		}
	}
}