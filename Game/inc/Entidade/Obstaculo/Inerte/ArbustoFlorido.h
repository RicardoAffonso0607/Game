#pragma once

#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	namespace Inertes {
		class ArbustoFlorido : public Inerte
		{
		private:
			static const int id;

		public:
			ArbustoFlorido(sf::Vector2f pos);
			~ArbustoFlorido();

			int getId() const override;
		};
	}
}