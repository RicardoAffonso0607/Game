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
                        collide(vector<Entidade*>{list_ent->getEntity(i), list_ent->getEntity(j)});
                    }
                if (list_ent->getEntity(i)->getFlying()) {
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
            }
        }
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(vector<Entidade*> ent) {
        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
        cg1 = ent[0]->getPos() + .5f * ent[0]->getEntSize();
        cg2 = ent[1]->getPos() + .5f * ent[1]->getEntSize();
        centerDistance = sf::Vector2f(fabs(cg2.x - cg1.x), fabs(cg2.y - cg1.y));
        centerSum = .5f * (ent[1]->getEntSize() + ent[0]->getEntSize());
        sobre = centerSum - centerDistance;
        /* se colidiu */
        if ((sobre.x > 0 && sobre.y > 0) || (sobre.x > 0 && !centerDistance.y) || (sobre.y > 0 && !centerDistance.x)) {
            if (!ent[0]->getGhost() && !ent[1]->getGhost())
                ricochet(ent, sobre);//volta a posição sem sobreposição
            else if (ent[0]->getGhost()) {
                ent[0]->setColidiu();
                ent[0]->setEntColidiu(ent[1]);
            }
            else {
                ent[1]->setColidiu();
                ent[1]->setEntColidiu(ent[0]);
            }
        }
        /* se apoiado em cima de outro */
        if (sobre.x > 0 && sobre.y <= ent[0]->getMass() * ACEL_GRAV && sobre.y >= 0) {
            if (!ent[1]->getMovable() && (ent[1]->getRetardant() || ent[1]->getAttacker())) {
                ent[0]->setColidiu();
                ent[0]->setEntColidiu(ent[1]);
            }
            ent[0]->unsetFlying();
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
    void Colisao::ricochet(vector<Entidade*> ent, sf::Vector2f sobre) {//onde de ent[1] foi colidido com ent[0]
        vertex e1, e2;
        vertexMath(&e1, ent[0]);
        vertexMath(&e2, ent[1]);
        if (!ent[1]->getMovable()) {//1 móvel e 2 fixo
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y) {//direita entre vértices
                    ent[0]->changePos(sf::Vector2f(sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y) {//cima canto direito
                    ent[0]->changePos(sf::Vector2f(0.f, -sobre.y));
                    ent[0]->setColidiuBaixo();
                    ent[1]->setColidiuCima();
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
                    ent[0]->changePos(sf::Vector2f(0.f, sobre.y));
                    ent[0]->setColidiuCima();
                    ent[1]->setColidiuBaixo();
                }
                else {//direita cantos superior e inferior
                    ent[0]->changePos(sf::Vector2f(sobre.x, 0.f));
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y) {//esquerda entre vértices
                    ent[0]->changePos(sf::Vector2f(-sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y) {//cima canto esquerdo
                    ent[0]->changePos(sf::Vector2f(0.f, -sobre.y));
                    ent[0]->setColidiuBaixo();
                    ent[1]->setColidiuCima();
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
                    ent[0]->changePos(sf::Vector2f(0.f, sobre.y));
                    ent[0]->setColidiuCima();
                    ent[1]->setColidiuBaixo();
                }
                else {//esquerda cantos superior e inferior
                    ent[0]->changePos(sf::Vector2f(-sobre.x, 0.f));
                }
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent[0]->changePos(sf::Vector2f(0.f, -sobre.y));
                ent[0]->setColidiuBaixo();
                ent[1]->setColidiuCima();
            }
            else {//baixo entre vértices
                ent[0]->changePos(sf::Vector2f(0.f, sobre.y));
                ent[0]->setColidiuCima();
                ent[1]->setColidiuBaixo();
            }
        }
        else {//ambos móveis
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita entre vértices
                    ent[0]->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent[1]->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y){//cima canto direito
                    ent[0]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent[1]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent[0]->setColidiuBaixo();
                    ent[1]->setColidiuCima();
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent[0]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent[1]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent[0]->setColidiuCima();
                    ent[1]->setColidiuBaixo();
                }
                else{//direita cantos superior e inferior
                    ent[0]->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent[1]->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x){
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y){//esquerda entre vértices
                    ent[0]->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent[1]->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y){//cima canto esquerdo
                    ent[0]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent[1]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent[0]->setColidiuBaixo();
                    ent[1]->setColidiuCima();
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent[0]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent[1]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent[0]->setColidiuCima();
                    ent[1]->setColidiuBaixo();
                }
                else{//esquerda cantos superior e inferior
                    ent[0]->changePos(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent[1]->changePos(sf::Vector2f(.5f*sobre.x, 0.f));
                }
            }
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent[0]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                ent[1]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                ent[0]->setColidiuBaixo();
                ent[1]->setColidiuCima();
            }
            else{//baixo entre vértices
                ent[0]->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                ent[1]->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                ent[0]->setColidiuCima();
                ent[1]->setColidiuBaixo();
            }
        }
    }

    /* Aceleração da gravidade */
    void Colisao::gravity(Entidade* ent){
        if (ent->getPos().y < ger_graf->getWindowSize().y)
            ent->changePos(sf::Vector2f(0.f, ent->getMass() * ACEL_GRAV));
        else
            ent->applyDamage(1000);
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
