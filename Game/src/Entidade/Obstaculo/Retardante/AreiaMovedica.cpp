#include "pch.h"
#include "Entidade/Obstaculo/Retardante/AreiaMovedica.h"

namespace Obstaculos {
	namespace Retardantes {
		AreiaMovedica::AreiaMovedica(sf::Vector2f pos, sf::Vector2f size)
		{
			body.setPosition(pos);
			body.setSize(size);
		}

		AreiaMovedica::~AreiaMovedica()
		{
		}

		float AreiaMovedica::getSlowness() const
		{
			return slowness;
		}

		unsigned int AreiaMovedica::getId() const
		{
			return id;
		}
	}
}