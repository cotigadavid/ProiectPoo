#pragma once

#include <iostream>

class Cont
{
public:
	Cont() = default;
	explicit Cont(int newSold);
	Cont(int newId, int newSold);
	Cont(const Cont& other);
	~Cont();

	Cont& operator=(const Cont& other) {
		id = other.id;
		sold = other.sold;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Cont& cont) {
		os << "Id : " << cont.id << " Sold : " << cont.sold << "\n";
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