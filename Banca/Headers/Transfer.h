#pragma once

#include "Tranzactie.h"

#include <iostream>

class Transfer : public Tranzactie {
public:

	Transfer(int newReceiverId, int newReceiverContId, int newClientId, int newClientContId, int newSuma);

	void ShowTranzactie() override;
	void Run() override;
	int GetReceiverId() { return receiverId; }

	~Transfer();

private:
	bool VerificaTransfer();
	void ConfirmareTransfer();

	int receiverId;
	int receiverContId;
	int clientContId;
	std::string receiverName;

};