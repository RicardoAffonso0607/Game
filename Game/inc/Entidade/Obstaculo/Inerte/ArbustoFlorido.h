#pragma once

#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculo {
	namespace Inerte {
		class ArbustoFlorido : public Inerte
		{
		private:

		public:
			ArbustoFlorido(sf::Vector2f pos, int id);
			~ArbustoFlorido();
		};
	}
}