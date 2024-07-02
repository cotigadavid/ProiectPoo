#pragma once

#include <iostream>

class Loan
{
public:
	Loan() = default;
	explicit Loan(int newID);
	Loan(int newId, int newSold);
	Loan(const Loan& other);
	~Loan();

	Loan& operator=(const Loan& other) {
		id = other.id;
		sold = other.sold;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Loan& Loan) {
		os << "Id : " << Loan.id << " Sold : " << Loan.sold << "\n";
		return os;
	}

private:
	int id = -1;
	int sold = 0;

public:
	int GetSold() { return sold; }
	void SetSold(int newSold) { sold = newSold; }

	void AddToSold(int amount) { sold += amount; }
	void SubtractFromSold(int amount) { sold -= amount; }

	int GetId() { return id; }
};