#include "pch.h"
#include "Entidade/Obstaculo/Danoso/ArmadilhaDeLancas.h"

namespace Obstaculos {
	namespace Danosos {
		const int ArmadilhaDeLancas::damage = 2;

		const int ArmadilhaDeLancas::id = 11;

		ArmadilhaDeLancas::ArmadilhaDeLancas(sf::Vector2f pos)
		{
			textura.loadFromFile(string(IMG) + "LancaPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(100.f, 100.f));
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