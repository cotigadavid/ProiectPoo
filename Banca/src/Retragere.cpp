#include "../Headers/Retragere.h"

#include <iostream>

Retragere::Retragere(int newClientId, int newClientContId, int newsuma)
	: clientContId(newClientContId)
{
	clientId = newClientId;
	suma = newsuma;
}

bool Retragere::VerificaRetragere()
{
	if (!Banca::GetInstance()->HasId(clientId))
		return false;
	if (!Banca::GetInstance()->GetClientWithID(clientId)->HasContWithId(clientContId))
		return false;
	if (Banca::GetInstance()->GetClientWithID(clientId)->GetContWithID(clientContId)->GetSold() < suma)
		return false;
	return true;
}

void Retragere::Run()
{
	if (!VerificaRetragere())
	{
		std::cout << "Retragerea nu a putut fi efectuata\n";
		return;
	}

	Banca::GetInstance()->GetClientWithID(clientId)->GetContWithID(clientContId)->SubtractFromSold(suma);

	ConfirmareRetragere();

}

void Retragere::ConfirmareRetragere()
{
	std::cout << "Retragere confirmata\n";
	//banca->AddTranzactie(this);
}

Retragere::~Retragere()
{
}
