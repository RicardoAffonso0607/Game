#pragma once

#include "Lista/ListaEntidades.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Eventos.h"

/* entidades */
#include "Entidade/Personagem/Jogador/Lutadora.h"
#include "Entidade/Personagem/Jogador/Ninja.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"
#include "Entidade/Obstaculo/Inerte/ArbustoFlorido.h"
#include "Entidade/Obstaculo/Inerte/ArbustoSeco.h"
#include "Entidade/Obstaculo/Danoso/ArmadilhaDeLancas.h"
#include "Entidade/Obstaculo/Danoso/Cacto.h"
#include "Entidade/Obstaculo/Retardante/AreiaMovedica.h"
#include "Entidade/Obstaculo/Retardante/Lama.h"
#include "Entidade/Plataforma/Areal.h"
#include "Entidade/Plataforma/Gramado.h"
#include "Entidade/Projetil/EsferaDeFogo.h"
#include "Entidade/Projetil/EsferaDeGelo.h"
#include "Entidade/Projetil/Flecha.h"

/* old */
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
		sf::Texture background_texture;
		sf::RectangleShape background;

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