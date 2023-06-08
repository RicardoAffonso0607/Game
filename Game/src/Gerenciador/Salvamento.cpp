#include "pch.h"
#include "Gerenciador/Salvamento.h"

namespace Gerenciador{
	Salvamento::Salvamento(){

	}

	Salvamento::~Salvamento(){

	}

  void Salvamento::carregar()
  {
  }

  void Salvamento::salvar()
  {
  }

  void Salvamento::limpar()
  {
  }

Salvamento* Salvamento::getSalvamento()
	{
		if (pSalva == nullptr)
			pSalva = new Salvamento();

		return pSalva;
	}
}