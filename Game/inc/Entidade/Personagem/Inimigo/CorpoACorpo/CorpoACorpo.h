#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	private:

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();

		void move();
		void attack();
	};
}