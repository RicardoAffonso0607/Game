#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class ArmadilhaDeLancas : public Danoso
		{
		private:

		public:
			ArmadilhaDeLancas(sf::Vector2f pos, int id);
			~ArmadilhaDeLancas();
		};
	}
}