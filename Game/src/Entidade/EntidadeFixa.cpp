#include "pch.h"
#include "Entidade/EntidadeFixa.h"

namespace Entidades{
	EntidadeFixa::EntidadeFixa(int id, sf::Vector2f pos) : Entidade(id)
	{
		this->pos = pos;
	}

	EntidadeFixa::~EntidadeFixa()
	{

	}
}