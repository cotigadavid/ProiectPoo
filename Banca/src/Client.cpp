#include "../Headers/Client.h"

Client::Client(int newId)
	: id(newId)
{
}

Client::Client(const std::string& newName)
	: name(newName)
{
}

Client::Client(const std::vector<Cont>& newConturi)
	: conturi(newConturi)
{
	nrConturi = newConturi.size();
}

Client::Client(const std::vector<Credit>& newCredite)
	: credite(newCredite)
{
	nrCredite = newCredite.size();
}

Client::Client(const std::vector<Cont>& newConturi, const std::vector<Credit>& newCredite)
	: conturi(newConturi), credite(newCredite)
{
	nrConturi = newConturi.size();
	nrCredite = newCredite.size();
}

Client::Client(const Client& other)
	: id(other.id), nrConturi(other.nrConturi), name(other.name), conturi(other.conturi)
{
}

Client::~Client()
{
}

void Client::AddCont(Cont& newCont)
{
	conturi.push_back(newCont);
	
	nrConturi++;
}

bool Client::HasContWithId(int ID)
{
	for (auto cont : conturi)
		if (cont.GetId() == ID)
			return true;
	return false;
}

bool Client::HasCreditWithId(int ID)
{
	for (auto credit : credite)
		if (credit.GetId() == ID)
			return true;
	return false;
}

//void Client::EraseCont(int index)
//{
//	std::vector<Cont>* conturi = GetConturi();
//	for (size_t i = 0; i < GetNrConturi(); ++i)
//		if ((*conturi)[i].GetId() == index)
//			(*conturi).erase((*conturi).begin() + i);
//}

void Client::EraseCont(int index)
{
	for (size_t i = 0; i < GetNrConturi(); ++i)
		if (conturi[i].GetId() == index)
			conturi.erase(conturi.begin() + i);
	nrConturi--;
}

void Client::AddCredit(Credit& newCredit)
{
	credite.push_back(newCredit);

	nrCredite++;
}

//void Client::EraseCredit(int index)
//{
//	std::vector<Credit>* credite = GetCredite();
//	for (size_t i = 0; i < GetNrCredite(); ++i)
//		if ((*credite)[i].GetId() == index)
//			(*credite).erase((*credite).begin() + i);
//}

void Client::EraseCredit(int index)
{
	for (size_t i = 0; i < GetNrCredite(); ++i)
		if (credite[i].GetId() == index)
			credite.erase(credite.begin() + i);
	nrCredite--;
}