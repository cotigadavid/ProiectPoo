#include "../Headers/Client.h"
#include "../Headers/Exceptii.h"

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
}

Client::Client(const std::vector<Loan>& newLoans)
	: loans(newLoans)
{
}

Client::Client(const std::vector<Cont>& newConturi, const std::vector<Loan>& newLoans)
	: conturi(newConturi), loans(newLoans)
{
}

Client::Client(const Client& other)
	: id(other.id), name(other.name), conturi(other.conturi)
{
}

Client::~Client()
{
}

void Client::AddCont(Cont& newCont)
{
	conturi.push_back(newCont);
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
	for (size_t i = 0; i < conturi.size(); ++i)
		if (conturi[i].GetId() == index)
			conturi.erase(conturi.begin() + i);
}

void Client::AddLoan(Loan& newLoan)
{
	loans.push_back(newLoan);
}

void Client::EraseLoan(int index)
{
	for (size_t i = 0; i < loans.size(); ++i)
		if (loans[i].GetId() == index)
			loans.erase(loans.begin() + i);
}

Cont& Client::GetContWithID(int ID)
{
	for (size_t i = 0; i < conturi.size(); ++i)
		if (conturi[i].GetId() == ID)
			return conturi[i];

	throw eroare_id("Id cont nu exista");
}

//Loan* Client::GetLoanWithID(int ID)
//{
//	for (size_t i = 0; i < loans.size(); ++i)
//		if (loans[i].GetId() == ID)
//			return &loans[i];
//
//	return nullptr;
//}