#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class Cacto : public Danoso
		{
		private:
			const int damage;

		public:
			Cacto(sf::Vector2f pos, int id);
			~Cacto();

			int getDamage() const override;
		};
	}
}