#pragma once

#include "Entidade/Entidade.h"

namespace Entidades{
    class EntidadeFixa:public Entidade{
    protected:

    public:
        EntidadeFixa(int id, sf::Vector2f pos);
        ~EntidadeFixa();

    };
}
