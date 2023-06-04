#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	const bool Chefao::retardable = false;

	Chefao::Chefao() :
		pProjetil(nullptr)
	{
	}

	Chefao::~Chefao()
	{
	}

	void Chefao::move()
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

	void Chefao::attack()
	{
	}

	bool Chefao::getRetardable() const
	{
		return retardable;
	}
}
