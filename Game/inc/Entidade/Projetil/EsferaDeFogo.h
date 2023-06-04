#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Projeteis {
	class EsferaDeFogo : public Projetil
	{
	private:
		Inimigos::Disparador* pEnemyCaster = nullptr;

		static const int damage = 4;

		static const unsigned int id = 81;

	public:
		EsferaDeFogo(sf::Vector2f pos);
		~EsferaDeFogo();
		
		Inimigos::Disparador* getEnemyCaster();

		int getDamage() const;

		void setEnemyCaster(Inimigos::Disparador* caster);
	};
}
