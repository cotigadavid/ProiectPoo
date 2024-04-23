#include <iostream>

#include "Database.h"
#include "UI.h"
#include "Banca.h"

int main()
{
	Banca banca;

	Database::ReadFromFile(banca);

	UI::SelectAction();

	int input = UI::GetInput();

	if (input == 0)
	{
		UI::AskForID();
		input = UI::GetInput();
		if (!banca.HasId(input))
		{
			Client temp(input);
			banca.AddClient(temp);
			std::cout << "Client with id: " << input << " added to database\n";
		}
		else
		{
			std::cout << "A client with this id already exists.\n";
		}
	}

	else if (input == 1)
	{
		UI::AskForID();
		input = UI::GetInput();
		if (banca.HasId(input))
		{
			banca.EraseClient(input);
			std::cout << "Client with id: " << input << " erased from database\n";
		}
	}

	else if (input == 2)
	{
		UI::AskForID();
		input = UI::GetInput();

		if (banca.HasId(input))
		{
			Client temp = banca.GetClientWithID(input);
			std::cout << "Client Id: " << temp.GetId() << " Client Name: " << temp.GetName() << " Nr de conturi: " << temp.GetNrConturi() << " Nr de credite: " << temp.GetNrCredite();
		}
	}
	
	Database::CopyToFile(banca);
}