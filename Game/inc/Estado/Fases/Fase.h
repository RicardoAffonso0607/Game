#pragma once

#include "Lista/ListaEntidades.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Eventos.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Personagem/Inimigos/Boss.h"
#include "Entidade/Personagem/Inimigos/EnemyMelee.h"
#include "Entidade/Personagem/Inimigos/EnemyRanged.h"
#include "Entidade/Obstaculos/ObstacleBlock.h"
#include "Entidade/Obstaculos/ObstacleDamage.h"
#include "Entidade/Obstaculos/ObstacleSlowness.h"
#include "Entidade/Obstaculos/Plataforma.h"

namespace Estado {
	class Fase 
	{
	protected:
		ListaEntidades* list;
		static Gerenciador::Grafico* ger_grafico;
		/*static*/ Gerenciador::Colisao* colisor;
		static Gerenciador::Eventos* ger_eventos;

	public:
		Fase();
		~Fase();

		virtual void executar() = 0;
		virtual void criarJogador() = 0;
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;

		void draw() { list->drawAll(); }
		void move() { list->moveAll(); }

	};
}