#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeFogo : public Projetil
	{
	private:
		static const int damage;// dano que causa

		static const unsigned int id;

	public:
		EsferaDeFogo(sf::Vector2f pos);
		~EsferaDeFogo();

		float getMass() const override;// massa?

		int getDamage() const override;// dano que causa?

		unsigned int getId() const override;// id?

		void attack() override;// aplica efeito do ataque
	};
}
