#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	const bool Disparador::retardable = false;

	Disparador::Disparador() :
		pProjetil(nullptr)
	{
	}

	Disparador::~Disparador()
	{
	}

	void Disparador::move()
	{
		if (pPlayer->getPosition().y > body.getPosition().y - 3 * body.getSize().y && pPlayer->getPosition().y < body.getPosition().y + 4 * body.getSize().y)
		{
			if (pPlayer->getPosition().x < body.getPosition().x) {
				facing_left = true;
				pProjetil->setFacingLeft();
				body.move(sf::Vector2f(-vel.x, 0.f));
			}
			else if (pPlayer->getPosition().x > body.getPosition().x) {
				facing_left = false;
				pProjetil->unsetFacingLeft();
				body.move(sf::Vector2f(vel.x, 0.f));
			}
		}
	}

	void Disparador::attack()
	{
	}

	bool Disparador::getRetardable() const
	{
		return retardable;
	}
}