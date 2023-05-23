#pragma once

#include "Entidade/Entidade.h"
#include "Lista/ListaEntidades.h"

namespace Gerenciador{
    class Colisao{
    protected:
        void collide(Entidade *ent1, Entidade *ent2);
        void ricochet(Entidade* ent1, Entidade* ent2);
        void effects(Entidade* ent1, Entidade* ent2);
    public:
        Colisao(ListaEntidades list_ent);
        ~Colisao();
    };
}

