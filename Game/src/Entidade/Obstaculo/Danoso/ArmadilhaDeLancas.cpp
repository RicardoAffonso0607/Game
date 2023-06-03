#include "pch.h"
#include "Entidade/Obstaculo/Danoso/ArmadilhaDeLancas.h"

namespace Obstaculos {
	namespace Danosos {
		ArmadilhaDeLancas::ArmadilhaDeLancas(sf::Vector2f pos, int id) :
			damage(2),
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
	}
}