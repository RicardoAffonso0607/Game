#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"

namespace Inimigos {
	namespace Disparadores {
		const float Merlin::mass = 1.f;

		const unsigned int Merlin::id = 72;

		const sf::Vector2f Merlin::vel_max = sf::Vector2f(20.f, 15.f);

		Merlin::Merlin(sf::Vector2f pos)
		{
			life = 80;
			vel = vel_max;
			body.setSize(sf::Vector2f(100.f, 180.f));
			body.setPosition(pos);
		}

		Merlin::~Merlin()
		{
		}

		unsigned int Merlin::getId() const
		{
			return id;
		}

		float Merlin::getMass() const
		{
			return mass;
		}
	}
}