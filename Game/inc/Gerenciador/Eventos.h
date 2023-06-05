#pragma once

/* Código inspirado no vídeo do monitor Giovane Limas Salvi 2022.2 */

#include "Grafico.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
//#include "Lista/ListaEntidades.h"

namespace Gerenciador
{
	class Eventos
	{
	private:
		
		static Eventos* pEventos;
		Grafico* pGrafico;
		Entidade* pJogador;
		//ListaEntidades* list_ent;
		Eventos();

	public:
		~Eventos();

		static Eventos* getEventos();
		void setJogador(Jogador* pJogador) { this->pJogador = pJogador; }

		void executar();
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaMouseClicado();
	};
}