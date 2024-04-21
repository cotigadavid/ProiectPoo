#include "UI.h"

#include <iostream>

void UI::SelectAction()
{
	std::cout << "WELCOME TO THE DIGITAL BANKING SYSTEM\n";
	std::cout << "Please Select the desired action\n";
	std::cout << "0 - Add Client\n";
	std::cout << "1 - Remove Client\n";
	std::cout << "2 - Check Client\n\n";
}

void UI::AddClient()
{
}

void UI::RemoveClient()
{
}

void UI::CheckClient()
{
	std::cout << "Please provide the ID of the client\n";
}

int UI::GetInput()
{
	int a;
	std::cout << "Your Input: ";
	std::cin >> a;
	return a;
}
