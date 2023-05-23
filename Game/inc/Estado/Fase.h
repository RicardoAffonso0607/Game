#pragma once

#include "Entidade/Personagem/Inimigos/Boss.h"
#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Lista/ListaEntidades.h"

namespace Estado {
	class Fase {
	private:
		ListaEntidades* listaEntidades;
		Boss* enemy1;
		Jogador j1;
	public:
		Fase(Jogador* j1);
		~Fase();

	};
}