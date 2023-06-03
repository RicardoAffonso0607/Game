#pragma once

#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	namespace Retardantes {
		class Lama : public Retardante
		{
		private:
			const float slowness;

			static const int id;

		public:
			Lama(sf::Vector2f pos, sf::Vector2f size);
			~Lama();

			float getSlowness() const override;

			int getId() const override;
		};
	}
}