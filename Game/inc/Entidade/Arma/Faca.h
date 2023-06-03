#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Faca : public Arma
	{
	private:
		const int damage;

		static const int id;

		const sf::Time delay;

	public:
		Faca();
		~Faca();

		int getDamage() const override;
		int getId() const override;

		sf::Time getDelay() const override;
	};
}