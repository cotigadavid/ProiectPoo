#pragma once

class UI 
{
public:
	UI() = delete;

	static void AskForID();
	static void SelectClientAction();

	static int GetInput();
};