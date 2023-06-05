#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"

namespace Inimigos {
	namespace Chefoes {
		const float Apofis::mass = 1.5f;

		const unsigned int Apofis::id = 51;

		const sf::Vector2f Apofis::vel_max = sf::Vector2f(5.f, 15.f);

		Apofis::Apofis(sf::Vector2f pos)
		{
			life = 100;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "DragaoDesertoPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(300.f, 180.f));
			body.setPosition(pos);
		}

		Apofis::~Apofis()
		{
		}

		unsigned int Apofis::getId() const
		{
			return id;
		}

		float Apofis::getMass() const
		{
			return mass;
		}
	}
}