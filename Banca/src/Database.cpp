#include <fstream>

#include "../Headers/Database.h"
#include "../Headers/Banca.h"
#include "../Headers/Client.h"

#include "../Headers/Transfer.h"
#include "../Headers/Tranzactie.h"
#include "../Headers/Depunere.h"
#include "../Headers/Retragere.h"
#include "../Headers/Exceptii.h"

std::vector<LogInInfo> Database::accounts;

void Database::WriteAccountsInfo(Banca* banca)
{
	std::ofstream fout("Date.txt");

	std::vector<Client> clienti = banca->GetClienti();

	fout << banca->GetNrClienti() << "\n";

	for (size_t i = 0; i < clienti.size(); ++i)
	{
		fout << clienti[i].GetId() << " " << clienti[i].GetNrConturi() << " " << clienti[i].GetNrLoans() << " ";

		std::vector<Cont> conturi = clienti[i].GetConturi();
		std::vector<Loan> Loans = clienti[i].GetLoans();
		for (size_t j = 0; j < clienti[i].GetNrConturi(); ++j)
			fout << conturi[j].GetId() << " " << conturi[j].GetSold() << " ";

		for (size_t j = 0; j < clienti[i].GetNrLoans(); ++j)
			fout << Loans[j].GetId() << " " << Loans[j].GetSold() << " ";
	}

	fout.close();
}

void Database::ReadAccountsInfo(Banca* banca)
{
	std::ifstream fin("Date.txt");

	if (!fin.is_open())
		throw eroare_fisier("Date.txt");

	banca->EraseAllClients();

	int nrClienti = 0;

	fin >> nrClienti;

	int id;
	int nrConturi;
	int nrLoans;

	for (int i = 0; i < nrClienti; ++i)
	{
		fin >> id >> nrConturi >> nrLoans;

		Client clientTemp;
		clientTemp.SetId(id);
		
		int contId, sold;
		for (int j = 0; j < nrConturi; j++)
		{
			fin >> contId >> sold;
			Cont contTemp(contId, sold);
			clientTemp.AddCont(contTemp);
		}
		for (int j = 0; j < nrLoans; j++)
		{
			fin >> contId >> sold;
			Loan LoanTemp(contId, sold);
			clientTemp.AddLoan(LoanTemp);
		}

		banca->AddClient(clientTemp);
	}
	
}

void Database::WriteLoginInfo()
{

	std::ofstream fout("Conturi.txt");

	fout << accounts.size() << "\n";

	for (size_t i = 0; i < accounts.size(); ++i)
	{
		fout << accounts[i].username << " " << accounts[i].password << " " << accounts[i].id << "\n";
	}
}

void Database::ReadLoginInfo()
{
	std::ifstream fin("Conturi.txt");

	if (!fin.is_open())
		throw eroare_fisier("Conturi.txt");

	int nrConturi;
	fin >> nrConturi;

	LogInInfo temp;

	for (int i = 0; i < nrConturi; ++i)
	{
		fin >> temp.username;
		fin >> temp.password;
		fin >> temp.id;

		accounts.push_back(temp);
	}
}

void Database::WriteTranzactions(Banca* banca)
{

	for (size_t i = 0; i < banca->GetTranzactii().size(); ++i)
	{
		Transfer* tran = dynamic_cast<Transfer*>(banca->GetTranzactii()[i].get());

		if (tran != nullptr)
		{
			std::cout << "Transfer de la " << tran->GetClientId() << " catre " << tran->GetReceiverId() << " in valoare de " << tran->GetSuma() << "\n";
		}


		Retragere* ret = dynamic_cast<Retragere*>(banca->GetTranzactii()[i].get());

		if (ret != nullptr)
		{
			std::cout << "Retragere de catre " << ret->GetClientId() << " in valoare de " << ret->GetSuma() << "\n";
		}


		Depunere* dep = dynamic_cast<Depunere*>(banca->GetTranzactii()[i].get());
		if (dep != nullptr)
		{
			std::cout << "Depunere de catre " << dep->GetClientId() << " in valoare de " << dep->GetSuma() << "\n";
		}


	}
}

std::vector<LogInInfo> Database::GetLogInInfo()
{
	return accounts;
}

int Database::IdOfUser(const std::string& username)
{
	for (auto temp : accounts)
		if (username == temp.username)
			return temp.id;
	return -1;
}

void Database::AddAccount(LogInInfo acc)
{
	ReadAccountsInfo(Banca::s_Banca);
	if (accounts.size() > 0)
		acc.id = accounts[accounts.size() - 1].id + 1;
	else
		acc.id = 0;

	Client temp(acc.id);
	Banca::s_Banca->AddClient(temp);

	accounts.push_back(acc);
	WriteLoginInfo();
	WriteAccountsInfo(Banca::s_Banca);
}
