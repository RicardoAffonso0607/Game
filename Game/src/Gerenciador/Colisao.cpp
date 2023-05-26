#include "pch.h"
#include "Gerenciador/Colisao.h"

#define GRAVITY 5.5f
#define H_PULO 200.f
#define DY_PULO 20.f

namespace Gerenciador{
    Colisao::Colisao(){}

    Colisao::~Colisao(){}

    /* Verifica se a colis�o entre as entidades � poss�vel */
    void Colisao::collided(ListaEntidades* list_ent){
        int i, j;
        for (i = 0; i < list_ent->getSize(); i++) {
            if (list_ent->getEntity(i)->isMovable())
                for (j = i; j < list_ent->getSize(); j++)
                    if(list_ent->getEntity(i) != list_ent->getEntity(j))
                        collide(list_ent->getEntity(i), list_ent->getEntity(j));
        }
    }

    /* A colis�o ocorre quando entre centros a dist�ncia x � menor que soma das
       larguras/2 e a dist�ncia y � menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2){
        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
        cg1 = ent1->getPosition() + .5f*ent1->getEntSize();
        cg2 = ent2->getPosition() + .5f*ent2->getEntSize();
        centerDistance.x = fabs(cg2.x - cg1.x);
        centerDistance.y = fabs(cg2.y - cg1.y);
        centerSum.x = .5f*(ent2->getEntSize().x + ent1->getEntSize().x);
        centerSum.y = .5f*(ent2->getEntSize().y + ent1->getEntSize().y);
        sobre = centerSum - centerDistance;
        if(ent1->isJumped() && centerDistance.y<H_PULO)
            jump(ent1);//aplica pulo
        if(ent2->isJumped() && centerDistance.y<H_PULO)
            jump(ent2);
        if((centerDistance.y>centerSum.y || centerDistance.x>=centerSum.x) && ent1->getPosition().y<1500 && ent2->getPosition().y<1500)
            gravity(ent1, ent2);//aplica gravidade
        if((sobre.x>0 && sobre.y>0)||(sobre.x>0 && !centerDistance.y)||(sobre.y>0 && !centerDistance.x)) {// colidiu
            effects(ent1, ent2);//aplica dano e lentid�o
            ricochet(ent1, ent2, sobre);//volta a posi��o sem sobreposi��o
        }
    }

    /* V�rtices do ret�ngulo */
    struct Colisao::vertex{
        sf::Vector2f ul, ur, bl, br;
    };

    /* Encontra os v�rtices do ret�ngulo */
    void Colisao::vertexMath(vertex *rect, Entidade *ent){
        rect->ul = ent->getPosition();//up left
        rect->ur = rect->ul + sf::Vector2f(ent->getEntSize().x, 0.f);//up right
        rect->bl = rect->ul + sf::Vector2f(0.f,ent->getEntSize().y);//bottom left
        rect->br = rect->bl + sf::Vector2f(ent->getEntSize().x, 0.f);//bottom right
    }

    /* Ao andar e sobrepor um fixo, volta � posi��o s� encostado, e se for um m�vel, empurra */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre) {
        vertex e1, e2;
        vertexMath(&e1, ent1);
        vertexMath(&e2, ent2);
        if (ent1->isMovable() && !ent2->isMovable()) {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre v�rtices
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                else//direita cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre v�rtices
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x)//cima entre v�rtices
                ent1->changePosition(sf::Vector2f(0.f, -sobre.y));
            else//baixo entre v�rtices
                ent1->changePosition(sf::Vector2f(0.f, sobre.y));
        }
        else if (!ent1->isMovable() && ent2->isMovable()){
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre v�rtices
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent2->changePosition(sf::Vector2f(0.f, sobre.y));
                else//direita cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre v�rtices
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x)//cima entre v�rtices
                ent2->changePosition(sf::Vector2f(0.f, -sobre.y));
            else//baixo entre v�rtices
                ent2->changePosition(sf::Vector2f(0.f, sobre.y));
        }
        else {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita entre v�rtices
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
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y){//esquerda entre v�rtices
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
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre v�rtices
                ent1->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, .5f*sobre.y));
            }
            else{//baixo entre v�rtices
                ent1->changePosition(sf::Vector2f(0.f, 0.f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.f, -.5f*sobre.y));
            }
        }
    }

    /* Efeitos causados pela colis�o */
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

    /* Acelera��o da gravidade */
    void Colisao::gravity(Entidade* ent1, Entidade* ent2){
        if (ent1->isMovable())
            ent1->changePosition(sf::Vector2f(0.f, GRAVITY));
        else
            ent2->changePosition(sf::Vector2f(0.f, GRAVITY));
    }

    /* Pulo */
    void Colisao::jump(Entidade* ent){
        ent->changePosition(sf::Vector2f(0.f, -DY_PULO));
    }

    /* Funcionamento de um proj�til */
    void Colisao::trajectory(Entidade* ent){

    }
}