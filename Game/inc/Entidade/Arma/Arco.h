#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		const int damage = 1;

		static const int id = 91;

		//static sf::Time delay = sf::milliseconds(400);

	public:
		Arco();
		~Arco();

		int getDamage() const /*override*/;

		unsigned int getId() const override;

		sf::Time getDelay() const /*override*/;
	};
}