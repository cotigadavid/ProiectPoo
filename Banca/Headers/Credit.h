#pragma once

#include <iostream>

class Credit
{
public:
	Credit() = default;
	explicit Credit(int newSold);
	Credit(int newId, int newSold);
	Credit(const Credit& other);
	~Credit();

	Credit& operator=(const Credit& other) {
		id = other.id;
		sold = other.sold;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Credit& credit) {
		os << "Id : " << credit.id << " Sold : " << credit.sold << "\n";
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
	void SetId(int newId) { id = newId; }
};