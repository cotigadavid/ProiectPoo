#include "../Headers/UI.h"

#include <iostream>

void UI::WelcomeMessage()
{
	std::cout << "WELCOME TO THE DIGITAL BANKING SYSTEM\n\n";
}

void UI::SelectAction()
{
	std::cout << "Please Select the desired action\n";
	std::cout << "0 - Add Client\n";
	std::cout << "1 - Remove Client\n";
	std::cout << "2 - Check Client\n";
	std::cout << "3 - Further Action on Client \n";
	std::cout << "-1 - Exit \n\n";
}

void UI::AskForID()
{
	std::cout << "Please provide the ID of the client\n";
}

void UI::SelectClientAction()
{
	std::cout << "Please Select the desired action\n";
	std::cout << "0 - Add Account\n";
	std::cout << "1 - Remove Account\n";
	std::cout << "2 - Add Credit\n";
	std::cout << "3 - Remove Credit\n";
	std::cout << "-1 - Back\n\n";
}

int UI::GetInput()
{
	int a;
	std::cout << "Your Input: ";
	std::cin >> a;
	return a;
}
