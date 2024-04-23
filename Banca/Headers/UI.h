#pragma once

class UI 
{
public:
	UI() = delete;

	static void SelectAction();
	static void AddClient();
	static void RemoveClient();
	static void AskForID();

	static int GetInput();
};