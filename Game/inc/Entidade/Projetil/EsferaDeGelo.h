#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Projeteis {
	class EsferaDeGelo : public Projetil
	{
	private:
		Inimigos::Disparador* pEnemyCaster = nullptr;

		static const int damage = 7;

		static const unsigned int id = 82;

	public:
		EsferaDeGelo(sf::Vector2f pos);
		~EsferaDeGelo();

		Inimigos::Disparador* getEnemyCaster();

		int getDamage() const;

		void setEnemyCaster(Inimigos::Disparador* caster);
	};
}
