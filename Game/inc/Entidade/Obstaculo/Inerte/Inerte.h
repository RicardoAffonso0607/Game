#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculo {
	namespace Inerte {
		class Inerte : public Obstaculo
		{
		private:

		public:
			Inerte(sf::Vector2f pos, int id);
			~Inerte();
		};
	}
}