#pragma once

#include "pch.h"
#include "Entidade/Entidade.h"
#include "Lista/ListaEntidades.h"

namespace Gerenciador{
    class Colisao{
    protected:
        //Entidades::EntidadeMovel *eMov;
        //Entidades::EntidadeFixa *eFix;
        void colidiu();
    public:
        Colisao(/*Entidades::EntidadeMovel *eMov, Entidades::EntidadeFixa *eFix*/);
        ~Colisao();
    };
}