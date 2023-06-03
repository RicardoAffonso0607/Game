#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Lama.h"

namespace Obstaculos {
	namespace Retardantes {
		Lama::Lama(sf::Vector2f pos, sf::Vector2f size) :
			id(32),
			slowness(.7f)
		{
			body.setPosition(pos);
			body.setSize(size);
		}

		Lama::~Lama()
		{
		}

		Lama::float getSlowness() const
		{
			return slowness;
		}

		unsigned int Lama::getId() const
		{
			return id;
		}
	}
}