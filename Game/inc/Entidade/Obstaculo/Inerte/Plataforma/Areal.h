#pragma once

#include "Entidade/Obstaculo/Inerte/Plataforma/Plataforma.h"

namespace Obstaculos {
	namespace Inertes {
		namespace Plataformas {
			class Areal : public Plataforma
			{
			private:
				static const int id = 41;

			public:
				Areal(sf::Vector2f pos, sf::Vector2f size);
				~Areal();

				unsigned int getId() const override;
			};
		}
	}
}