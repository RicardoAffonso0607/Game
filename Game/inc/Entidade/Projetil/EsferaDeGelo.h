#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Projeteis {
	class EsferaDeGelo : public Projetil
	{
	private:
		static const int damage;// dano que causa

		static const unsigned int id;

	public:
		EsferaDeGelo(sf::Vector2f pos);
		~EsferaDeGelo();

		float getMass() const override;// massa?

		int getDamage() const override;// dano que causa?

		unsigned int getId() const override;// id?

		void attack() override;// aplica efeito do ataque
	};
}