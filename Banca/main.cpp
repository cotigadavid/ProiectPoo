#include <iostream>

#include "Database.h"
#include "UI.h"
#include "Banca.h"

int main()
{
	Banca banca;
	/*Client client1(1);
	Client client2(3);
	Client client3(6);

	client1.SetName("FAivd");
	client2.SetName("MRvd");
	client3.SetName("agdasgivd");

	banca.AddClient(client1);
	banca.AddClient(client2);
	banca.AddClient(client3);*/

	Database::ReadFromFile(banca);

	UI::SelectAction();

	int input = UI::GetInput();

	if (input == 0)
	{

	}

	else if (input == 1)
	{

	}

	else if (input == 2)
	{
		UI::CheckClient();
		input = UI::GetInput();

		if (banca.HasId(input))
		{
			Client temp = banca.GetClientWithID(input);
			std::cout << "Client Id: " << temp.GetId() << " Client Name: " << temp.GetName() << " Nr de conturi: " << temp.GetNrConturi() << " Nr de credite: " << temp.GetNrCredite();
		}
	}
	
}