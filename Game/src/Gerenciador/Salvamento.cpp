#include "pch.h"
#include "Gerenciador/Salvamento.h"

using namespace std;

namespace Gerenciador{
	Salvamento* Salvamento::pSalvamento(nullptr);

	Salvamento::Salvamento()
	{
	}

	Salvamento::~Salvamento()
	{
		dados.clear();
		pSalvamento = nullptr;
	}

	void Salvamento::carregarID(ListaEntidades* list_ent, unsigned int id)
	{
		int j;
		auto range = dados.equal_range(id);
		for (auto i = range.first; i != range.second; ++i)
		{
			for (j = 0; j < list_ent->getSize() && list_ent->getEntity(j)->getId() != id; j++)
			{
				j++;
			}
			if (j < list_ent->getSize() - 1) {
				restaurarProgresso(list_ent->getEntity(j), i->second);
				dados.erase(i);
				j++;
			}
			else
				j = 0;
		}
	}

	void Salvamento::carregarPersonagens(ListaEntidades* list_ent)
	{
		for_each(id_list.begin(), id_list.end(), [&](auto& id) {carregarID(list_ent, id);});
	}

	void Salvamento::carregarJogoSalvo(ListaEntidades* list_ent)
	{
		ifstream progresso("jogo_salvo.csv");
		if (progresso.is_open()) {
			unsigned int id_tmp;
			int life_tmp;
			sf::Vector2f pos_tmp;
			sf::Time clock_tmp;
			string linha, texto;
			dados.clear();
			while (getline(progresso, linha))
			{                                                                                    
				istringstream linestream(linha);
				getline(linestream, texto, ',');
				id_tmp = stoul(texto);
				getline(linestream, texto, ',');
				life_tmp = stoi(texto);
				getline(linestream, texto, ',');
				pos_tmp.x = stof(texto);
				getline(linestream, texto, ',');
				pos_tmp.y = stof(texto);
				getline(linestream, texto);
				clock_tmp = sf::milliseconds(stoi(texto));
				dados.emplace(id_tmp, make_tuple(life_tmp, pos_tmp, clock_tmp));
				progresso.close();
			}
		}
		else {
			string erro = "N�o foi poss�vel carregar o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
		carregarPersonagens(list_ent);
	}

	void Salvamento::limparJogoSalvo()
	{
		ofstream progresso("jogo_salvo.txt");
		progresso.clear();
		progresso.close();
		if (!remove("jogo_salvo.txt"))
		{
			string erro = "N�o foi poss�vel excluir o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::prepararSalvarJogo(ListaEntidades* list_ent)
	{
		for (int k = 0; k < list_ent->getSize(); k++)
		{
			if (binary_search(id_list.begin(), id_list.end(), list_ent->getEntity(k)->getId()))
			{
				dados.clear();
				dados.insert(make_pair(list_ent->getEntity(k)->getId(), make_tuple(list_ent->getEntity(k)->getLife(), list_ent->getEntity(k)->getPos(), list_ent->getEntity(k)->getClock())));
			}
		}
	}

	void Salvamento::salvarJogo(ListaEntidades* list_ent)
	{
		prepararSalvarJogo(list_ent);
		ofstream progresso("jogo_salvo.txt");
		progresso.clear();
		if (progresso.is_open()) {
			for (auto i : dados) {
				progresso << i.first << "," << get<0>(i.second) << "," << get<1>(i.second).x << "," << get<1>(i.second).y << ","
					      << get<2>(i.second).asMilliseconds() << endl;
			}
			progresso.close();
			dados.clear();
		}
		else {
			string erro = "N�o foi poss�vel salvar o progresso do jogo.";
			try { throw runtime_error(erro); }
			catch (...) {
				cerr << erro << endl;
				exit(1);
			}
		}
	}

	void Salvamento::restaurarProgresso(Entidade* ent, tuple<int, sf::Vector2f, sf::Time> dados_um)
	{
		ent->applyDamage(ent->getLife() - get<0>(dados_um));
		ent->setEntPos(get<1>(dados_um));
		ent->setClockZero(get<2>(dados_um));
	}

	Salvamento* Salvamento::getSalvamento()
	{
		if(!pSalvamento)
			pSalvamento = new Salvamento();
		return pSalvamento;
	}
}