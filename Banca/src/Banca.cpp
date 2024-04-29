#include "../Headers/Banca.h"


Banca::Banca(const std::vector<Client>& newClienti)
	: clienti(newClienti)
{
	nrClienti = newClienti.size();
}

void Banca::AddClient(Client& newClient)
{
	clienti.push_back(newClient);

	nrClienti++;
}

void Banca::EraseClient(int index)
{
	for (size_t i = 0; i < GetNrClienti(); ++i)
		if (clienti[i].GetId() == index)
		{
			clienti.erase(clienti.begin() + i);
			break;
		}
	nrClienti--;
}

bool Banca::HasId(int id)
{
	for (auto client : clienti)
		if (client.GetId() == id)
			return true;
	return false;
}

Client* Banca::GetClientWithID(int id)
{
	for (size_t i = 0; i < clienti.size(); ++i)
		if (clienti[i].GetId() == id)
			return &clienti[i];
	
	return NULL;
}
