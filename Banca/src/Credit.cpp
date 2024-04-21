#include "Credit.h"

Credit::Credit(int newSold)
	: sold(newSold)
{
}

Credit::Credit(int newId, int newSold)
	: id(newId), sold(newSold)
{
}

Credit::Credit(const Credit& other)
	: id(other.id), sold(other.sold)
{
}

Credit::~Credit()
{
}
