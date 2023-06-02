#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos, int id) :
		damage(4)
	{
		body.setPosition(pos);
	}

	EsferaDeFogo::~EsferaDeFogo()
	{

	}
}