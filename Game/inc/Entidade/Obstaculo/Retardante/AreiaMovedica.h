#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class AreiaMovedica : public Retardante
		{
		private:

		public:
			AreiaMovedica(sf::Vector2f pos, int id);
			~AreiaMovedica();
		};
	}
}