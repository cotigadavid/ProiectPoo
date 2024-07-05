#pragma once

#include "Banca.h"

#include "Encriptare.h"

struct LogInInfo {
	std::string username;
	SecureContainer<std::string> password;
	int id = 0;
};

class Database
{
public:
	Database() = delete;

	static void WriteAccountsInfo(Banca* banca);
	static void ReadAccountsInfo(Banca* banca);

	static void WriteLoginInfo();
	static void ReadLoginInfo();

	static void WriteTranzactions(Banca* banca);

	static std::vector<LogInInfo> GetLogInInfo();
	static int IdOfUser(const std::string& username);
	static void AddAccount(LogInInfo acc);

private:

	static std::vector<LogInInfo> accounts;
};