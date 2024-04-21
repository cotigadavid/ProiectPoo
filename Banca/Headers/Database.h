#pragma once

#include "Banca.h"

class Database
{
public:
	Database() = delete;

	static void CopyToFile(Banca& banca);
	static void ReadFromFile(Banca& banca);
};