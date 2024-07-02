#pragma once

#include "Tranzactie.h"

#include <iostream>

class Transfer : public Tranzactie {
public:

	Transfer(int newReceiverId, int newClientId);
	Transfer(int newReceiverId, int newReceiverContId, int newClientId, int newClientContId, int newSuma);

	bool VerificaTransfer();
	void Run() override;
	void ConfirmareTransfer();

	int GetReceiverId() { return receiverId; }

	~Transfer();

private:
	int receiverId;
	int receiverContId;
	int clientContId;
	std::string receiverName;

};