#include <iostream>

#include "Database.h"
#include "UI.h"
#include "Banca.h"

int main()
{
	Banca banca;

	Database::ReadFromFile(banca);

	bool b_exit = false;

	UI::WelcomeMessage();

	while (!b_exit)
	{
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
				std::cout << "Client with id: " << input << " added to database\n\n";
			}
			else
			{
				std::cout << "A client with this id already exists.\n\n";
			}
		}

		else if (input == 1)
		{
			UI::AskForID();
			input = UI::GetInput();
			if (banca.HasId(input))
			{
				banca.EraseClient(input);
				std::cout << "Client with id: " << input << " erased from database\n\n";
			}
			else
			{
				std::cout << "No client with id: " << input << " found\n\n";
			}
		}

		else if (input == 2)
		{
			UI::AskForID();
			input = UI::GetInput();

			if (banca.HasId(input))
			{
				Client* temp = banca.GetClientWithID(input);
				if (temp->GetId() != -1)
					std::cout << "Client Id: " << temp->GetId() << " Client Name: " << temp->GetName() << " Nr de conturi: " << temp->GetNrConturi() << " Nr de credite: " << temp->GetNrCredite() << "\n\n";
			}
			else
			{
				std::cout << "No client with id: " << input << " found\n\n";
			}
		}

		else if (input == 3)
		{
			UI::AskForID();
			int id = UI::GetInput();

			if (banca.HasId(id))
			{
				int input2;
				bool b_back = false;
				while (!b_back)
				{
					UI::SelectClientAction();
					input = UI::GetInput();

					if (input == 0)
					{
						std::cout << "Enter the account id: \n";
						input2 = UI::GetInput();
						Cont newCont(input2);
						banca.GetClientWithID(id)->AddCont(newCont);
					}
					else if (input == 1)
					{
						std::cout << "Enter the account id\n";
						input2 = UI::GetInput();
						if (banca.GetClientWithID(id)->HasContWithId(input2))
							banca.GetClientWithID(id)->EraseCont(input2);
						else
							std::cout << "No account with id: " << input2 << " found\n\n";

					}
					else if (input == 2)
					{
						std::cout << "Enter the credit id: \n";
						input2 = UI::GetInput();
						Credit newCredit(input2);
						banca.GetClientWithID(id)->AddCredit(newCredit);
					}
					else if (input == 3)
					{
						std::cout << "Enter the credit id\n";
						input2 = UI::GetInput();
						if (banca.GetClientWithID(id)->HasCreditWithId(input2))
							banca.GetClientWithID(id)->EraseCredit(input2);
						else
							std::cout << "No credit with id: " << input2 << " found\n\n";
					}
					else if (input == -1)
						b_back = true;
				}
			}
			else
			{
				std::cout << "No client with id: " << input << " found\n";
			}
		}
		else if (input == -1)
			b_exit = true;
	}
	
	Database::CopyToFile(banca);
}