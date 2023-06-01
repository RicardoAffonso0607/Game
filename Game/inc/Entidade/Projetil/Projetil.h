#pragma once

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Projetil {
	class Projetil : public Entidade
	{
	private:
		Inimigo::Disparador::Disparador* caster;
		float damage;

	public:
		Projetil(sf::Vector2f pos, int id);
		~Projetil();

		void setCaster(Inimigo::Disparador::Disparador* pCaster) { caster = pCaster; }
		Inimigo::Disparador::Disparador* getCaster() { return caster; }

		void move();
		void attack();
	};
}