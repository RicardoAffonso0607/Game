#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		const int damage;

		static const int id;

		const sf::Time delay;

	public:
		Arco();
		~Arco();

		int getDamage() const override;
		int getId() const override;

		sf::Time getDelay() const override;
	};
}