#include <iostream>

#include "../Headers/ClientUI.h"
#include "../Headers/Banca.h"
#include "../Headers/Exceptii.h"

int main()
{
	//Banca* banca = Banca::GetInstance();

	try 
	{
		ClientUI::Run();
	}
	catch (const eroare_fisier& e) 
	{
		std::cout << "Eroare fisier: " << e.what() << "\n";
	}
	catch (const eroare_id& e)
	{
		std::cout << "Eroare id: " << e.what() << "\n";
	}
	catch (const eroare_app& e)
	{
		std::cout << "Eroare: " << e.what() << "\n";
	}
	
	return 0;
}