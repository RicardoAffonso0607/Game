#pragma once

#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	namespace Inertes {
		class ArbustoSeco : public Inerte
		{
		private:

		public:
			ArbustoSeco(sf::Vector2f pos, int id);
			~ArbustoSeco();
		};
	}
}