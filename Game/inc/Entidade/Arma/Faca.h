#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Faca : public Arma
	{
	private:
		const int damage;

		const sf::Time delay;

	public:
		Faca();
		~Faca();

		int getDamage() const override;

		sf::Time getDelay() const override;
	};
}