#pragma once

#include "Entidade/Obstaculo/Inerte/Plataforma/Plataforma.h"

namespace Obstaculos {
	namespace Inertes {
		namespace Plataformas {
			class Gramado : public Plataforma
			{
			private:
				static const int id = 42;

			public:
				Gramado(sf::Vector2f pos, sf::Vector2f size);
				~Gramado();

				unsigned int getId() const override;
			};
		}
	}
}