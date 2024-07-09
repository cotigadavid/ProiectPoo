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

	fout << banca->GetClienti().size() << "\n";

	for (size_t i = 0; i < clienti.size(); ++i)
	{
		fout << clienti[i].GetId() << " " << clienti[i].GetConturi().size() << " " << clienti[i].GetLoans().size() << " ";

		std::vector<Cont> conturi = clienti[i].GetConturi();
		std::vector<Loan> Loans = clienti[i].GetLoans();
		for (size_t j = 0; j < clienti[i].GetConturi().size(); ++j)
			fout << conturi[j].GetId() << " " << conturi[j].GetSold() << " ";

		for (size_t j = 0; j < clienti[i].GetLoans().size(); ++j)
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
		fout << accounts[i].username << " " << accounts[i].password.Get() << " " << accounts[i].id << "\n";
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
		std::string s;
		fin >> s;
		temp.password.Set(s);
		fin >> temp.id;

		accounts.push_back(temp);
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
	ReadAccountsInfo(Banca::GetInstance());
	if (accounts.size() > 0)
		acc.id = accounts[accounts.size() - 1].id + 1;
	else
		acc.id = 0;

	Client temp(acc.id);
	Banca::GetInstance()->AddClient(temp);

	accounts.push_back(acc);
	WriteLoginInfo();
	WriteAccountsInfo(Banca::GetInstance());
}
