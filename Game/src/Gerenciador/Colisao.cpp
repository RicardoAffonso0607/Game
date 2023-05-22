#include "pch.h"
#include "Gerenciador/Colisao.h"
#include "Entidade/EntidadeMovel.h"
#include "Entidade/EntidadeFixa.h"
#include "Estado/Nivel.h"

//namespace Gerenciador{
//    Colisao::Colisao(Lista::ListaEntidades* entidadesMoveis, Lista::ListaEntidades* entidadesFixas, Estado::Nivel* pnivel):
//        entidadeMovel(entidadeMovel),
//        entidadeFixa(entidadeFixa),
//        pnivel(pnivel){}
//
//    Colisao::~Colisao(){
//        entidadeFixa = nullptr;
//        entidadeMovel = nullptr;
//    }
//
//    void Colisao::colidir(){
//        Entidade::Entidade* ent1 = nullptr;
//        Entidade::Entidade* ent2 = nullptr;
//        Calculadora::CoordF intersect;
//        Calculadora::CoordF centerDistance;
//        int i, j;
//        for (i = 0; i < entidadeFixa->getSize(); i++) {
//            for (j = 0; j < entidadesMoveis->getSize(); j++) {
//                ent1 = (*entidadesFixas)[i];
//                ent2 = (*entidadesMoveis)[j];
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
//        for (i = 0; i < entidadesMoveis->getSize(); i++){
//            for (j = i + 1; j < entidadesMoveis->getSize(); j++) {
//                ent1 = (*entidadesMoveis)[i];
//                ent2 = (*entidadesMoveis)[j];
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
//        for (int i = 0; i < entidadesMoveis->getSize(); i++) {
//            pAux = static_cast<Entities::MovingEntity*>((*entidadesMoveis)[i]);
//            if (pAux != nullptr) {
//                if (!pAux->isActive()) {
//                    if (pAux->getId() != Entities::ID::coin)
//                        plvl->coinBomb(pAux->getPosition());
//                    entidadesMoveis->deleteEntity(pAux);
//                    i--;
//                    if (i < 0)
//                        i = -1;
//                }
//            }
//        }
//    }
//
//}