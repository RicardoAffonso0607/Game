#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	protected:
		Arma* pArma;

		static const bool retardable;

		float gun_pos = .8f;
		float attack_radius;
		float sensor_radius = 2000.f;

		sf::Time attack_delay = sf::milliseconds(500);
		sf::Time attack_instant = clock.getElapsedTime();

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();

		void move() override;

		void attack() override;

		bool getRetardable() const override;

		Entidade* getArma() const override;
	};
}