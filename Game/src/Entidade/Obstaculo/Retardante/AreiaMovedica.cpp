#include "pch.h"
#include "Entidade/Obstaculo/Retardante/AreiaMovedica.h"

namespace Obstaculos {
	namespace Retardantes {
		AreiaMovedica::AreiaMovedica(sf::Vector2f pos, sf::Vector2f size, int id) :
			slowness(.5f)
		{
			body.setPosition(pos);
			body.setSize(size);
		}

		AreiaMovedica::~AreiaMovedica()
		{
		}

		AreiaMovedica::float getSlowness() const
		{
			return slowness;
		}
	}
}