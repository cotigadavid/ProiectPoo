#include "../Headers/ClientUI.h"

#include <iostream>

#include "../Headers/Retragere.h"
#include "../Headers/Depunere.h"
#include "../Headers/Transfer.h"
#include "../Headers/Database.h"
#include "../Headers/UI.h"

int ClientUI::ClientID = -1;

void ClientUI::Run()
{
	Database::ReadLoginInfo();
	int input;
	std::cout << "Select Option:\n1 - Log In\n2 - Sign Up\n";
	std::cin >> input;

	if (input == 1)
	{
		LogIn();
	}
	else if (input == 2)
	{
		SignUp();
	}
	else
	{
		std::cout << "Incorrect input\n\n";
		Run();
	}
	Run2(input);

	Banca::s_Banca->ShowTranzactii();
	Database::WriteAccountsInfo(Banca::s_Banca);
	Database::WriteTranzactions(Banca::s_Banca);
}

void ClientUI::Run2(int input)
{
	Banca* banca = Banca::s_Banca;

	Database::ReadAccountsInfo(banca);

	if (banca->HasId(ClientID))
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
				banca->GetClientWithID(ClientID)->AddCont(newCont);
			}
			else if (input == 1)
			{
				std::cout << "Enter the account id\n";
				input2 = UI::GetInput();
				if (banca->GetClientWithID(ClientID)->HasContWithId(input2))
					banca->GetClientWithID(ClientID)->EraseCont(input2);
				else
					std::cout << "No account with id: " << input2 << " found\n\n";

			}
			else if (input == 2)
			{
				std::cout << "Enter the Loan id: \n";
				input2 = UI::GetInput();
				Loan newLoan(input2);
				banca->GetClientWithID(ClientID)->AddLoan(newLoan);
			}
			else if (input == 3)
			{
				std::cout << "Enter the Loan id\n";
				input2 = UI::GetInput();
				if (banca->GetClientWithID(ClientID)->HasLoanWithId(input2))
					banca->GetClientWithID(ClientID)->EraseLoan(input2);
				else
					std::cout << "No Loan with id: " << input2 << " found\n\n";
			}
			else if (input == 4)
			{
				DoTransaction(input);
			}
			else if (input == -1)
				b_back = true;
		}
	}
	else
	{
		std::cout << "No client with id: " << ClientID << " found\n";
	}
}

void ClientUI::LogIn()
{
	std::string username;
	std::string password;

	std::cout << "Login\nUsername:\n";
	std::cin >> username;
	std::cout << "\nPassword:\n";
	std::cin >> password;

	bool checked = false;
	for (auto temp : Database::GetLogInInfo())
	{
		if (temp.username == username && temp.password == password)
		{
			ClientID = temp.id;
			checked = true;
		}
	}

	if (checked)
	{
		std::cout << "Logged In Successfully\n";
	}
	else
	{
		std::cout << "Incorrect username or password\n";
		LogIn();
	}
}

void ClientUI::SignUp()
{
	std::string username;
	std::string password;

	std::cout << "Your username:\n";
	std::cin >> username;
	std::cout << "Your password:\n";
	std::cin >> password;

	for (auto temp : Database::GetLogInInfo())
	{
		if (temp.username == username)
		{
			std::cout << "This username already exists\n";
			SignUp();
		}
	}

	LogInInfo acc;
	acc.username = username;
	acc.password = password;

	Database::AddAccount(acc);

	ClientID = Database::IdOfUser(username);

}

void ClientUI::DoTransaction(int input)
{
	std::cout << "Please Select the desired action\n";
	std::cout << "1 - Withdraw\n";
	std::cout << "2 - Deposit\n";
	std::cout << "3 - Transfer\n";
	std::cout << "-1 - Back\n\n";

	int input2;
	std::cin >> input2;

	if (input2 == 1)
	{
		int contId, suma;

		std::cout << "Cont id:\n";
		std::cin >> contId;
		std::cout << "Suma :\n";
		std::cin >> suma;

		std::shared_ptr<Retragere> t = std::make_shared<Retragere>(ClientID, contId, suma);
		t->SetClientId(ClientID);
		t->Run();
		Banca::s_Banca->AddTranzactie(t);
	}
	else if (input2 == 2)
	{
		int contId, suma;

		std::cout << "Cont id:\n";
		std::cin >> contId;
		std::cout << "Suma :\n";
		std::cin >> suma;

		std::shared_ptr<Depunere> t = std::make_shared<Depunere>(ClientID, contId, suma);
		t->SetClientId(ClientID);
		t->Run();
		Banca::s_Banca->AddTranzactie(t);
	}
	else if (input2 == 3)
	{
		int contId, receiverId, receiverContId, suma;

		std::cout << "Cont id:\n";
		std::cin >> contId;
		std::cout << "Suma :\n";
		std::cin >> suma;
		std::cout << "Receiver id:\n";
		std::cin >> receiverId;
		std::cout << "Receiver cont :\n";
		std::cin >> receiverContId;

		std::shared_ptr<Transfer> t = std::make_shared<Transfer>(receiverId, receiverContId, ClientID, contId, suma);
		t->SetClientId(ClientID);
		t->Run();
		Banca::s_Banca->AddTranzactie(t);
	}
	else if (input2 == -1)
	{
		Run2(input);
	}
	else
	{
		std::cout << "Incorrect Input\n";
	}
}
