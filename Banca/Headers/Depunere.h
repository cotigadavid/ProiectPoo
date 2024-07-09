#pragma once

#include "Tranzactie.h"

class Depunere : public Tranzactie {
public:
	Depunere(int newClientId, int newClientContId, int newsuma);

	void ShowTranzactie() override;
	void Run() override;

	~Depunere();

private:
	bool VerificaDepunere();
	void ConfirmareDepunere();

	int clientContId;
};