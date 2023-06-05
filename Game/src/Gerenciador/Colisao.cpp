//#include "pch.h"
//#include "Gerenciador/Colisao.h"
//#include "Gerenciador/Grafico.h"
//
//constexpr auto GRAVITY = 9.8f, HMAX_PULO = 150.f, DX_PROJECTILE = 10.f;
//
//namespace Gerenciador {
//    Colisao::Colisao(ListaEntidades* list_ent, Grafico* ger_graf)
//    {
//        this->list_ent = list_ent;
//        this->ger_graf = ger_graf;
//    }
//
//    Colisao::~Colisao()
//    {
//        this->list_ent = nullptr;
//        this->ger_graf = nullptr;
//    }
//
//    /* Verifica se a colisão entre as entidades é possível */
//    void Colisao::executar() {
//        Entidade* ent;
//        int i, j;//ent1=móvel ent2=fixo ou móvel
//        for (i = 0; i < list_ent->getSize(); i++) {
//            ent = list_ent->getEntity(i);
//            ent->flying = true;
//            ent->allow_jump = true;
//            if (ent->getMovable()) {
//                for (j = 0; j < list_ent->getSize(); j++)
//                    if (j != i)
//                        collide(ent, list_ent->getEntity(j));
//                if (ent->flying) {
//                    gravity(ent);
//                    ent->allow_jump = false;
//                }
//                if (ent->getJumped())
//                    jump(ent);
//                ent->colidiu_cima = false;
//                ent->colidiu_baixo = false;
//            }
//        }
//    }
//
//    /* A colisão ocorre quando entre centros a distância x é menor que soma das
//       larguras/2 e a distância y é menor que soma das alturas/2 */
//    void Colisao::collide(Entidade* ent1, Entidade* ent2) {
//        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
//        cg1 = ent1->getPos() + .5f * ent1->getEntSize();
//        cg2 = ent2->getPos() + .5f * ent2->getEntSize();
//        centerDistance = sf::Vector2f(fabs(cg2.x - cg1.x), fabs(cg2.y - cg1.y));
//        centerSum = .5f * (ent2->getEntSize() + ent1->getEntSize());
//        sobre = centerSum - centerDistance;
//        /* se colidiu */
//        if ((sobre.x > 0 && sobre.y > 0) || (sobre.x > 0 && !centerDistance.y) || (sobre.y > 0 && !centerDistance.x)) {
//            effects(ent1, ent2);//aplica dano e lentidão
//            ricochet(ent1, ent2, sobre);//volta a posição sem sobreposição
//        }
//        /* se apoiado em cima de outro */
//        if (ent1->getPos().y + ent1->getEntSize().y >= ent2->getPos().y && ent1->getPos().y + ent1->getEntSize().y <= ent2->getPos().y + ent2->getEntSize().y && ent1->getPos().x > ent2->getPos().x - ent1->getEntSize().x && ent1->getPos().x < ent2->getPos().x + ent2->getEntSize().x)
//            ent1->flying = false;
//    }
//
//    /* Vértices do retângulo */
//    struct Colisao::vertex {
//        sf::Vector2f ul, ur, bl, br;
//    };
//
//    /* Encontra os vértices do retângulo */
//    void Colisao::vertexMath(vertex* rect, Entidade* ent) {
//        rect->ul = ent->getPos();//up left
//        rect->ur = rect->ul + sf::Vector2f(ent->getEntSize().x, 0.f);//up right
//        rect->bl = rect->ul + sf::Vector2f(0.f, ent->getEntSize().y);//bottom left
//        rect->br = rect->bl + sf::Vector2f(ent->getEntSize().x, 0.f);//bottom right
//    }
//
//    /* Ao andar e sobrepor um fixo, volta à posição só encostado, e se for um móvel, empurra */
//    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre) {
//        vertex e1, e2;
//        vertexMath(&e1, ent1);
//        vertexMath(&e2, ent2);
//        if (!ent2->getMovable()) {//1 móvel e 2 fixo
//            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
//                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
//                    ent1->changePos(sf::Vector2f(sobre.x, 0.f));
//                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y) {//cima canto direito
//                    ent1->changePos(sf::Vector2f(0.f, -sobre.y));
//                    ent1->colidiu_baixo = true;
//                    ent2->colidiu_cima = true;
//                }
//                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
//                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
//                    ent1->colidiu_cima = true;
//                    ent2->colidiu_baixo = true;
//                }
//                else//direita cantos superior e inferior
//                    ent1->changePos(sf::Vector2f(sobre.x, 0.f));
//            }
//            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
//                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
//                    ent1->changePos(sf::Vector2f(-sobre.x, 0.f));
//                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y) {//cima canto esquerdo
//                    ent1->changePos(sf::Vector2f(0.f, -sobre.y));
//                    ent1->colidiu_baixo = true;
//                    ent2->colidiu_cima = true;
//                }
//                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
//                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
//                    ent1->colidiu_cima = true;
//                    ent2->colidiu_baixo = true;
//                }
//                else//esquerda cantos superior e inferior
//                    ent1->changePos(sf::Vector2f(-sobre.x, 0.f));
//            }
//            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x) {//cima entre vértices
//                ent1->changePos(sf::Vector2f(0.f, -sobre.y));
//                ent1->colidiu_baixo = true;
//                ent2->colidiu_cima = true;
//            }
//            else {//baixo entre vértices
//                ent1->changePos(sf::Vector2f(0.f, sobre.y));
//                ent1->colidiu_cima = true;
//                ent2->colidiu_baixo = true;
//            }
//        }
//        else {//ambos móveis
//            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
//                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y) {//direita ent1 entre vértices
//                    ent1->changePos(sf::Vector2f(.5f * sobre.x, 0.f));
//                    ent2->changePos(sf::Vector2f(-.5f * sobre.x, 0.f));
//                }
//                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y) {//cima canto direito
//                    ent1->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                    ent2->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                    ent1->colidiu_baixo = true;
//                    ent2->colidiu_cima = true;
//                }
//                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
//                    ent1->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                    ent2->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                    ent1->colidiu_cima = true;
//                    ent2->colidiu_baixo = true;
//                }
//                else {//direita ent1 cantos superior e inferior
//                    ent1->changePos(sf::Vector2f(.5f * sobre.x, 0.f));
//                    ent2->changePos(sf::Vector2f(-.5f * sobre.x, 0.f));
//                }
//            }
//            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
//                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y) {//esquerda entre vértices
//                    ent1->changePos(sf::Vector2f(-.5f * sobre.x, 0.f));
//                    ent2->changePos(sf::Vector2f(.5f * sobre.x, 0.f));
//                }
//                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y) {//cima canto esquerdo
//                    ent1->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                    ent2->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                    ent1->colidiu_baixo = true;
//                    ent2->colidiu_cima = true;
//                }
//                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
//                    ent1->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                    ent2->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                    ent1->colidiu_cima = true;
//                    ent2->colidiu_baixo = true;
//                }
//                else {//esquerda cantos superior e inferior
//                    ent1->changePos(sf::Vector2f(-.5f * sobre.x, 0.f));
//                    ent2->changePos(sf::Vector2f(.5f * sobre.x, 0.f));
//                }
//            }
//            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x) {//cima entre vértices
//                ent1->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                ent2->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                ent1->colidiu_baixo = true;
//                ent2->colidiu_cima = true;
//            }
//            else {//baixo entre vértices
//                ent1->changePos(sf::Vector2f(0.f, .5f * sobre.y));
//                ent2->changePos(sf::Vector2f(0.f, -.5f * sobre.y));
//                ent1->colidiu_cima = true;
//                ent2->colidiu_baixo = true;
//            }
//        }
//    }
//
//    /* Efeitos causados pela colisão */
//    void Colisao::effects(Entidade* ent1, Entidade* ent2) {
//        //if (colidiu) {
//        //    if (ent1->getDamageable() && ent2->getAttacker())
//        //        ent1->subtractLife(ent2->getDamage());
//        //    if (ent1->getAttacker() && ent2->getDamageable())
//        //        ent2->subtractLife(ent1->getDamage());
//        //    if (ent1->getMovable() && !ent1->getRetarded() && ent2->getRetarder()) {
//        //        ent1->subtractVelocity(ent2->getRetarder());
//        //        ent1->setRetarded();
//        //    }
//        //    if (ent1->getRetarder() && !ent2->getRetarded() && ent2->getMovable()) {
//        //        ent2->subtractVelocity(ent1->getRetarder());
//        //        ent2->setRetarded();
//        //    }
//        //    if(ent1->getMovable()&&!ent2->getRetarder())
//        //        ent1->unsetRetarded();
//        //    if (ent1->getRetarder() && !ent2->getMovable())
//        //        ent2->unsetRetarded();
//        //}
//        //else {
//        //    if (ent1->getRetarder())
//        //        ent1->unsetRetarded();
//        //    if (ent2->getRetarder())
//        //        ent2->unsetRetarded();
//        //}
//    }
//
//    /* Aceleração da gravidade */
//    void Colisao::gravity(Entidade* ent) {
//        if (ent->getPos().y < 1.5f * ger_graf->getWindowSize().y)
//            ent->changePos(sf::Vector2f(0.f, ent->getMass() * GRAVITY));
//    }
//
//    /* Pulo */
//    void Colisao::jump(Entidade* ent) {
//        if (!ent->colidiu_cima && ent->jumped_height < HMAX_PULO) {
//            ent->changePos(sf::Vector2f(0.f, -2 * ent->getMass() * GRAVITY));
//            ent->jumped_height += ent->getMass() * GRAVITY;
//            ent->allow_jump = false;
//        }
//        else if (ent->colidiu_baixo) {
//            //printf("entrou2\n");
//            ent->jumped = false;
//            ent->allow_jump = true;
//            ent->jumped_height = 0.f;
//        }
//    }
//
//    /* Funcionamento de um projétil */
//    //void Colisao::trajectory(Entidade* ent) {
//    //    //if (ent->getProjetil())
//    //    //    if (ent->pCaster->getFacingLeft())
//    //    //        ent->changePos(sf::Vector2f(-DX_PROJECTILE, 0.f));
//    //}
//
//    //Colisao* Colisao::getColisao()
//    //{
//    //    if (pColisao == nullptr)
//    //        pColisao = new Gerenciador::Colisao();
//
//    //    return pColisao;
//    //}
}


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
            if (list_ent->getEntity(i)->getMovable() && !list_ent->getEntity(i)->getGhost()) {
                for (j = 0; j < list_ent->getSize(); j++)
                    if (j != i && !list_ent->getEntity(j)->getGhost()){
                        collide(list_ent->getEntity(i), list_ent->getEntity(j));
                        printf("%u %u\n", list_ent->getEntity(i)->getId(), list_ent->getEntity(j)->getId());
                    }
                //if (list_ent->getEntity(i)->flying) {
                    //printf("acionou gravidade\n");
                    gravity(list_ent->getEntity(i));
                    list_ent->getEntity(i)->allow_jump = false;
                //}
                //else {
                //    list_ent->getEntity(i)->colidiu_baixo = true;
                //    list_ent->getEntity(i)->jumped = false;
                //    list_ent->getEntity(i)->allow_jump = true;
                //}
                if (list_ent->getEntity(i)->getJumped())
                {
                    jump(list_ent->getEntity(i));
                }
                //list_ent->getEntity(i)->colidiu_cima = false;
                //list_ent->getEntity(i)->colidiu_baixo = false;
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
            ricochet(ent1, ent2, sobre);//volta a posição sem sobreposição
        }
        /* se apoiado em cima de outro */
        if (sobre.x > 0 && centerDistance.y <= centerSum.y + ent1->getMass() * ACEL_GRAV && centerDistance.y >= centerSum.y-1) {
            ent1->flying = false;
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
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                    cout << "cima canto direito" << endl;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y) {//baixo canto direito
                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
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
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                    cout << "cima canto esquerdo" << endl;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y) {//baixo canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
                    cout << "baixo canto esquerdo" << endl;
                }
                else {//esquerda cantos superior e inferior
                    ent1->changePos(sf::Vector2f(-sobre.x, 0.f));
                    cout << "esquerda cantos superior e inferior" << endl;
                }
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePos(sf::Vector2f(0.f, -sobre.y));
                ent1->colidiu_baixo = true;
                ent2->colidiu_cima = true;
                cout << "cima entre vértices" << endl;
            }
            else {//baixo entre vértices
                ent1->changePos(sf::Vector2f(0.f, sobre.y));
                ent1->colidiu_cima = true;
                ent2->colidiu_baixo = true;
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
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                    cout << "cima canto direito" << endl;
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
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
                    ent1->colidiu_baixo = true;
                    ent2->colidiu_cima = true;
                    cout << "cima canto esquerdo" << endl;
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                    ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                    ent1->colidiu_cima = true;
                    ent2->colidiu_baixo = true;
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
                ent1->colidiu_baixo = true;
                ent2->colidiu_cima = true;
                cout << "cima entre vértices" << endl;
            }
            else{//baixo entre vértices
                ent1->changePos(sf::Vector2f(0.f, .5f*sobre.y));
                ent2->changePos(sf::Vector2f(0.f, -.5f*sobre.y));
                ent1->colidiu_cima = true;
                ent2->colidiu_baixo = true;
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
        if (!ent->colidiu_cima && ent->jumped_height < ent->getJumpStrength() && ent->getVel().y > ent->getMass() * ACEL_GRAV) {
            ent->changePos(sf::Vector2f(0.f, -ent->getVel().y));
            ent->jumped_height += ent->getVel().y;
            ent->allow_jump = false;
        }
        else if (ent->colidiu_baixo)
        {
            ent->jumped = false;
            ent->allow_jump = true;
            ent->jumped_height = 0.f;
            ent->colidiu_baixo = false;
            ent->colidiu_cima = false;
        }
    }
}
