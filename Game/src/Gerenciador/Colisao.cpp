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
        sf::Vector2f centerDistance, centerSum;
        centerDistance.x = fabs(ent2->getPosition().x - ent1->getPosition().x);
        centerDistance.y = fabs(ent2->getPosition().y - ent1->getPosition().y);
        centerSum.x = 0.5f*(ent2->getEntSize().x + ent1->getEntSize().x);
        centerSum.y = 0.5f*(ent2->getEntSize().y + ent1->getEntSize().y);
        //printf("%f %f %f %f\n", ent1->getPosition().x, ent1->getPosition().y, ent2->getPosition().x, ent2->getPosition().y);
        //printf("\n%f %f %f %f\n", centerDistance.x, centerDistance.y, centerSum.x, centerSum.y);
        if(centerDistance.x < centerSum.x && centerDistance.y < centerSum.y && centerDistance.x && centerDistance.y){// colidiu
            effects(ent1, ent2);// aplica dano e lentidão
            ricochet(ent1, ent2, centerDistance, centerSum);// volta a posição sem sobreposição
        }
    }

    /* ao andar e sobrepor outra entidade, volta à posição só encostado */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f centerDistance, sf::Vector2f centerSum){
        printf("entrou\n");
        sf::Vector2f nova_pos1, nova_pos2;
        if(ent1->isMovable() && !ent2->isMovable()) {
            if(ent1->getPosition().x <= ent2->getPosition().x)
                nova_pos1.x = ent2->getPosition().x - centerSum.x;
            else
                nova_pos1.x = ent2->getPosition().x + centerSum.x;
            if(ent1->getPosition().y <= ent2->getPosition().y)
                nova_pos1.y = ent2->getPosition().y - centerSum.y;
            else
                nova_pos1.y = ent2->getPosition().y + centerSum.y;
            ent1->changePosition(nova_pos1 - ent1->getPosition());
        }
        else if(!ent1->isMovable() && ent2->isMovable()){
            if(ent1->getPosition().x <= ent2->getPosition().x)
                nova_pos2.x = ent1->getPosition().x - centerSum.x;
            else
                nova_pos2.x = ent1->getPosition().x + centerSum.x;
            if(ent1->getPosition().y <= ent2->getPosition().y)
                nova_pos2.y = ent1->getPosition().y - centerSum.y;
            else
                nova_pos2.y = ent1->getPosition().y + centerSum.y;
            ent2->changePosition(nova_pos2 - ent2->getPosition());
        }
        else{
            sf::Vector2f shift;
            shift.x = 0.5f*(centerSum.x - centerDistance.x);
            shift.y = 0.5f*(centerSum.y - centerDistance.y);
            if(ent1->getPosition().x <= ent2->getPosition().x){
                nova_pos1.x -= shift.x;
                nova_pos2.x += shift.x;
            }
            else{
                nova_pos2.x += shift.x;
                nova_pos1.x -= shift.x;
            }
            if(ent1->getPosition().y <= ent2->getPosition().y){
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
}