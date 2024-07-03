#include "../Headers/Depunere.h"

#include <iostream>

Depunere::Depunere(int newClientId, int newClientContId, int newsuma)
	: clientContId(newClientContId)
{
	clientId = newClientId;
	suma = newsuma;
}

bool Depunere::VerificaDepunere()
{
	if (!Banca::GetInstance()->HasId(clientId))
		return false;
	if (!Banca::GetInstance()->GetClientWithID(clientId)->HasContWithId(clientContId))
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

	Banca::GetInstance()->GetClientWithID(clientId)->GetContWithID(clientContId)->AddToSold(suma);

	ConfirmareDepunere();
}

void Depunere::ConfirmareDepunere()
{
	std::cout << "Depunere confirmate\n";
}

Depunere::~Depunere()
{
}
