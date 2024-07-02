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

Client::Client(const std::vector<Loan>& newLoans)
	: loans(newLoans)
{
	nrLoans = newLoans.size();
}

Client::Client(const std::vector<Cont>& newConturi, const std::vector<Loan>& newLoans)
	: conturi(newConturi), loans(newLoans)
{
	nrConturi = newConturi.size();
	nrLoans = newLoans.size();
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

bool Client::HasLoanWithId(int ID)
{
	for (auto Loan : loans)
		if (Loan.GetId() == ID)
			return true;
	return false;
}

void Client::EraseCont(int index)
{
	for (size_t i = 0; i < GetNrConturi(); ++i)
		if (conturi[i].GetId() == index)
			conturi.erase(conturi.begin() + i);
	nrConturi--;
}

void Client::AddLoan(Loan& newLoan)
{
	loans.push_back(newLoan);

	nrLoans++;
}

void Client::EraseLoan(int index)
{
	for (size_t i = 0; i < GetNrLoans(); ++i)
		if (loans[i].GetId() == index)
			loans.erase(loans.begin() + i);
	nrLoans--;
}

Cont* Client::GetContWithID(int id)
{
	for (size_t i = 0; i < conturi.size(); ++i)
		if (conturi[i].GetId() == id)
			return &conturi[i];

	return nullptr;
}

Loan* Client::GetLoanWithID(int id)
{
	for (size_t i = 0; i < loans.size(); ++i)
		if (loans[i].GetId() == id)
			return &loans[i];

	return nullptr;
}