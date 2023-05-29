#pragma once

#include "Entidade/Entidade.h"

namespace Entidades{
	class EntidadeMovel:public Entidade{
	protected:
		int vel_x;
		int vel_y;
	
	public:
		EntidadeMovel(int id, sf::Vector2f pos);
		~EntidadeMovel();

		virtual void move() = 0;
		virtual void attack() = 0;
	};
}