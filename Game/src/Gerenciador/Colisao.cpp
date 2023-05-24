#include "pch.h"
#include "Gerenciador/Colisao.h"

namespace Gerenciador{
    Colisao::Colisao(){}

    Colisao::~Colisao(){
    }

    void Colisao::collided(ListaEntidades* list_ent){
        int i, j;
        for (i = 0; i < list_ent->getSize(); i++) {
            if (list_ent->getEntity(i)->isMovable())
                for (j = 0; j < list_ent->getSize(); j++)
                    collide(list_ent->getEntity(i), list_ent->getEntity(j));
        }
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2){
        sf::Vector2f cg1, cg2, centerDistance, centerSum;
        cg1.x = ent1->getPosition().x + 0.5f*ent1->getEntSize().x;
        cg1.y = ent1->getPosition().y + 0.5f*ent1->getEntSize().y;
        cg2.x = ent2->getPosition().x + 0.5f*ent2->getEntSize().x;
        cg2.y = ent2->getPosition().y + 0.5f*ent2->getEntSize().y;
        centerDistance.x = fabs(cg2.x - cg1.x);
        centerDistance.y = fabs(cg2.y - cg1.y);
        centerSum.x = 0.5f*(ent2->getEntSize().x + ent1->getEntSize().x);
        centerSum.y = 0.5f*(ent2->getEntSize().y + ent1->getEntSize().y);
        //printf("%f %f %f %f\n", ent1->getPosition().x, ent1->getPosition().y, ent2->getPosition().x, ent2->getPosition().y);
        //printf("\n%f %f %f %f\n", centerDistance.x, centerDistance.y, centerSum.x, centerSum.y);
        if(centerDistance.x < centerSum.x && centerDistance.y < centerSum.y && centerDistance.x && centerDistance.y){// colidiu
            effects(ent1, ent2);// aplica dano e lentidão
            ricochet(ent1, ent2, cg1, cg2, centerDistance, centerSum);// volta a posição sem sobreposição
        }
    }

    /* ao andar e sobrepor um fixo, volta à posição só encostado, e se for um móvel, empurra */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f cg1, sf::Vector2f cg2, sf::Vector2f centerDistance, sf::Vector2f centerSum){
        printf("entrou\n");
        sf::Vector2f nova_pos1, nova_pos2;
        if(ent1->isMovable() && !ent2->isMovable()) {
            if(cg1.x <= cg2.x)
                nova_pos1.x = cg2.x - centerSum.x;
            else
                nova_pos1.x = cg2.x + centerSum.x;
            if(cg1.y <= cg2.y)
                nova_pos1.y = cg2.y - centerSum.y;
            else
                nova_pos1.y = cg2.y + centerSum.y;
            ent1->changePosition(nova_pos1 - cg1);
        }
        else if(!ent1->isMovable() && ent2->isMovable()){
            if(cg1.x <= cg2.x)
                nova_pos2.x = cg1.x - centerSum.x;
            else
                nova_pos2.x = cg1.x + centerSum.x;
            if(cg1.y <= cg2.y)
                nova_pos2.y = cg1.y - centerSum.y;
            else
                nova_pos2.y = cg1.y + centerSum.y;
            ent2->changePosition(nova_pos2 - cg2);
        }
        else{
            sf::Vector2f shift;
            shift.x = 0.5f*(centerSum.x - centerDistance.x);
            shift.y = 0.5f*(centerSum.y - centerDistance.y);
            if(cg1.x <= cg2.x){
                nova_pos1.x -= shift.x;
                nova_pos2.x += shift.x;
            }
            else{
                nova_pos2.x += shift.x;
                nova_pos1.x -= shift.x;
            }
            if(cg1.y <= cg2.y){
                nova_pos1.y -= shift.y;
                nova_pos2.y += shift.y;
            }
            else{
                nova_pos2.y += shift.y;
                nova_pos1.y -= shift.y;
            }
            ent1->changePosition(nova_pos1);
            ent2->changePosition(nova_pos2);
        }   
    }

    void Colisao::effects(Entidade* ent1, Entidade* ent2){
        if(ent1->isDamageable() && ent2->isAttacker()){
            
        }

        if(ent1->isAttacker() && ent2->isDamageable()){
            
        }

        if(ent1->isMovable() && ent2->isRetarder()){
            
        }

        if(ent1->isRetarder() && ent2->isMovable()){
            
        }

    }

    void Colisao::gravity(Entidade* ent1, Entidade* ent2){
        
    }

    void Colisao::trajectory(Entidade* ent) {

    }
}