#include "../Headers/Tranzactie.h"

#include <iostream>

#include "../Headers/Banca.h"

Tranzactie::Tranzactie()
{
	banca = Banca::s_Banca;
}

Tranzactie::~Tranzactie()
{
}
