#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoFlorido.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoFlorido::ArbustoFlorido(sf::Vector2f pos)
		{
			textura.loadFromFile(string(IMG) + "ArbustoFloridoPA.png");
			body.setTexture(&textura);
			body.setSize(sf::Vector2f(100.f, 100.f));
			body.setPosition(pos);
		}

		ArbustoFlorido::~ArbustoFlorido()
		{
		}

		unsigned int ArbustoFlorido::getId() const
		{
			return id;
		}
	}
}