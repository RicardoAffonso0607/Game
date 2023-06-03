#pragma once

#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	namespace Danosos {
		class ArmadilhaDeLancas : public Danoso
		{
		private:
			const int damage;

			static const int id;

		public:
			ArmadilhaDeLancas(sf::Vector2f pos);
			~ArmadilhaDeLancas();

			int getDamage() const override;
			int getId() const override;
		};
	}
}