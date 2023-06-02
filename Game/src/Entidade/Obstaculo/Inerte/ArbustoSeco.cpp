#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoSeco.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoSeco::ArbustoSeco(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		ArbustoSeco::~ArbustoSeco()
		{

		}
	}
}