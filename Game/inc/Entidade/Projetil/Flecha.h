#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Arma/Arco.h"

namespace Projeteis {
	class Flecha : public Projetil
	{
	private:
		Arma* pGun = nullptr;

		static const int damage = 10;

		static const unsigned int id = 83;

	public:
		Flecha(sf::Vector2f pos);
		~Flecha();
		
		Arma* getGun();

		int getDamage() const;

		void setGun(Arma* gun);
	};
}
