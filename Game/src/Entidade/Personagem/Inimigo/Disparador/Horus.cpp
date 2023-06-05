#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"

namespace Inimigos {
	namespace Disparadores {
		const float Horus::mass = 1.f;

		const unsigned int Horus::id = 71;

		const sf::Vector2f Horus::vel_max = sf::Vector2f(20.f, 15.f);

		Horus::Horus(sf::Vector2f pos)
		{
			life = 100;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "MageDesertoPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(100.f, 180.f));
			body.setPosition(pos);
		}

		Horus::~Horus()
		{
		}

		unsigned int Horus::getId() const
		{
			return id;
		}

		float Horus::getMass() const
		{
			return mass;
		}
	}
}