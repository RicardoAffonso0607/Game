#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Lama.h"

namespace Obstaculos {
	namespace Retardantes {
		Lama::Lama(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Lama::~Lama()
		{

		}
	}
}