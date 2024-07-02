#include "Depunere.h"

#include <iostream>

Depunere::Depunere(int newClientId, int newClientContId, int newsuma)
	: clientContId(newClientContId)
{
	clientId = newClientId;
	suma = newsuma;
}

bool Depunere::VerificaDepunere()
{
	if (!banca->HasId(clientId))
		return false;
	if (!banca->GetClientWithID(clientId)->HasContWithId(clientContId))
		return false;
    return true;
}

void Depunere::Run()
{
	if (!VerificaDepunere())
	{
		std::cout << "Depunere nu a putut fi efectuata\n";
		return;
	}

	banca->GetClientWithID(clientId)->GetContWithID(clientContId)->AddToSold(suma);

	ConfirmareDepunere();
}

void Depunere::ConfirmareDepunere()
{
	std::cout << "Depunere confirmate\n";
	//banca->AddTranzactie(this);
}
