#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
	private:
		const set<unsigned int> id_list{ 1, 2, 51, 52, 61, 62, 71, 72, 91, 92, 93 };// lista de ids para salvar ou restaurar

		const set<unsigned int> player_id{ 1, 2 };// ids dos jogadores

		static Salvamento* pSalvamento;// singleton

		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>> dados;// multimapa dos dados

		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>>::iterator i;// iterador dos dados

		vector<pair<string, int>> jogadores;// vetor dos jogadores

		vector<pair<string, int>>::iterator p;// iterador dos jogadores

		fstream progresso;// arquivo para salvar o progresso do jogo
		fstream ranking;// arquivo para salvar o ranking do jogo

	public:
		Salvamento();
		~Salvamento();

		void carregarID(ListaEntidades* list_ent, unsigned int id);// encontra o id escolhido na lista de entidades
		void carregarJogoSalvo(ListaEntidades* list_ent);// restaura o jogo salvo
		void carregarPersonagens(ListaEntidades* list_ent);// seleciona o id dos personagens para restaurar os dados
		void limparJogoSalvo();// limpa os dados salvos
		void limparRankingSalvo();// limpa o ranking salvo
		void prepararSalvarJogo(ListaEntidades* list_ent);// pega vida, posição e relógio
		void prepararSalvarRanking(ListaEntidades* list_ent);// pega as pontuações e apelidos dos jogadores
		void salvarJogo(ListaEntidades* list_ent);// salva o jogo
		void salvarRanking(ListaEntidades* list_ent);// salva o ranking
		void restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um);// restaura os dados daquela entidade na lista

		static Salvamento* getSalvamento();// singleton
	};
}