#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
	private:
		static Salvamento* pSalvamento;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>> dados;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time>>::iterator i;
		fstream progresso;

	public:
		Salvamento();
		~Salvamento();
		void carregarID(ListaEntidades* list_ent, unsigned int id);
		void carregarPersonagens(ListaEntidades* list_ent);
		void lerJogoSalvo();
		void salvarJogo();
		void limparJogoSalvo();
		void restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um);
		static Salvamento* getSalvamento();
	};
}