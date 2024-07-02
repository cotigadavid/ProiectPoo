#pragma once

class ClientUI
{
public:
	ClientUI() = delete;

	static void Run();
	static void Run2(int input);
	static void LogIn();
	static void SignUp();
	static void DoTransaction(int input);

	static int ClientID;
};