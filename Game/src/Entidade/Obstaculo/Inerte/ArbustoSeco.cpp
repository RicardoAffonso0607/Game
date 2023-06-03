#include "pch.h"
#include "Entidade/Obstaculo/Inerte/ArbustoSeco.h"

namespace Obstaculos {
	namespace Inertes {
		ArbustoSeco::ArbustoSeco(sf::Vector2f pos) :
			id(21),
			size(Vector2f(100.f, 100.f))
		{
			body.setPosition(pos);
		}

		ArbustoSeco::~ArbustoSeco()
		{
		}

		int ArbustoSeco::getId() const
		{
			return id;
		}
	}
}