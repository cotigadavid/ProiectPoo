#include "../Headers/Banca.h"


Banca::Banca(std::vector<Client> newClienti)
	: clienti(newClienti)
{
	nrClienti = newClienti.size();
}

Banca::~Banca()
{
}

void Banca::AddClient(Client& newClient)
{
	clienti.push_back(newClient);

	//newClient.SetId(nrClienti);

	nrClienti++;
}

void Banca::EraseClient(int index)
{
	clienti.erase(clienti.begin() + index);
}

bool Banca::HasId(int id)
{
	for (auto client : clienti)
		if (client.GetId() == id)
			return true;
	return false;
}

Client Banca::GetClientWithID(int id)
{
	for (auto client : clienti)
		if (client.GetId() == id)
			return client;
	Client temp(-1);
	return temp;
}
