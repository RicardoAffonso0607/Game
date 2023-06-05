#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"

namespace Inimigos {
	namespace Chefoes {
		const float Nidogue::mass = 1.5f;

		const unsigned int Nidogue::id = 52;

		const sf::Vector2f Nidogue::vel_max = sf::Vector2f(5.f, 15.f);

		Nidogue::Nidogue(sf::Vector2f pos)
		{
			life = 200;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "DragaoFlorestaPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(300.f, 180.f));
			body.setPosition(pos);
		}

		Nidogue::~Nidogue()
		{
		}

		unsigned int Nidogue::getId() const
		{
			return id;
		}

		float Nidogue::getMass() const
		{
			return mass;
		}
	}
}