#pragma once

#include "Lista/ListaEntidades.h"
#include "Gerenciador/Grafico.h"

namespace Gerenciador{
	class Salvamento{
	private:
		static Salvamento* pSalvamento;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time, int32_t>> dados;
		multimap<unsigned int, tuple<int, sf::Vector2f, sf::Time, int32_t>>::iterator i;
		fstream progresso;

	public:
		Salvamento();
		~Salvamento();
		void carregar(Grafico* ger_graf);
		void salvar();
		void limpar();
		static Salvamento* getSalvamento();
	};
}