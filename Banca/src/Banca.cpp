#include "../Headers/Banca.h"

#include "../Headers/Tranzactie.h"
#include "../Headers/Transfer.h"
#include "../Headers/Depunere.h"
#include "../Headers/Retragere.h"
#include "../Headers/Exceptii.h"

Banca* Banca::s_Banca = nullptr;

Banca::Banca()
{
}

void Banca::AddTranzactie(std::shared_ptr<Tranzactie> newTran)
{
	tranzactii.push_back(newTran);

	nrTran++;
}

void Banca::ShowTranzactii()
{
	for (auto ptr : tranzactii)
		ptr->ShowTranzactie();
}

void Banca::AddClient(Client& newClient)
{
	clienti.push_back(newClient);
}

//void Banca::EraseClient(int index)
//{
//	for (size_t i = 0; i < GetNrClienti(); ++i)
//		if (clienti[i].GetId() == index)
//		{
//			clienti.erase(clienti.begin() + i);
//			break;
//		}
//	nrClienti--;
//}

void Banca::EraseAllClients()
{
	clienti.clear();
}

bool Banca::HasId(int id)
{
	for (auto client : clienti)
		if (client.GetId() == id)
			return true;
	return false;
}

Client& Banca::GetClientWithID(int id)
{
	for (size_t i = 0; i < clienti.size(); ++i)
		if (clienti[i].GetId() == id)
			return clienti[i];

	throw eroare_id("Id client inexistent");
}

Banca* Banca::GetInstance() {
	if (s_Banca == nullptr) {
		s_Banca = new Banca();
	}
	return s_Banca;
}


Banca::~Banca()
{
}