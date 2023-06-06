#pragma once

#include "Lista/ListaEntidades.h"

inline static constexpr float ACEL_GRAV = 9.8f;

namespace Gerenciador{
    class Colisao{
    private:
        ListaEntidades* list_ent;
        Grafico* ger_graf;

        struct vertex;

        void collide(Entidade *ent1, Entidade *ent2);
        void ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre);
        //void effects(Entidade* ent1, Entidade* ent2);
        void gravity(Entidade* ent1, Entidade* ent2);
        void vertexMath(vertex *rect, Entidade* ent);
        void jump(Entidade* ent);
        void gravity(Entidade* ent);

    public:
        Colisao(ListaEntidades* list, Grafico* graf);
        ~Colisao();

        void executar();
    };
}