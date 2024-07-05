#include "../Headers/UI.h"

#include <iostream>

void UI::SelectClientAction()
{
	std::cout << "Please Select the desired action\n";
	std::cout << "0 - Add Account\n";
	std::cout << "1 - Remove Account\n";
	std::cout << "2 - Add Loan\n";
	std::cout << "3 - Remove Loan\n";
	std::cout << "4 - Make Transaction\n";
	std::cout << "-1 - Back\n\n";
}

int UI::GetInput()
{
	int a;
	std::cout << "Your Input: ";
	std::cin >> a;
	return a;
}
