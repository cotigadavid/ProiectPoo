#pragma once

#include <iostream>
#include <vector>

#include "Client.h"

class Banca
{
public:
	Banca() = default;
	explicit Banca(const std::vector<Client>& newClienti);

	friend std::ostream& operator<<(std::ostream& os, const Banca& banca) {
		os << "Numar clienti : " << banca.nrClienti << "\n";
		return os;
	}

private:
	size_t nrClienti = 0;
	std::vector<Client> clienti;

public:
	size_t GetNrClienti() { return nrClienti; }
	std::vector<Client> GetClienti() { return clienti; }

	void AddClient(Client& newClient);
	void EraseClient(int index);

	bool HasId(int id);

	Client* GetClientWithID(int id);
};