#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const float Spartacus::mass = .5f;

		const unsigned int Spartacus::id = 62;

		const sf::Vector2f Spartacus::vel_max = sf::Vector2f(5.f, 15.f);

		Spartacus::Spartacus(sf::Vector2f pos)
		{
			life = 50;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "Spartacus.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(250.f, 300.f));
			body.setPosition(pos);
			pArma = new Armas::Espada(pos);
		}

		Spartacus::~Spartacus()
		{
			delete pArma;
		}

		unsigned int Spartacus::getId() const
		{
			return id;
		}

		float Spartacus::getMass() const
		{
			return mass;
		}
	}
}