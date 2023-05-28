#pragma once

#include "Entidade/Entidade.h"

namespace Entidades{
	class EntidadeMovel:public Entidade{
	protected:
		int vel_x;
		int vel_y;
		int vel_max_x;
		int vel_max_y;
	public:
		EntidadeMovel(int id, sf::Vector2f pos);
		~EntidadeMovel();
	};
}