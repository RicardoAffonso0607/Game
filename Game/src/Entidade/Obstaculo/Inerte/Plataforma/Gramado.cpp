#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Plataforma/Gramado.h"

namespace Obstaculos {
	namespace Inertes {
		namespace Plataformas {
			Gramado::Gramado(sf::Vector2f pos, sf::Vector2f size) :
				id(42)
			{
				body.setSize(size);
				body.setPosition(pos);
			}

			Gramado::~Gramado()
			{
			}

			unsigned int Gramado::getId() const
			{
				return id;
			}
		}
	}
}