#pragma once

#include <iostream>
#include <vector>

#include "Cont.h"
#include "Loan.h"

class Client 
{
public:
	Client() = default;
	explicit Client(int newId);
	explicit Client(const std::string& newName);
	explicit Client(const std::vector<Cont>& newConturi);
	explicit Client(const std::vector<Loan>& newLoans);
	Client(const std::vector<Cont>& newConturi, const std::vector<Loan>& newLoans);
	Client(const Client& other);
	~Client();

	Client& operator=(const Client& other) {
		id = other.id;
		nrConturi = other.nrConturi;
		conturi = other.conturi;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Client& client) {
		os << "Id : " << client.id << " Numar conturi : " << client.nrConturi << " Numar Credite : " << client.nrLoans << "\n";
		return os;
	}

private:
	int id = -1;
	size_t nrConturi = 0;
	size_t nrLoans = 0;
	std::string name;
	std::vector<Cont> conturi;
	std::vector<Loan> loans;

public:
	bool HasContWithId(int id);
	bool HasLoanWithId(int id);

	void AddCont(Cont& newCont);
	void EraseCont(int index);

	void AddLoan(Loan& newLoan);
	void EraseLoan(int index);

	int GetId() { return id; }
	void SetId(int newId) { id = newId; }

	std::string GetName() { return name; }
	void SetName(const std::string& newName) { name = newName; }

	size_t GetNrConturi() { return nrConturi; }
	size_t GetNrLoans() { return nrLoans; }

	std::vector<Cont> GetConturi() { return conturi; }
	std::vector<Loan> GetLoans() { return loans; }

	Cont* GetContWithID(int id);
	Loan* GetLoanWithID(int id);
};