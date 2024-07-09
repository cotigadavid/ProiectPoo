#pragma once

#include "Tranzactie.h"

class Retragere : public Tranzactie {
public:
	Retragere(int newClientId, int newClientContId, int newsuma);

	void ShowTranzactie() override;
	void Run() override;

	~Retragere();

private:
	bool VerificaRetragere();
	void ConfirmareRetragere();

	int clientContId;
};