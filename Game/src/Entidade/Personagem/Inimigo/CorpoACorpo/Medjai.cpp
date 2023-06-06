#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const float Medjai::mass = .5f;

		const unsigned int Medjai::id = 61;

		const sf::Vector2f Medjai::vel_max = sf::Vector2f(20.f, 15.f);

		Medjai::Medjai(sf::Vector2f pos)
		{
			life = 20;
			vel = vel_max;
			textura.loadFromFile(string(IMG) + "MedjaiPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(80.f, 150.f));
			body.setPosition(pos);
			pArma = new Armas::Faca(pos);
		}

		Medjai::~Medjai()
		{
			delete pArma;
		}

		unsigned int Medjai::getId() const
		{
			return id;
		}

		float Medjai::getMass() const
		{
			return mass;
		}
	}
}