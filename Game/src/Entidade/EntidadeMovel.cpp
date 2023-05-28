#include "pch.h"
#include "Entidade/EntidadeMovel.h"

namespace Entidades{
	EntidadeMovel::EntidadeMovel(int id, sf::Vector2f pos) : Entidade(id), vel_x(0), vel_y(0),
		vel_max_x(5), vel_max_y(5)
	{
		this->pos = pos;
	}

	EntidadeMovel::~EntidadeMovel()
	{

	}
}