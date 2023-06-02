#pragma once

#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	namespace Inertes {
		class ArbustoFlorido : public Inerte
		{
		private:

		public:
			ArbustoFlorido(sf::Vector2f pos, int id);
			~ArbustoFlorido();
		};
	}
}