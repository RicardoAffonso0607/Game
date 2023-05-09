#pragma once

#include "stdafx.h"

class GerenciaColisao{
  private:
    Lista::ListaEntidade* listaPersonagem;
    Lista::ListaObstaculo* listaObstaculo;
  public:
    GerenciaColisao(Lista::ListaEntidade* listaPersonagem, Lista::ListaObstaculo* listaObstaculo);
    ~GerenciaColisao();
    const sf::Vector2f CalculaColisao(Entidade::Entidade* jogador1);
    void Executar();
};
