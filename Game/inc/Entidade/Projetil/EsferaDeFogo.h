#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Projeteis {
	class EsferaDeFogo : public Projetil
	{
	private:
		Inimigos::Disparador* pEnemyCaster;

		static const int damage;

		static const unsigned int id;

	public:
		EsferaDeFogo(sf::Vector2f pos);
		~EsferaDeFogo();
		
		Inimigos::Disparador getEnemyCaster();

		int getDamage() const;

		void setEnemyCaster(Inimigos::Disparador* caster);
	};
}
