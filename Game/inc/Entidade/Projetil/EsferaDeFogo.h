#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeFogo : public Projetil
	{
	private:
		static const int damage;
		
		static const sf::Vector2f size;

	public:
		EsferaDeFogo(sf::Vector2f pos, int id);
		~EsferaDeFogo();
		
		void getDamage() const;
	};
}
