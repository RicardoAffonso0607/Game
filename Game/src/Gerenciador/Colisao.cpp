#include "pch.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Grafico.h"

#define GRAVITY .98f
#define HMAX_PULO 100.f
#define DY_PULO 2.f
#define DX_PROJECTILE 10.f

namespace Gerenciador{
    Colisao::Colisao(ListaEntidades* list, Grafico* graf)
    {
       list_ent = list;
       ger_graf = graf;
    }

    Colisao::~Colisao()
    {
        list_ent = nullptr;
        ger_graf = nullptr;
    }

    /* Verifica se a colisão entre as entidades é possível */
    void Colisao::executar(){
        int i, j;
        for (i=0; i<list_ent->getSize(); i++)
            if (list_ent->getEntity(i)->isMovable())
                for (j = i + 1; j < list_ent->getSize(); j++)
                    collide(list_ent->getEntity(i), list_ent->getEntity(j));
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
        if((sobre.x>0 && sobre.y>0)||(sobre.x>0 && !centerDistance.y)||(sobre.y>0 && !centerDistance.x)) {
            effects(ent1, ent2);//aplica dano e lentidão
            ricochet(ent1, ent2, sobre);//volta a posição sem sobreposição
        }
        else{//aplica gravidade
            gravity(ent1);
            gravity(ent2);
        }
        //if (centerDistance.y <= centerSum.y) {//aplica pulo
            jump(ent1);
            jump(ent2);
        //}
        colidiu = false;
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
        ent1->colidiu = true;
        ent2->colidiu = true;
        vertex e1, e2;
        vertexMath(&e1, ent1);
        vertexMath(&e2, ent2);
        if (ent1->isMovable() && !ent2->isMovable()) {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                else//direita cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x)//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
            else//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.f, sobre.y));
        }
        else if (!ent1->isMovable() && ent2->isMovable()) {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent2->changePosition(sf::Vector2f(0.f, sobre.y));
                else//direita cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
            }
            else//baixo entre vértices
                ent2->changePosition(sf::Vector2f(0.f, sobre.y));
        }
        else {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita entre vértices
                    ent1->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y){//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                }
                else{//direita cantos superior e inferior
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
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                }
                else{//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-.5f*sobre.x, 0.f));
                    ent2->changePosition(sf::Vector2f(.5f*sobre.x, 0.f));
                }
            }
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
            }
            else{//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
            }
        }
    }

    /* Efeitos causados pela colisão */
    void Colisao::effects(Entidade* ent1, Entidade* ent2){
        //if (colidiu) {
        //    if (ent1->isDamageable() && ent2->isAttacker())
        //        ent1->subtractLife(ent2->getDamage());
        //    if (ent1->isAttacker() && ent2->isDamageable())
        //        ent2->subtractLife(ent1->getDamage());
        //    if (ent1->isMovable() && !ent1->isRetarded() && ent2->isRetarder()) {
        //        ent1->subtractVelocity(ent2->getRetarder());
        //        ent1->setRetarded();
        //    }
        //    if (ent1->isRetarder() && !ent2->isRetarded() && ent2->isMovable()) {
        //        ent2->subtractVelocity(ent1->getRetarder());
        //        ent2->setRetarded();
        //    }
        //    if(ent1->isMovable()&&!ent2->isRetarder())
        //        ent1->unsetRetarded();
        //    if (ent1->isRetarder() && !ent2->isMovable())
        //        ent2->unsetRetarded();
        //}
        //else {
        //    if (ent1->isRetarder())
        //        ent1->unsetRetarded();
        //    if (ent2->isRetarder())
        //        ent2->unsetRetarded();
        //}
    }

    /* Aceleração da gravidade */
    void Colisao::gravity(Entidade* ent){
        if (ent->isMovable() && ent->getPosition().y < 1.5f*ger_graf->getWindowHeight()) {
            ent->changePosition(sf::Vector2f(0.f, GRAVITY));
        }
    }

    /* Pulo */
    void Colisao::jump(Entidade* ent){
        if (ent->isJumped() && /*!ent->colidiu && */ ent->jumped_height<HMAX_PULO) {
            ent->changePosition(sf::Vector2f(0.f, -DY_PULO));
            ent->jumped_height += DY_PULO;
            //ent->
        }
        if (ent->jumped_height >= HMAX_PULO) {
            ent->jumped = false;
           // if (ent->jumped_height == -1.f)
                //ent->colidiu = false;
            //if(ent->colidiu)
                ent->jumped_height = 0.f;
        }
    }

    /* Funcionamento de um projétil */
    void Colisao::trajectory(Entidade* ent){
        //if (ent->isProjectile())
        //    if (ent->pCaster->isFacingLeft())
        //        ent->changePosition(sf::Vector2f(-DX_PROJECTILE, 0.f));
    }
}
