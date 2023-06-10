#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
	private:
		vector<unsigned int> id_list{ 1, 2, 51, 52, 61, 62, 71, 72, 91, 92, 93 };
		static Salvamento* pSalvamento;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>> dados;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>>::iterator i;
		fstream progresso;

	public:
		Salvamento();
		~Salvamento();
		void carregarID(ListaEntidades* list_ent, unsigned int id);
		void carregarJogoSalvo(ListaEntidades* list_ent);
		void carregarPersonagens(ListaEntidades* list_ent);
		void limparJogoSalvo();
		void prepararSalvarJogo(ListaEntidades* list_ent);
		void salvarJogo(ListaEntidades* list_ent);
		void restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um);
		static Salvamento* getSalvamento();
	};
}