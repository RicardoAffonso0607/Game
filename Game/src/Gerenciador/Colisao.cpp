#include "pch.h"
#include "Calculo/Calculadora.h"
#include "Gerenciador/Colisao.h"
#include "Entidade/EntidadeMovel.h"
#include "Entidade/EntidadeFixa.h"

namespace Gerenciador{
    Colisao::Colisao(/*Entidades::EntidadeFixa* eFix, Entidades::EntidadeMovel* eMov*/){
    //    for (register auto i = eMov.begin(); i != eMov.end(); i++){
    //        for (register auto j = eMov.begin(); j != eMov.end(); j++)
    //            colidiu(eMov[i], eMov[j]);
    //        for (register auto j = eFix.begin(); j != eFix.end(); i++)
    //            colidiu(eFix[i], eMov[j]);
    //    }
    }

    Colisao::~Colisao(){
        //*eFix = nullptr;
        //*eMov = nullptr;
    }

    void Colisao::colidiu(){
        //Calculo::Calculadora::CoordF intersect;
        //Calculo::Calculadora::CoordF centerDistance;
        //int i, j;
        //for (i = 0; i < entidadeFixa->getSize(); i++) {
        //    for (j = 0; j < entidadesMoveis->getSize(); j++) {
        //        ent1 = (*entidadesFixas)[i];
        //        ent2 = (*entidadesMoveis)[j];

        //        centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
        //        centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

        //        intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
        //        intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);

        //        if (intersect.x < 0.0f && intersect.y < 0.0f) {
        //            ent2->collide(ent1, intersect);
        //        }
        //    }
        //}
        //for (i = 0; i < entidadesMoveis->getSize(); i++){
        //    for (j = i + 1; j < entidadesMoveis->getSize(); j++) {
        //        ent1 = (*entidadesMoveis)[i];
        //        ent2 = (*entidadesMoveis)[j];

        //        centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
        //        centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

        //        intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
        //        intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);

        //        if (intersect.x < 0.0f && intersect.y < 0.0f){
        //            ent2->collide(ent1, intersect);
        //            ent1->collide(ent2, intersect);
        //        }
        //    }
        //}
        //clear();
    }
}