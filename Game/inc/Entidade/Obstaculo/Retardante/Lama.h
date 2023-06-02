#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class Lama : public Retardante
		{
		private:

		public:
			Lama(sf::Vector2f pos, int id);
			~Lama();
		};
	}
}