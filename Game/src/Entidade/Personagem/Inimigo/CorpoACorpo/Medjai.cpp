#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const int Medjai::life = 20;

		const unsigned int Medjai::id = 61;

		Medjai::Medjai(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(80.f, 150.f));
			body.setPosition(pos);
			pArma = new Armas::Faca(pos, this);
		}

		Medjai::~Medjai()
		{
			delete pArma;
		}

		unsigned int Medjai::getId() const
		{
			return id;
		}
	}
}