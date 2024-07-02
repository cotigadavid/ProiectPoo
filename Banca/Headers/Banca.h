#pragma once

#include <iostream>
#include <vector>

#include "Client.h"

class Tranzactie;

class Banca
{
public:
	Banca();
	~Banca();
	explicit Banca(const std::vector<Client>& newClienti);

	friend std::ostream& operator<<(std::ostream& os, const Banca& banca) {
		os << "Numar clienti : " << banca.nrClienti << "\n";
		return os;
	}

private:
	size_t nrClienti = 0;
	std::vector<Client> clienti;

	size_t nrTran = 0;
	std::vector<std::shared_ptr<Tranzactie>> tranzactii;

public:
	size_t GetNrClienti() { return nrClienti; }
	std::vector<Client> GetClienti() { return clienti; }
	std::vector<std::shared_ptr<Tranzactie>> GetTranzactii() { return tranzactii; }

	void AddTranzactie(std::shared_ptr<Tranzactie> newTran);
	void ShowTranzactii();

	void AddClient(Client& newClient);
	void EraseClient(int index);
	void EraseAllClients();

	bool HasId(int id);

	Client* GetClientWithID(int id);

	static Banca* s_Banca;
};