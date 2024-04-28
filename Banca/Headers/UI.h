#pragma once

class UI 
{
public:
	UI() = delete;

	static void SelectAction();
	static void AskForID();
	static void SelectClientAction();

	static int GetInput();
};