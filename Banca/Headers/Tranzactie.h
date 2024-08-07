#pragma once

#include "Banca.h"

class Tranzactie {
public:
	Tranzactie();

	virtual void Run() = 0;

	virtual void ShowTranzactie() = 0;

	int GetClientId() { return clientId; }
	void SetClientId(int newId) { clientId = newId; }
	int GetSuma() { return suma; }

	virtual ~Tranzactie();

protected:
	int tranId = -1;
	int clientId = -1;
	int suma = 0;
};