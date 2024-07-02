#include <iostream>

#include "Banca/Headers/ClientUI.h"
#include "Banca/Headers/Banca.h"
#include "Banca/Headers/Exceptii.h"

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