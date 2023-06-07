#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	const bool CorpoACorpo::retardable = true;

	CorpoACorpo::CorpoACorpo() :
		pArma(nullptr),
		attack_radius(0)
	{
		
	}

	CorpoACorpo::~CorpoACorpo()
	{
	}

	void CorpoACorpo::move()
	{
		if (pPlayer && !pPlayer->getGodMode() && pPlayer->getPos().y > body.getPosition().y - sensor_radius && pPlayer->getPos().y < body.getPosition().y + body.getSize().y + sensor_radius)
		{
			if (pPlayer->getPos().x < body.getPosition().x) {
				facing_left = true;
				body.move(sf::Vector2f(-vel.x, 0.f));
			}
			else if (pPlayer->getPos().x > body.getPosition().x) {
				facing_left = false;
				body.move(sf::Vector2f(vel.x, 0.f));
			}
		}
		if (facing_left) {
			pArma->setEsquerda();
			pArma->setEntPos(body.getPosition() + sf::Vector2f(-pArma->getEntSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
		}
		else {
			pArma->setDireita();
			pArma->setEntPos(body.getPosition() + sf::Vector2f(body.getSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
		}
		pArma->resetRot();
		if (fabs(pPlayer->getPos().x - body.getPosition().x-.5f*body.getSize().x) <= attack_radius && fabs(pPlayer->getPos().y - body.getPosition().y - .5f * body.getSize().y) <= attack_radius)
			attack();
	}

	void CorpoACorpo::attack()
	{
		if (clock.getElapsedTime() - attack_delay > attack_instant) {
			pArma->attack();
			attack_instant = clock.getElapsedTime();
		}
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