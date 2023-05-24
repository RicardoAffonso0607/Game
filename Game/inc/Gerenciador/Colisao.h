#pragma once

#include "Lista/ListaEntidades.h"

namespace Gerenciador{
    class Colisao{
    protected:
        void collide(Entidade *ent1, Entidade *ent2);
        void ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f cg1, sf::Vector2f cg2, sf::Vector2f centerDistance, sf::Vector2f centerSum);
        void effects(Entidade* ent1, Entidade* ent2);
        void gravity(Entidade* ent1, Entidade* ent2);
        void trajectory(Entidade* ent);
    public:
        void collided(ListaEntidades* list_ent);
        Colisao();
        ~Colisao();
    };
}

