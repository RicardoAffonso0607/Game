#include "pch.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Grafico.h"

namespace Gerenciador{
    Colisao::Colisao(ListaEntidades* lista, Grafico* graf):
        list_ent(lista),
        ger_graf(graf)
    {
    }

    Colisao::~Colisao()
    {
    }

    /* Verifica se a colisão entre as entidades é possível */
    void Colisao::executar() {
        int i, j;//ent1=móvel ent2=fixo ou móvel
        for (i = 0; i < list_ent->getSize(); i++) {
            if (list_ent->getEntity(i)->getMovable()) {
                list_ent->getEntity(i)->setFlying();
                for (j = 0; j < list_ent->getSize(); j++)
                    if (j != i){
                        //if (list_ent->getEntity(i)->getGhost())
                        //    list_ent->getEntity(i)->colidiu = false;
                        //if(list_ent->getEntity(j)->getGhost())
                        //    list_ent->getEntity(j)->colidiu = false;
                        collide(list_ent->getEntity(i), list_ent->getEntity(j));
                       //cout<< list_ent->getEntity(i)->getId()<<list_ent->getEntity(j)->getId()<<endl;
                    }
                if (list_ent->getEntity(i)->flying) {
                    //printf("acionou gravidade\n");
                    gravity(list_ent->getEntity(i));
                    list_ent->getEntity(i)->unsetAllowJump();
                }
                else {
                    list_ent->getEntity(i)->setColidiuBaixo();
                    list_ent->getEntity(i)->unsetJumped();
                    list_ent->getEntity(i)->setAllowJump();
                }
                if (list_ent->getEntity(i)->getJumped())
                {
                    jump(list_ent->getEntity(i));
                }
                //list_ent->getEntity(i)->unsetColidiuCima();
                //list_ent->getEntity(i)->unsetColidiuBaixo();
            }
        }
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2) {
        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
        cg1 = ent1->getPos() + .5f * ent1->getEntSize();
        cg2 = ent2->getPos() + .5f * ent2->getEntSize();
        centerDistance = sf::Vector2f(fabs(cg2.x - cg1.x), fabs(cg2.y - cg1.y));
        centerSum = .5f * (ent2->getEntSize() + ent1->getEntSize());
        sobre = centerSum - centerDistance;
        /* se colidiu */
        if ((sobre.x > 0 && sobre.y > 0) || (sobre.x > 0 && !centerDistance.y) || (sobre.y > 0 && !centerDistance.x)) {
            //effects(ent1, ent2);//aplica dano e lentidão
            if (!ent1->getGhost() && !ent2->getGhost())
                ricochet(ent1, ent2, sobre);//volta a posição sem sobreposição
            else if (ent1->getGhost()) {
                cout << "mudou colidiu pra true" << endl;
                ent1->setColidiu();
                ent1->setEntColidiu(ent2);
                //cout << (ent1->colidiu ? 1 : 0) << endl;
            }
            else {
                cout << "mudou colidiu2 pra true" << endl;
                ent2->setColidiu();
                ent2->setEntColidiu(ent1);
                //cout << (ent2->colidiu ? 1 : 0) << endl;
            }
            //ent1->unsetFlying();
        }
        /* se apoiado em cima de outro */
        if (sobre.x > 0 && sobre.y <= ent1->getMass() * ACEL_GRAV && sobre.y >= -1.f) {
            ent1->unsetFlying();
            //cout << "acionou flying false" << endl;
        }
    }
    
    /* Vértices do retângulo */
    struct Colisao::vertex{
        sf::Vector2f ul, ur, bl, br;
    };

    /* Encontra os vértices do retângulo */
    void Colisao::vertexMath(vertex *rect, Entidade *ent){
        rect->ul = ent->getPos();//up left
        rect->ur = rect->ul + sf::Vector2f(ent->getEntSize().x, 0.f);//up right
        rect->bl = rect->ul + sf::Vector2f(0.f,ent->getEntSize().y);//bottom left
        rect->br = rect->bl + sf::Vector2f(ent->getEntSize().x, 0.f);//bottom right
    }

    /* Ao andar e sobrepor um fixo, volta à posição só encostado, e se for um móvel, empurra */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre) {//onde de ent2 foi colidido com ent1
        vertex e1, e2;
        vertexMath(&e1, ent1);
        vertexMath(&e2, ent2);
        if (!ent2->getMovable()) {//1 móvel e 2 fixo
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y) {//direita entre vértices
                    ent1->changePos(sf::Vector2f(sobre.x, 0.f));
                    cout << "direita entre vértices" << endl;
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y) {//cima canto direito
                    ent1->changePos(sf::Vector2f(0.f, -sobre.y));
                    ent1->setColidiuBaixo();
                    ent2->setColidiuCima();
                    cout << "cima canto direito" << endl;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
                    ent1->setColidiuCima();
                    ent2->setColidiuBaixo();
                    cout << "baixo canto direito" << endl;
                }
                else {//direita cantos superior e inferior
                    ent1->changePos(sf::Vector2f(sobre.x, 0.f));
                    cout << "direita cantos superior e inferior" << endl;
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y) {//esquerda entre vértices
                    ent1->changePos(sf::Vector2f(-sobre.x, 0.f));
                    cout << "esquerda entre vértices" << endl;
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y) {//cima canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, -sobre.y));
                    ent1->setColidiuBaixo();
                    ent2->setColidiuCima();
                    cout << "cima canto esquerdo" << endl;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
                    ent1->setColidiuCima();
                    ent2->setColidiuBaixo();
                    cout << "baixo canto esquerdo" << endl;
                }
                else {//esquerda cantos superior e inferior
                    ent1->changePos(sf::Vector2f(-sobre.x, 0.f));
                    cout << "esquerda cantos superior e inferior" << endl;
                }
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePos(sf::Vector2f(0.f, -sobre.y));
                ent1->setColidiuBaixo();
                ent2->setColidiuCima();
                cout << "cima entre vértices" << endl;
            }
            else {//baixo entre vértices
                ent1->changePos(sf::Vector2f(0.f, sobre.y));
                ent1->setColidiuCima();
                ent2->setColidiuBaixo();
                cout << "baixo entre vértices" << endl;
            }
        }
        else {//ambos móveis
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita entre vértices
                    ent1->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent2->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    cout << "direita entre vértices" << endl;
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y){//cima canto direito
                    ent1->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent1->setColidiuBaixo();
                    ent2->setColidiuCima();
                    cout << "cima canto direito" << endl;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->setColidiuCima();
                    ent2->setColidiuBaixo();
                    cout << "baixo canto direito" << endl;
                }
                else{//direita cantos superior e inferior
                    ent1->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent2->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    cout << "direita cantos superior e inferior" << endl;
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x){
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y){//esquerda entre vértices
                    ent1->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent2->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    cout << "esquerda entre vértices" << endl;
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y){//cima canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent1->setColidiuBaixo();
                    ent2->setColidiuCima();
                    cout << "cima canto esquerdo" << endl;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->setColidiuCima();
                    ent2->setColidiuBaixo();
                    cout << "baixo canto esquerdo" << endl;
                }
                else{//esquerda cantos superior e inferior
                    ent1->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent2->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    cout << "esquerda cantos superior e inferior" << endl;
                }
            }
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                ent2->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                ent1->setColidiuBaixo();
                ent2->setColidiuCima();
                cout << "cima entre vértices" << endl;
            }
            else{//baixo entre vértices
                ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                ent1->setColidiuCima();
                ent2->setColidiuBaixo();
                cout << "baixo entre vértices" << endl;
            }
        }
    }

    /* Efeitos causados pela colisão */
    void Colisao::effects(Entidade* ent1, Entidade* ent2){
        if (ent1->getDamageable() && ent2->getAttacker()) {
            ent1->applyDamage(ent2->getDamage());
            ent2->setAtacou();
        }
        if (ent1->getAttacker() && ent2->getDamageable()) {
            ent2->applyDamage(ent1->getDamage());
            ent1->setAtacou();
        }
        if (ent1->getRetardable() && !ent2->getMovable() && ent2->getRetardant())
            ent1->applySlowness(ent2->getSlowness());
    }

    /* Aceleração da gravidade */
    void Colisao::gravity(Entidade* ent){
        if(ent->getPos().y < 1.5f*ger_graf->getWindowSize().y)
            ent->changePos(sf::Vector2f(0.f, ent->getMass()*ACEL_GRAV));
    }

    /* Pulo */
    void Colisao::jump(Entidade* ent){
        if (!ent->getColidiuCima() && ent->getJumpedHeight() < ent->getJumpStrength() && ent->getVel().y > ent->getMass() * ACEL_GRAV) {
            ent->changePos(sf::Vector2f(0.f, -ent->getVel().y));
            ent->setJumpedHeight(ent->getJumpedHeight()+ent->getVel().y);
            ent->unsetAllowJump();
        }
        if (ent->getColidiuBaixo())
        {
            ent->unsetJumped();
            ent->setAllowJump();
            ent->setJumpedHeight(0.f);
            ent->unsetColidiuBaixo();
            ent->unsetColidiuCima();
        }
    }
}
