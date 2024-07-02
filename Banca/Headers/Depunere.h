#pragma once

#include "Tranzactie.h"

class Depunere : public Tranzactie {
public:
	Depunere(int newClientId, int newClientContId, int newsuma);

	bool VerificaDepunere();
	void Run() override;
	void ConfirmareDepunere();

private:
	int clientContId;
};