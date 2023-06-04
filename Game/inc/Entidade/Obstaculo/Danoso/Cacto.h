#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class Cacto : public Danoso
		{
		private:
			const int damage = 1;
			
			static const int id = 10;

		public:
			Cacto(sf::Vector2f pos);
			~Cacto();

			int getDamage() const /*override*/;

			unsigned int getId() const override;
		};
	}
}