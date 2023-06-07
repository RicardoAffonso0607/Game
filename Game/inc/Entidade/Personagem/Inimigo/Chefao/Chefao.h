#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Chefao : public Inimigo
	{
	protected:
		Projetil* pProjetil;// ponteiro do projétil

		static const bool retardable;// é retardável?

		static const float action_radius;// raio de ação
		float cast_height = .8f;// altura do disparo

		static const int cadence;// cadência do ataque múltiplo

		static const sf::Time cadence_delay;// espera entre tiros múltiplos
		static const sf::Time burst_delay;// espera entre rajadas

	public:
		Chefao();
		virtual ~Chefao();

		bool getRetardable() const override;// é retardável?

		void move() override;// move-se
	};
}