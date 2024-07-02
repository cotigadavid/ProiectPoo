#include <iostream>

#include "../Headers/ClientUI.h"
#include "../Headers/Banca.h"
#include "../Headers/Exceptii.h"

int main()
{
	try {
		ClientUI::Run();
	}
	catch (const eroare_fisier& e) {
		std::cout << "Eroare fisier: " << e.what() << "\n";
	}
	
	return 0;
}