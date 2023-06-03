#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Cacto.h"

namespace Obstaculos {
	namespace Danosos {
		Cacto::Cacto(sf::Vector2f pos) :
			damage(1),
			id(10),
			size(Vector2f(50.f, 100.f))
		{
			body.setPosition(pos);
		}

		Cacto::~Cacto()
		{
		}

		int Cacto::getDamage() const
		{
			return damage;
		}

		int Cacto::getId() const
		{
			return id;
		}
	}
}