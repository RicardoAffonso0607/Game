#pragma once

#include "Entidade/Projetil/Projetil.h"
#include "Entidade/Arma/Arco.h"

namespace Projeteis {
	class Flecha : public Projetil
	{
	private:
		Arma* pGun;

		static const int damage;

		static const unsigned int id;

	public:
		Flecha(sf::Vector2f pos);
		~Flecha();
		
		Arma* getGun();

		int getDamage() const;

		void setCaster(Armas::Arco* gun);
	};
}
