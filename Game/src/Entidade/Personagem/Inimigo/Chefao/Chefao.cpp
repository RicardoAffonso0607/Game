#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	Chefao::Chefao():
		pProjetil(nullptr)
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Chefao::~Chefao()
	{
	}
}
