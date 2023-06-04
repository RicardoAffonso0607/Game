#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Lama.h"

namespace Obstaculos {
	namespace Retardantes {
		const float Lama::slowness = .7f;

		const int Lama::id = 32;

		Lama::Lama(sf::Vector2f pos, sf::Vector2f size)
		{
			body.setPosition(pos);
			body.setSize(size);
		}

		Lama::~Lama()
		{
		}

		float Lama::getSlowness() const
		{
			return slowness;
		}

		unsigned int Lama::getId() const
		{
			return id;
		}
	}
}