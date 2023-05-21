#pragma once

#include "Entidade/Entidade.h"

//namespace Entidade{
//    class EntidadeMovel:public Entidade{
//    protected:
//        Calcula::CoordF velocidade;
//        bool ativo;
//        bool mirandoEsquerda;
//        unsigned int dano;
//
//        ElementoGrafico::MultiFrameAnimation sprite;
//
//    public:
//        MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f),
//            Math::CoordF size = Math::CoordF(0.f, 0.f),
//            ID id = empty,
//            Math::CoordF velocity = Math::CoordF(0.f, 0.f));
//
//        virtual ~MovingEntity();
//
//        virtual void render();
//
//        virtual void update(const float dt) = 0;
//
//        virtual void initialize() = 0;
//
//        virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;
//
//        virtual void updateSprite(const float dt) = 0;
//
//        const bool isFacingLeft() const;
//
//        void setFacingLeft(const bool left);
//
//        void setFacingLeft();
//
//        const bool isActive() const;
//
//        Math::CoordF getVelocity() const;
//
//        void setVelocity(Math::CoordF velo);
//
//        void moveOnCollision(Math::CoordF intersect, Entities::Entity* other);
//
//        void setDamage(unsigned int dmg);
//
//        virtual unsigned int getDamage();
//    };
//
//}