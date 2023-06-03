#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Lama.h"

namespace Obstaculos {
	namespace Retardantes {
		Lama::Lama(sf::Vector2f pos, sf::Vector2f size, int id)
			slowness(.7f)
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Lama::~Lama()
		{
		}

		Lama::float getSlowness() const
		{
			return slowness;
		}
	}
}