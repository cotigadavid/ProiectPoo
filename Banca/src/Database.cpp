#include <fstream>

#include "Database.h"
#include "Banca.h"
#include "Client.h"

void Database::CopyToFile(Banca& banca)
{
	std::ofstream fout("Date.txt");

	std::vector<Client> clienti = banca.GetClienti();

	fout << banca.GetNrClienti() << "\n";

	for (int i = 0; i < clienti.size(); ++i)
	{
		fout << clienti[i].GetId() << " " << clienti[i].GetName() << " " << clienti[i].GetNrConturi() << " " << clienti[i].GetNrCredite() << " ";

		std::vector<Cont> conturi = clienti[i].GetConturi();
		std::vector<Credit> credite = clienti[i].GetCredite();
		for (int j = 0; j < clienti[i].GetNrConturi(); ++j)
			fout << conturi[j].GetId() << " " << conturi[j].GetSold() << " ";

		for (int j = 0; j < clienti[i].GetNrCredite(); ++j)
			fout << credite[j].GetId() << " " << credite[j].GetSold() << " ";
	}

	fout.close();
}

void Database::ReadFromFile(Banca& banca)
{
	std::ifstream fin("Date.txt");

	int nrClienti;

	fin >> nrClienti;

	int id;
	std::string name;
	int nrConturi;
	int nrCredite;

	for (int i = 0; i < nrClienti; ++i)
	{
		fin >> id >> name >> nrConturi >> nrCredite;

		Client clientTemp;
		clientTemp.SetId(id);
		clientTemp.SetName(name);
		
		int contId, sold;
		for (int j = 0; j < nrConturi; j++)
		{
			fin >> contId >> sold;
			Cont contTemp(contId, sold);
			clientTemp.AddCont(contTemp);
		}
		for (int j = 0; j < nrConturi; j++)
		{
			fin >> contId >> sold;
			Credit creditTemp(contId, sold);
			clientTemp.AddCredit(creditTemp);
		}

		banca.AddClient(clientTemp);
	}
	
}
