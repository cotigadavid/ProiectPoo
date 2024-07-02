#pragma once

#include "Banca.h"

class Tranzactie {
public:
	Tranzactie();

	virtual void Run() = 0;

	int GetClientId() { return clientId; }
	void SetClientId(int newId) { clientId = newId; }
	int GetSuma() { return suma; }

protected:
	int tranId;
	int clientId;
	int suma;

	Banca* banca;
};