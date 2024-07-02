#include "Transfer.h"

//#include "Banca.h"

Transfer::Transfer(int newReceiverId, int newClientId)
	: receiverId(newReceiverId)
{
	clientId = newClientId;
}

Transfer::Transfer(int newReceiverId, int newReceiverContId, int newClientId, int newClientContId, int newSuma)
	: receiverId(newReceiverId), receiverContId(newReceiverContId), clientContId(newClientContId)
{
	clientId = newClientId;
	suma = newSuma;
}

bool Transfer::VerificaTransfer()
{
	if (!banca->HasId(receiverId))
		return false;
	if (!banca->GetClientWithID(receiverId)->HasContWithId(receiverContId))
		return false;
	if (!banca->HasId(clientId))
		return false;
	if (!banca->GetClientWithID(clientId)->HasContWithId(clientContId))
		return false;
	if (banca->GetClientWithID(clientId)->GetContWithID(clientContId)->GetSold() < suma)
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

	banca->GetClientWithID(clientId)->GetContWithID(clientContId)->SubtractFromSold(suma);
	banca->GetClientWithID(receiverId)->GetContWithID(receiverContId)->AddToSold(suma);

	ConfirmareTransfer();
}

void Transfer::ConfirmareTransfer()
{
	std::cout << "Transfer efectuat\n";
	//banca->AddTranzactie(this);
}
