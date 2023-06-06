#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	const bool CorpoACorpo::retardable = true;

	CorpoACorpo::CorpoACorpo() :
		pArma(nullptr)
	{
	}

	CorpoACorpo::~CorpoACorpo()
	{
	}

	void CorpoACorpo::move()
	{
		if (pPlayer && !pPlayer->getGodMode() && pPlayer->getPos().y > body.getPosition().y - 3 * body.getSize().y && pPlayer->getPos().y < body.getPosition().y + 4 * body.getSize().y)
		{
			if (pPlayer->getPos().x < body.getPosition().x) {
				facing_left = true;
				pArma->setEsquerda();
				body.move(sf::Vector2f(-vel.x, 0.f));
			}
			else if (pPlayer->getPos().x > body.getPosition().x) {
				facing_left = false;
				pArma->setDireita();
				body.move(sf::Vector2f(vel.x, 0.f));
			}
		}
		*/
	}

	void CorpoACorpo::attack()
	{
	}

	bool CorpoACorpo::getRetardable() const
	{
		return retardable;
	}

	Entidade* CorpoACorpo::getArma() const
	{
		return pArma;
	}
}