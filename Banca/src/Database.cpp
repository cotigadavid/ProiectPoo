#include <fstream>

#include "../Headers/Database.h"
#include "../Headers/Banca.h"
#include "../Headers/Client.h"

void Database::CopyToFile(Banca& banca)
{
	std::ofstream fout("Date.txt");

	std::vector<Client> clienti = banca.GetClienti();

	fout << banca.GetNrClienti() << "\n";

	for (size_t i = 0; i < clienti.size(); ++i)
	{
		fout << clienti[i].GetId() << " " << clienti[i].GetNrConturi() << " " << clienti[i].GetNrCredite() << " ";

		std::vector<Cont> conturi = clienti[i].GetConturi();
		std::vector<Credit> credite = clienti[i].GetCredite();
		for (size_t j = 0; j < clienti[i].GetNrConturi(); ++j)
			fout << conturi[j].GetId() << " " << conturi[j].GetSold() << " ";

		for (size_t j = 0; j < clienti[i].GetNrCredite(); ++j)
			fout << credite[j].GetId() << " " << credite[j].GetSold() << " ";
	}

	fout.close();
}

void Database::ReadFromFile(Banca& banca)
{
	std::ifstream fin("Date.txt");

	int nrClienti = 0;

	fin >> nrClienti;

	int id;
	int nrConturi;
	int nrCredite;

	for (int i = 0; i < nrClienti; ++i)
	{
		fin >> id >> nrConturi >> nrCredite;

		Client clientTemp;
		clientTemp.SetId(id);
		
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
