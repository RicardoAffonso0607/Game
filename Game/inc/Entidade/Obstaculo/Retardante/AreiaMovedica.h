#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class AreiaMovedica : public Retardante
		{
		private:
			const float slowness;

		public:
			AreiaMovedica(sf::Vector2f pos, sf::Vector2f size, int id);
			~AreiaMovedica();

			float getSlowness() const override;
		};
	}
}