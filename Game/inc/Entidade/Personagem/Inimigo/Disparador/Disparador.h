#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Disparador : public Inimigo
	{
	protected:
		Projetil* pProjetil;// ponteiro do projétil

		static const bool retardable;// é retardável?

		static const float attack_radius;// raio de ação
		static const float cast_height;// altura do disparo

		static const sf::Time attack_delay;// tempo entre disparos

	public:
		Disparador();
		virtual ~Disparador();

		bool getRetardable() const override;// é retardável?

		void move() override;// move-se
	};
}