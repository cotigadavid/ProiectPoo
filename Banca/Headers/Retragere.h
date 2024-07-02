#pragma once

#include "Tranzactie.h"

class Retragere : public Tranzactie {
public:
	Retragere(int newClientId, int newClientContId, int newsuma);

	bool VerificaRetragere();
	void Run() override;
	void ConfirmareRetragere();

	~Retragere();

private:
	int clientContId;
};