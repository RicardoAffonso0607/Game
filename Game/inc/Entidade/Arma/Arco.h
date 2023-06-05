#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		static const bool attacker;// ataca?

		static const unsigned int id;

	public:
		Arco(sf::Vector2f pos);
		~Arco();

		unsigned int getId() const override;// id?

		//void attack() override;// � atacante?
	};
}