#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculo {
	namespace Danoso {
		class ArmadilhaDeLancas : public Danoso
		{
		private:

		public:
			ArmadilhaDeLancas(sf::Vector2f pos, int id);
			~ArmadilhaDeLancas();
		};
	}
}