#include "pch.h"
#include "Gerenciador/Colisao.h"
#include "Entidade/EntidadeMovendo.h"
#include "Estado/Nivel.h"

//namespace Gerenciador{
//    Colisao::Colisao(Lista::ListaEntidades* entidadesMovendo, Lista::ListaEntidades* entidadesEstaticas, Estado::Nivel* pnivel):
//        entidadeMovendo(entidadeMovendo),
//        entidadeEstatica(entidadeEstatica),
//        pnivel(pnivel){}
//
//    Colisao::~Colisao(){
//        entidadeEstatica = nullptr;
//        entidadeMovendo = nullptr;
//    }
//
//    void Colisao::colidir(){
//        Entidade::Entidade* ent1 = nullptr;
//        Entidade::Entidade* ent2 = nullptr;
//        Calculadora::CoordF intersect;
//        Calculadora::CoordF centerDistance;
//        int i, j;
//        for (i = 0; i < entidadeEstatica->getSize(); i++) {
//            for (j = 0; j < movingEntities->getSize(); j++) {
//                ent1 = (*staticEntities)[i];
//                ent2 = (*movingEntities)[j];
//
//                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
//                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;
//
//                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
//                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);
//
//                if (intersect.x < 0.0f && intersect.y < 0.0f) {
//                    ent2->collide(ent1, intersect);
//                }
//            }
//        }
//        for (i = 0; i < movingEntities->getSize(); i++){
//            for (j = i + 1; j < movingEntities->getSize(); j++) {
//                ent1 = (*movingEntities)[i];
//                ent2 = (*movingEntities)[j];
//
//                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
//                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;
//
//                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
//                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);
//
//                if (intersect.x < 0.0f && intersect.y < 0.0f){
//                    ent2->collide(ent1, intersect);
//                    ent1->collide(ent2, intersect);
//                }
//            }
//        }
//        clear();
//    }
//
//    void Colisao::limpar(){
//        Entidade::MovingEntity* pAux = nullptr;
//        for (int i = 0; i < movingEntities->getSize(); i++) {
//            pAux = static_cast<Entities::MovingEntity*>((*movingEntities)[i]);
//            if (pAux != nullptr) {
//                if (!pAux->isActive()) {
//                    if (pAux->getId() != Entities::ID::coin)
//                        plvl->coinBomb(pAux->getPosition());
//                    movingEntities->deleteEntity(pAux);
//                    i--;
//                    if (i < 0)
//                        i = -1;
//                }
//            }
//        }
//    }
//
//}