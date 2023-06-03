#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class AreiaMovedica : public Retardante
		{
		private:
			const float slowness;

			static const int id;

		public:
			AreiaMovedica(sf::Vector2f pos, sf::Vector2f size);
			~AreiaMovedica();

			float getSlowness() const override;

			int getId() const override;
		};
	}
}