#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador {
    class Colisao {
    private:

        ListaEntidades* list_ent;
        Grafico* ger_graf;
        int colidiu = 0;
        void collide(Entidade* ent1, Entidade* ent2);
        void ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre);
        void effects(Entidade* ent1, Entidade* ent2);
        void gravity(Entidade* ent1, Entidade* ent2);
        void trajectory(Entidade* ent);
        struct vertex;
        void vertexMath(vertex* rect, Entidade* ent);
        void jump(Entidade* ent);
        void gravity(Entidade* ent);

    public:
        void executar();
        Colisao(ListaEntidades* list, Grafico* graf);
        ~Colisao();
    };
}

