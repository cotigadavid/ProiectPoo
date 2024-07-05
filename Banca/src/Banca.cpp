#include "../Headers/Banca.h"

#include "../Headers/Tranzactie.h"
#include "../Headers/Transfer.h"
#include "../Headers/Depunere.h"
#include "../Headers/Retragere.h"

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
	for (size_t i = 0; i < tranzactii.size(); ++i)
	{
		Transfer* tran = dynamic_cast<Transfer*>(tranzactii[i].get());

		if (tran != nullptr)
		{
			std::cout << "Transfer de la " << tran->GetClientId() << " catre " << tran->GetReceiverId() << " in valoare de " << tran->GetSuma() << "\n";
		}

		Retragere* ret = dynamic_cast<Retragere*>(tranzactii[i].get());

		if (ret != nullptr)
		{
			std::cout << "Retragere de catre " << ret->GetClientId() << " in valoare de " << ret->GetSuma() << "\n";
		}

		Depunere* dep = dynamic_cast<Depunere*>(tranzactii[i].get());
		if (dep != nullptr)
		{
			std::cout << "Depunere de catre " << dep->GetClientId() << " in valoare de " << dep->GetSuma() << "\n";
		}
	}
}

void Banca::AddClient(Client& newClient)
{
	clienti.push_back(newClient);

	nrClienti++;
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
	nrClienti = 0;
	clienti.clear();
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
	
	return nullptr;
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