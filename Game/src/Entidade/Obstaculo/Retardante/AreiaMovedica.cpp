#include "pch.h"
#include "Entidade/Obstaculo/Retardante/AreiaMovedica.h"

namespace Obstaculos {
	namespace Retardantes {
		AreiaMovedica::AreiaMovedica(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		AreiaMovedica::~AreiaMovedica()
		{

		}
	}
}