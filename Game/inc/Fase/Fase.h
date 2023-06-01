#pragma once

#include "Lista/ListaEntidades.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Eventos.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"
#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"
#include "Entidade/Plataforma/Plataforma.h"

namespace Fase {
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