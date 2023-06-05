#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Plataforma/Areal.h"

namespace Obstaculos {
	namespace Inertes {
		namespace Plataformas {
			Areal::Areal(sf::Vector2f pos, sf::Vector2f size)
			{
				textura.loadFromFile(string(IMG) + "Areal.png");
				body.setTexture(&textura);
				body.setSize(size);
				body.setPosition(pos);
			}

			Areal::~Areal()
			{
			}

			unsigned int Areal::getId() const
			{
				return id;
			}
		}
	}
}