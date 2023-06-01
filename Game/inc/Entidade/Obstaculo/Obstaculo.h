#pragma once

#include "Entidade/Entidade.h"

namespace Obstaculo {
	class Obstaculo : public Entidade
	{
	protected:

	public:
		Obstaculo(sf::Vector2f pos, int id);
		~Obstaculo();

		void move();
		void attack();
	};
}