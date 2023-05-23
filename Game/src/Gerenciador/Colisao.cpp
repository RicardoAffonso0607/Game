#include "pch.h"
#include "Gerenciador/Colisao.h"

namespace Gerenciador{
    Colisao::Colisao(ListaEntidades list_ent){
        //int i, j;
        //for (i = 0; i < list_ent->getTamanho(); i++) {
        //    if(list_ent->getEntity(i)->isMovable())
        //        for (j = 0; i < list_ent->getTamanho(); j++) {
        //            collide(list_ent->getEntity(i), list_ent->getEntity(j));
        //}
    }

    Colisao::~Colisao(){
        //ent1 = nullptr;
        //ent2 = nullptr;
        //centerDistance = nullptr;
        //centerSum = nullptr;
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2) {
        //sf::Vector2f centerDistance, centerSum;
        //centerDistance.x = fabs(ent2->getPosition().x - ent1->getPosition().x);
        //centerDistance.y = fabs(ent2->getPosition().y - ent1->getPosition().y);
        //centerSum.x = 0.5*(ent2->getDim().x + ent1->getDim().x);
        //centerSum.y = 0.5*(ent2->getDim().y + ent1->getDim().y);
        //if (centerDistance.x < centerSum.x && centerDistance.y < centerSum.y){// colidiu
        //    effects(ent1, ent2);// aplica dano e lentidão
        //    ricochet(ent1, ent2, centerSum);// volta a posição sem sobreposição
        //}
    }

    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f centerDistance, sf::Vector2f centerSum) {
        //if (ent1->isMovable() && !ent2->isMovable()) {
        //    if (ent1->getPosition().x <= ent2->getPosition().x){
        //        ent1->pos.x = ent2->x - centerSum.x;
        //    }
        //    else {
        //        ent1->pos.x = ent2->x + centerSum.x;
        //    }
        //    if (ent1->getPosition().y <= ent2->getPosition().y){
        //        ent1->pos.y = ent2->y - centerSum.y;
        //    }
        //    else {
        //        ent1->pos.y = ent2->y + centerSum.y;
        //    }
        //}
        //else if (!ent1->isMovable() && ent2->isMovable()){
        //    if (ent1->getPosition().x <= ent2->getPosition().x) {
        //        ent2->pos.x = ent1->x - centerSum.x;
        //    }
        //    else {
        //        ent2->pos.x = ent1->x + centerSum.x;
        //    }
        //    if (ent1->getPosition().y <= ent2->getPosition().y) {
        //        ent2->pos.y = ent1->y - centerSum.y;
        //    }
        //    else {
        //        ent2->pos.y = ent1->y + centerSum.y;
        //    }
        //}
        //else{
        //    sf::Vector2f shift;
        //    shift.x = 0.5*(centerSum.x - centerDistance.x);
        //    shift.y = 0.5*(centerSum.y - centerDistance.y);
        //    if (ent1->getPosition().x <= ent2->getPosition().x){
        //        ent1->pos.x -= shift.x;
        //        ent2->pos.x += shift.x;
        //    }
        //    else {
        //        ent2->pos.x += shift.x;
        //        ent1->pos.x -= shift.x;
        //    }
        //    if (ent1->getPosition().y <= ent2->getPosition().y){
        //        ent1->pos.y -= shift.y;
        //        ent2->pos.y += shift.y;
        //    }
        //    else {
        //        ent2->pos.y += shift.y;
        //        ent1->pos.y -= shift.y;
        //    }
        //}   
    }

    void Colisao::effects(Entidade* ent1, Entidade* ent2) {
        //if (ent1->isDamageable() && ent2->isAttacker()) {}

        //if (ent1->isAttacker() && ent2->isDamageable()) {}

        //if (ent1->isMovable() && ent2->isRetarder()) {}

        //if (ent1->isRetarder() && ent2->isMovable()) {}

    }
}