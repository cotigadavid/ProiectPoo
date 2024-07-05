#include "../Headers/Transfer.h"


Transfer::Transfer(int newReceiverId, int newReceiverContId, int newClientId, int newClientContId, int newSuma)
	: receiverId(newReceiverId), receiverContId(newReceiverContId), clientContId(newClientContId)
{
	clientId = newClientId;
	suma = newSuma;
}

bool Transfer::VerificaTransfer()
{
	if (!Banca::GetInstance()->HasId(receiverId))
		return false;
	if (!Banca::GetInstance()->GetClientWithID(receiverId)->HasContWithId(receiverContId))
		return false;
	if (!Banca::GetInstance()->HasId(clientId))
		return false;
	if (!Banca::GetInstance()->GetClientWithID(clientId)->HasContWithId(clientContId))
		return false;
	if (Banca::GetInstance()->GetClientWithID(clientId)->GetContWithID(clientContId)->GetSold() < suma)
		return false;
	return true;
}

void Transfer::Run()
{
	if (!VerificaTransfer())
	{
		std::cout << "Transferul nu a putut fi efectuat\n";
		return;
	}

	Banca::GetInstance()->GetClientWithID(clientId)->GetContWithID(clientContId)->SubtractFromSold(suma);
	Banca::GetInstance()->GetClientWithID(receiverId)->GetContWithID(receiverContId)->AddToSold(suma);

	ConfirmareTransfer();
}

void Transfer::ConfirmareTransfer()
{
	std::cout << "Transfer efectuat\n";
	//banca->AddTranzactie(this);
}

Transfer::~Transfer()
{
}
