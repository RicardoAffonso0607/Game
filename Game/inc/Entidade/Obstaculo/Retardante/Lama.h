#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculo {
	namespace Retardante {
		class Lama : public Retardante
		{
		private:

		public:
			Lama(sf::Vector2f pos, int id);
			~Lama();
		};
	}
}