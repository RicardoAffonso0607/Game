#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	const bool CorpoACorpo::attacker = true;

	CorpoACorpo::CorpoACorpo()
	{
	}

	CorpoACorpo::~CorpoACorpo()
	{
	}

	void CorpoACorpo::move()
	{
		if (pPlayer->getPosition().y > body.getPosition().y - 3 * body.getSize().y && pPlayer->getPosition().y < body.getPosition().y + 4 * body.getSize().y)
		{
			if (pPlayer->getPosition().x < body.getPosition().x) {
				facing_left = true;
				pArma->setFacingLeft();
				body.move(sf::Vector2f(-vel.x, 0.f));
			}
			else if (pPlayer->getPosition().x > body.getPosition().x) {
				facing_left = false;
				pArma->unsetFacingLeft();
				body.move(sf::Vector2f(vel.x, 0.f));
			}
		}
	}

	void CorpoACorpo::attack()
	{
	}

	bool CorpoACorpo::getAttacker() const
	{
		return attacker;
	}
}