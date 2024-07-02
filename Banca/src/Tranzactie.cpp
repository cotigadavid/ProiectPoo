#include "Tranzactie.h"

#include <iostream>

#include "Banca.h"

Tranzactie::Tranzactie()
{
	banca = Banca::s_Banca;
}
