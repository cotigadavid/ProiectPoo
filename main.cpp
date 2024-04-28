#include <iostream>

#include "Banca/Headers/Database.h"
#include "Banca/Headers/UI.h"
#include "Banca/Headers/Banca.h"

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
		else
		{
			std::cout << "No client with id: " << input << " found\n";
		}
	}

	else if (input == 2)
	{
		UI::AskForID();
		input = UI::GetInput();

		if (banca.HasId(input))
		{
			Client temp = banca.GetClientWithID(input);
			if (temp.GetId() != -1)
				std::cout << "Client Id: " << temp.GetId() << " Client Name: " << temp.GetName() << " Nr de conturi: " << temp.GetNrConturi() << " Nr de credite: " << temp.GetNrCredite();
		}
		else
		{
			std::cout << "No client with id: " << input << " found\n";
		}
	}

	else if (input == 3)
	{
		UI::AskForID();
		input = UI::GetInput();
		int input2;

		if (banca.HasId(input))
		{
			UI::SelectClientAction();
			input = UI::GetInput();

			if (input == 0)
			{
				std::cout << "Enter the account balance: \n";
				input2 = UI::GetInput();
				Cont newCont(input2);
				banca.GetClientWithID(input).AddCont(newCont);
			}
			else if (input == 1)
			{
				std::cout << "Enter the account id\n";
				input2 = UI::GetInput();
				banca.GetClientWithID(input).EraseCont(input2);
			}
			else if (input == 2)
			{
				std::cout << "Enter the credit balance: \n";
				input2 = UI::GetInput();
				Credit newCredit(input2);
				banca.GetClientWithID(input).AddCredit(newCredit);
			}
			else if (input == 3)
			{
				std::cout << "Enter the credit id\n";
				input2 = UI::GetInput();
				banca.GetClientWithID(input).EraseCredit(input2);
			}
		}
		else
		{
			std::cout << "No client with id: " << input << " found\n";
		}
	}

	Database::CopyToFile(banca);
}