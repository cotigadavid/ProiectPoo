#include "Cont.h"

Cont::Cont(int newSold)
{
}

Cont::Cont(int newId, int newSold)
	: id(newId), sold(newSold)
{
}

Cont::Cont(const Cont& other)
	: id(other.id), sold(other.sold)
{
}

Cont::~Cont()
{
}
