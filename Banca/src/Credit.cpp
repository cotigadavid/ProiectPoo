#include "../Headers/Credit.h"

Credit::Credit(int newID)
	: id(newID)
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
