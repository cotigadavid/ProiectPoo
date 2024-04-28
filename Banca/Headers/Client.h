#pragma once

#include <iostream>
#include <vector>

#include "Cont.h"
#include "Credit.h"

class Client 
{
public:
	Client() = default;
	explicit Client(int newId);
	explicit Client(const std::string& newName);
	explicit Client(const std::vector<Cont>& newConturi);
	explicit Client(const std::vector<Credit>& newCredite);
	Client(const std::vector<Cont>& newConturi, const std::vector<Credit>& newCredite);
	Client(const Client& other);
	~Client();

	Client& operator=(const Client& other) {
		id = other.id;
		nrConturi = other.nrConturi;
		conturi = other.conturi;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Client& client) {
		os << "Id : " << client.id << " Numar conturi : " << client.nrConturi << " Numar credite : " << client.nrCredite << "\n";
		return os;
	}

private:
	int id = -1;
	size_t nrConturi = 0;
	size_t nrCredite = 0;
	std::string name;
	std::vector<Cont> conturi;
	std::vector<Credit> credite;

public:
	void AddCont(Cont& newCont);
	void EraseCont(int index);

	void AddCredit(Credit& newCredit);
	void EraseCredit(int index);

	int GetId() { return id; }
	void SetId(int newId) { id = newId; }

	std::string GetName() { return name; }
	void SetName(const std::string& newName) { name = newName; }

	size_t GetNrConturi() { return nrConturi; }
	size_t GetNrCredite() { return nrCredite; }

	std::vector<Cont> GetConturi() { return conturi; }
	std::vector<Credit> GetCredite() { return credite; }
};