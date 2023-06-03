#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class Lama : public Retardante
		{
		private:
			const float slowness;

		public:
			Lama(sf::Vector2f pos, sf::Vector2f size, int id);
			~Lama();

			float getSlowness() const override;
		};
	}
}