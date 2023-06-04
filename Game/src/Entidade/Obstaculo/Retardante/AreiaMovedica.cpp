#include "pch.h"
#include "Entidade/Obstaculo/Retardante/AreiaMovedica.h"

namespace Obstaculos {
	namespace Retardantes {
		const float AreiaMovedica::slowness = .5f;

		const int AreiaMovedica::id = 31;

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