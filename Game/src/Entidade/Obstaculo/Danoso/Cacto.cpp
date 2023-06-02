#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Cacto.h"

namespace Obstaculos {
	namespace Danosos {
		Cacto::Cacto(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Cacto::~Cacto()
		{

		}
	}
}