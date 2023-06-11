#pragma once

#include "Lista/ListaEntidades.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Gerenciador{
	class Salvamento{
	private:
		const set<unsigned int> id_list{ 1, 2, 51, 52, 61, 62, 71, 72, 91, 92, 93 };// lista de ids para salvar ou restaurar

		const set<unsigned int> player_id{ 1, 2 };// ids dos jogadores

		static Salvamento* pSalvamento;// singleton

		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>> dados;// multimapa dos dados

		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>>::iterator i;// iterador dos dados

		set<tuple<int, string, int, unsigned int>> jogadores;// vetor dos jogadores

		set<tuple<int, string, int, unsigned int>>::iterator p;// iterador dos jogadores

		fstream progresso;// arquivo para salvar o progresso do jogo
		fstream ranking;// arquivo para salvar o ranking do jogo

		int rodada;

	public:
		Salvamento();
		~Salvamento();

		static Salvamento* getSalvamento();// singleton

		void encontrarID(ListaEntidades* list_ent, unsigned int id);// encontra o id escolhido na lista de entidades
		void encontrarJogador(ListaEntidades* list_ent, unsigned int id);// encontra o jogador na lista de entidades
		void carregarJogoSalvo(ListaEntidades* list_ent);// restaura o jogo salvo do arquivo
		void carregarPersonagens(ListaEntidades* list_ent);// seleciona o id dos personagens para restaurar os dados
		void carregarRankingSalvo();// restaura o ranking salvo do arquivo
		void limparJogoSalvo();// limpa os dados salvos
		void limparRankingSalvo();// limpa o ranking salvo
		void prepararSalvarJogo(ListaEntidades* list_ent);// pega id, vida, posição e relógio
		void prepararSalvarRanking(ListaEntidades* list_ent);// pega pontuação, apelido e id do jogador e rodada (quantas vezes já jogou)
		void salvarJogo(ListaEntidades* list_ent);// salva o jogo
		void salvarRanking(ListaEntidades* list_ent);// salva o ranking
		void restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um);// restaura os dados daquela entidade na lista
		void restaurarJogador(Jogador* player, tuple<int, string, int, unsigned int> dados_jogador);// restaura os dados do jogador
	};
}