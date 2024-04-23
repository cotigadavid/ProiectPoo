#include "../Headers/Client.h"

Client::Client(int newId)
	: id(newId)
{
}

Client::Client(std::string newName)
	: name(newName)
{
}

Client::Client(std::vector<Cont> newConturi)
	: conturi(newConturi)
{
	nrConturi = newConturi.size();
}

Client::Client(std::vector<Credit> newCredite)
	: credite(newCredite)
{
	nrCredite = newCredite.size();
}

Client::Client(std::vector<Cont> newConturi, std::vector<Credit> newCredite)
	: conturi(newConturi), credite(newCredite)
{
	nrConturi = newConturi.size();
	nrCredite = newCredite.size();
}

Client::Client(const Client& other)
	: conturi(other.conturi), id(other.id), nrConturi(other.nrConturi), name(other.name)
{
}

Client::~Client()
{
}

void Client::AddCont(Cont& newCont)
{
	conturi.push_back(newCont);

	newCont.SetId((int)nrConturi);
	
	nrConturi++;
}

void Client::EraseCont(int index)
{
	conturi.erase(conturi.begin() + index);
}

void Client::AddCredit(Credit& newCredit)
{
	credite.push_back(newCredit);

	newCredit.SetId((int)nrCredite);

	nrCredite++;
}

void Client::EraseCredit(int index)
{
	credite.erase(credite.begin() + index);
}