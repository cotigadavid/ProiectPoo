#include <iostream>

#include "ClientUI.h"
#include "Banca.h"
#include "Exceptii.h"

int main()
{
	Banca* banca = new Banca;

	try {
		ClientUI::Run();
	}
	catch (const eroare_fisier& e) {
		std::cout << "Eroare fisier: " << e.what() << "\n";
	}
	
	return 0;
}