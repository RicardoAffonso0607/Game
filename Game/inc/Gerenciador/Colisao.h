#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
    class Colisao{
    protected:
        void collide(Entidade *ent1, Entidade *ent2);
        void ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre);
        void effects(Entidade* ent1, Entidade* ent2);
        void gravity(Entidade* ent1, Entidade* ent2);
        void trajectory(Entidade* ent);
        struct vertex;
        void vertexMath(vertex *rect, Entidade* ent);
        void jump(Entidade* ent);
    public:
        void executar(ListaEntidades* list_ent);
        Colisao();
        ~Colisao();
    };
}

