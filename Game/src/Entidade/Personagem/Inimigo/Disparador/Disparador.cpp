#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigo {
	namespace Disparador {
		Disparador::Disparador(sf::Vector2f pos, int id) : Inimigo(pos, id)
		{
			movable = true;
			attacker = true;
			retarder = false;
			damageable = true;

			//magic = nullptr;
			this->life = 50;
			this->damage = 0;

			body.setFillColor(sf::Color::Magenta);
			body.setPosition(pos);
		}

		Disparador::~Disparador()
		{
		}

		void Disparador::move()
		{
		}

		void Disparador::attack()
		{
			//magic = new Projetil(sf::Vector2f(pos.x, pos.y), 10);
			//magic->setCaster(this);
		}
	}
}