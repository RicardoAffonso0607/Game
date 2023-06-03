#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Espada : public Arma
	{
	private:
		const int damage;

		static const int id;

		const sf::Time delay;

	public:
		Espada();
		~Espada();

		int getDamage() const override;

		unsigned int getId() const override;

		sf::Time getDelay() const override;
	};
}