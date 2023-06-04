#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class ArmadilhaDeLancas : public Danoso
		{
		private:
			const int damage = 2;

			static const int id = 11;

		public:
			ArmadilhaDeLancas(sf::Vector2f pos);
			~ArmadilhaDeLancas();

			int getDamage() const /*override*/;

			unsigned int getId() const override;
		};
	}
}