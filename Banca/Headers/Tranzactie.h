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
	int tranId = -1;
	int clientId = -1;
	int suma = 0;

	Banca* banca;
};