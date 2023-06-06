#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoSeco.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoSeco::ArbustoSeco(sf::Vector2f pos)
		{
			textura.loadFromFile(string(IMG) + "ArbustoSeco.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(250.f, 250.f));
			body.setPosition(pos);
		}

		ArbustoSeco::~ArbustoSeco()
		{
		}

		unsigned int ArbustoSeco::getId() const
		{
			return id;
		}
	}
}