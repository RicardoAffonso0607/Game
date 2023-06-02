#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoFlorido.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoFlorido::ArbustoFlorido(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		ArbustoFlorido::~ArbustoFlorido()
		{

		}
	}
}