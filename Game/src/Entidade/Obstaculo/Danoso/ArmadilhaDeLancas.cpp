#include "pch.h"
#include "Entidade/Obstaculo/Danoso/ArmadilhaDeLancas.h"

namespace Obstaculos {
	namespace Danosos {
		ArmadilhaDeLancas::ArmadilhaDeLancas(sf::Vector2f pos) :
			damage(2),
			id(11),
			size(Vector2f(100.f,100.f))
		{
			body.setPosition(pos);
		}

		ArmadilhaDeLancas::~ArmadilhaDeLancas()
		{
		}

		int ArmadilhaDeLancas::getDamage() const
		{
			return damage;
		}

		unsigned int ArmadilhaDeLancas::getId() const
		{
			return id;
		}
	}
}