#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculo {
	namespace Danoso {
		class Cacto : public Danoso
		{
		private:

		public:
			Cacto(sf::Vector2f pos, int id);
			~Cacto();
		};
	}
}