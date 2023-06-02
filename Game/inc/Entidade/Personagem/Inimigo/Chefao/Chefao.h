#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Inimigos {
	class Chefao : public Inimigo
	{
	private:

	public:
		Chefao();
		virtual ~Chefao();

		void move();
		void attack();
	};
}