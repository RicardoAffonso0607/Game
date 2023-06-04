#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class Cacto : public Danoso
		{
		private:
			static const int damage;
			
			static const int id;

		public:
			Cacto(sf::Vector2f pos);
			~Cacto();

			int getDamage() const override;

			unsigned int getId() const override;
		};
	}
}