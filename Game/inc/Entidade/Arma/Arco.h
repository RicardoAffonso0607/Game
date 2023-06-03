#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		const int damage;

		const sf::Time delay;

	public:
		Arco();
		~Arco();

		int getDamage() const override;

		sf::Time getDelay() const override;
	};
}