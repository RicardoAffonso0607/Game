#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculo {
	namespace Retardante {
		class Retardante : public Obstaculo
		{
		private:
			int slowness;

		public:
			Retardante(sf::Vector2f pos, int id);
			~Retardante();
		};
	}
}