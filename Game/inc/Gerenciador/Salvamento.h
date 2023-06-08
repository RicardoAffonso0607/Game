#pragma once
#include "Lista/ListaEntidades.h"

namespace Gerenciador{
	class Salvamento{
private:
  static Salvamento* pSalva;
  ListaEntidades* list_ent;
  multimap<unsigned int, vector> dados;

public:
  Salvamento();
		~Salvamento();
  static void carregar();
  static void salvar();
  static void limpar();
  static Salvamento* getSalvamento();
	};
}