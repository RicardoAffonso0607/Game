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
        Entidade* ent;
        int i, j;//ent1=móvel ent2=fixo ou móvel
        for (i = 0; i < list_ent->getSize(); i++) {
            ent = dynamic_cast<Entidade*>(list_ent->getEntity(i));
            ent->flying = true;
            ent->allow_jump = true;
            if (ent->getMovable()) {
                for (j = 0; j < list_ent->getSize(); j++)
                    if (j != i)
                        collide(ent, dynamic_cast<Entidade*>(list_ent->getEntity(j)));
                if (ent->flying) {
                    gravity(ent);
                    ent->allow_jump = false;
                }
                if (ent->getJumped())
                    jump(ent);
                ent->colidiu_cima = false;
                ent->colidiu_baixo = false;
            }
        }
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2) {
        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
        cg1 = ent1->getPosition() + .5f * ent1->getEntSize();
        cg2 = ent2->getPosition() + .5f * ent2->getEntSize();
        centerDistance = sf::Vector2f(fabs(cg2.x - cg1.x), fabs(cg2.y - cg1.y));
        centerSum = .5f * (ent2->getEntSize() + ent1->getEntSize());
        sobre = centerSum - centerDistance;
        /* se colidiu */
        if ((sobre.x > 0 && sobre.y > 0) || (sobre.x > 0 && !centerDistance.y) || (sobre.y > 0 && !centerDistance.x)) {
            effects(ent1, ent2);//aplica dano e lentidão
            ricochet(ent1, ent2, sobre);//volta a posição sem sobreposição
        }
        /* se apoiado em cima de outro */
        if (ent1->getPosition().y + ent1->getEntSize().y >= ent2->getPosition().y && ent1->getPosition().y + ent1->getEntSize().y <= ent2->getPosition().y+ent2->getEntSize().y && ent1->getPosition().x>ent2->getPosition().x - ent1->getEntSize().x && ent1->getPosition().x < ent2->getPosition().x + ent2->getEntSize().x)
            ent1->flying = false;
    }
    
    /* Vértices do retângulo */
    struct Colisao::vertex{
        sf::Vector2f ul, ur, bl, br;
    };

    /* Encontra os vértices do retângulo */
    void Colisao::vertexMath(vertex *rect, Entidade *ent){
        rect->ul = ent->getPosition();//up left
        rect->ur = rect->ul + sf::Vector2f(ent->getEntSize().x, 0.f);//up right
        rect->bl = rect->ul + sf::Vector2f(0.f,ent->getEntSize().y);//bottom left
        rect->br = rect->bl + sf::Vector2f(ent->getEntSize().x, 0.f);//bottom right
    }

    /* Ao andar e sobrepor um fixo, volta à posição só encostado, e se for um móvel, empurra */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre) {
        vertex e1, e2;
        vertexMath(&e1, ent1);
        vertexMath(&e2, ent2);
        if (!ent2->getMovable()) {//1 móvel e 2 fixo
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y) {//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
                }
                else//direita cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y) {//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
                }
                else//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                ent1->colidiu_baixo = true;
                ent2->colidiu_cima = true;
            }
            else {//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                ent1->colidiu_cima = true;
                ent2->colidiu_baixo = true;
            }
        }
        else {//ambos móveis
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita ent1 entre vértices
                    ent1->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y){//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
                }
                else{//direita ent1 cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x){
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y){//esquerda entre vértices
                    ent1->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y){//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
                }
                else{//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                }
            }
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                ent1->colidiu_baixo = true;
                ent2->colidiu_cima = true;
            }
            else{//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                ent1->colidiu_cima = true;
                ent2->colidiu_baixo = true;
            }
        }
    }

    /* Efeitos causados pela colisão */
    void Colisao::effects(Entidade* ent1, Entidade* ent2){
        //if (colidiu) {
        //    if (ent1->getDamageable() && ent2->getAttacker())
        //        ent1->subtractLife(ent2->getDamage());
        //    if (ent1->getAttacker() && ent2->getDamageable())
        //        ent2->subtractLife(ent1->getDamage());
        //    if (ent1->getMovable() && !ent1->getRetarded() && ent2->getRetarder()) {
        //        ent1->subtractVelocity(ent2->getRetarder());
        //        ent1->setRetarded();
        //    }
        //    if (ent1->getRetarder() && !ent2->getRetarded() && ent2->getMovable()) {
        //        ent2->subtractVelocity(ent1->getRetarder());
        //        ent2->setRetarded();
        //    }
        //    if(ent1->getMovable()&&!ent2->getRetarder())
        //        ent1->unsetRetarded();
        //    if (ent1->getRetarder() && !ent2->getMovable())
        //        ent2->unsetRetarded();
        //}
        //else {
        //    if (ent1->getRetarder())
        //        ent1->unsetRetarded();
        //    if (ent2->getRetarder())
        //        ent2->unsetRetarded();
        //}
    }

    /* Aceleração da gravidade */
    void Colisao::gravity(Entidade* ent){
        if(ent->getPosition().y < 1.5f*ger_graf->getWindowSize().y)
            ent->changePosition(sf::Vector2f(0.f, ent->getMass()*GRAVITY));
    }

    /* Pulo */
    void Colisao::jump(Entidade* ent){
        if (!ent->colidiu_cima && ent->jumped_height < ent->getJumpStrength() && ent->getVel().y > ent->getMass()*GRAVITY) {
            ent->changePosition(sf::Vector2f(0.f, -ent->getVel().y);
            ent->jumped_height += ent->getVel().y;
            ent->allow_jump = false;
        }
        else if (ent->colidiu_baixo) {
            //printf("entrou2\n");
            ent->jumped = false;
            ent->allow_jump = true;
            ent->jumped_height = 0.f;
        }
    }

    /* Funcionamento de um projétil */
    void Colisao::trajectory(Entidade* ent){
        //if (ent->getProjetil())
        //    if (ent->pCaster->getFacingLeft())
        //        ent->changePosition(sf::Vector2f(-DX_PROJECTILE, 0.f));
    }
}
