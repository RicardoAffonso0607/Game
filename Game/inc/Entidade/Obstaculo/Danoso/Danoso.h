#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculo {
	namespace Danoso {
		class Danoso : public Obstaculo
		{
		private:
			int damage;

		public:
			Danoso(sf::Vector2f pos, int id);
			~Danoso();
		};
	}
}