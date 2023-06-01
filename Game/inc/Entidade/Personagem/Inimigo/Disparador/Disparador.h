#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Inimigo {
	namespace Disparador {
		class Disparador : public Inimigo
		{
		private:
			//Projetil* magic;

		public:
			Disparador(sf::Vector2f pos, int id);
			~Disparador();

			void move();
			void attack();
		};
	}
}