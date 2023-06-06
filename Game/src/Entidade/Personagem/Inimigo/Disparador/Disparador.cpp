#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	const bool Disparador::retardable = false;// é retardável?

	const float Disparador::action_radius = 1000.f;// raio de ação
	const float Disparador::cast_height = .4f;// altura do disparo

	const sf::Time Disparador::attack_delay = sf::milliseconds(2000);// cooldown entre ataques

	Disparador::Disparador() :
		pProjetil(nullptr)
	{
	}

	Disparador::~Disparador()
	{
	}

	bool Disparador::getRetardable() const
	{
		return retardable;
	}

	void Disparador::move()
	{
		if (pPlayer && !pPlayer->getGodMode() && pPlayer->getPos().y > body.getPosition().y - action_radius && pPlayer->getPos().y < body.getPosition().y + action_radius)
		{
			if (pPlayer->getPos().x < body.getPosition().x) {
				facing_left = true;
				if (pPlayer->getPos().x + pPlayer->getEntSize().x < body.getPosition().x - action_radius)
					body.move(sf::Vector2f(-vel.x, 0.f));
			}
			else if (pPlayer->getPos().x > body.getPosition().x) {
				facing_left = false;
				if (pPlayer->getPos().x + pPlayer->getEntSize().x > body.getPosition().x + action_radius)
					body.move(sf::Vector2f(vel.x, 0.f));
			}
			if (fabs(pPlayer->getPos().x - body.getPosition().x) < action_radius)
				if (clock.getElapsedTime() - attack_delay > attack_instant) {
					attack();
					attack_instant = clock.getElapsedTime();
				}
		}
	}
}
