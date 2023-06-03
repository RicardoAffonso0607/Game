#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Espada : public Arma
	{
	private:
		const int damage;

		const sf::Time delay;

	public:
		Espada();
		~Espada();

		int getDamage() const override;

		sf::Time getDelay() const override;
	};
}