#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoSeco.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoSeco::ArbustoSeco(sf::Vector2f pos, int id) :
			size(Vector2f(100.f, 100.f))
		{
			body.setPosition(pos);
		}

		ArbustoSeco::~ArbustoSeco()
		{
		}
	}
}