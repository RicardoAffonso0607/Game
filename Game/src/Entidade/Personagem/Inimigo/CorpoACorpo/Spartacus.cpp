#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		const int Spartacus::life = 50;

		const unsigned int Spartacus::id = 62;

		Spartacus::Spartacus(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(80.f, 150.f));
			body.setPosition(pos);
			pArma = new Armas::Espada(pos, this);
		}

		Spartacus::~Spartacus()
		{
			delete pArma;
		}

		unsigned int Spartacus::getId() const
		{
			return id;
		}
	}
}