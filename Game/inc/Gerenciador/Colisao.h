#pragma once

#include "Lista/ListaEntidades.h"

inline static constexpr float ACEL_GRAV = 9.8f;

namespace Gerenciador{
    class Colisao{
    private:
        ListaEntidades* list_ent;
        Grafico* ger_graf;

        struct vertex;

        void collide(vector<Entidade*> ent);
        void ricochet(vector<Entidade*> ent, sf::Vector2f sobre);
        void vertexMath(vertex *rect, Entidade* ent);
        void jump(Entidade* ent);
        void gravity(Entidade* ent);

    public:
        Colisao(ListaEntidades* list, Grafico* graf);
        ~Colisao();

        void executar();
    };
}