#include "../Headers/Loan.h"

Loan::Loan(int newID)
	: id(newID)
{
}

Loan::Loan(int newId, int newSold)
	: id(newId), sold(newSold)
{
}

Loan::Loan(const Loan& other)
	: id(other.id), sold(other.sold)
{
}

Loan::~Loan()
{
}
