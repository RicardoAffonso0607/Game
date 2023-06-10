#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
	private:
		static Salvamento* pSalvamento;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time, int>> dados;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time, int>>::iterator i;
		fstream progresso;

	public:
		Salvamento();
		~Salvamento();
		void carregarID(ListaEntidades* list_ent, unsigned int id);
		void carregarTodos(ListaEntidades* list_ent);
		void lerJogoSalvo();
		void salvarJogo();
		void limparJogoSalvo();
		static Salvamento* getSalvamento();
	};
}