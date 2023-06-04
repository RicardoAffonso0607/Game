#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Cacto.h"

namespace Obstaculos {
	namespace Danosos {
		Cacto::Cacto(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(50.f, 100.f));
			body.setPosition(pos);
		}

		Cacto::~Cacto()
		{
		}

		int Cacto::getDamage() const
		{
			return damage;
		}

		unsigned int Cacto::getId() const
		{
			return id;
		}
	}
}