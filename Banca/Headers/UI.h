#pragma once

class UI 
{
public:
	UI() = delete;

	static void SelectAction();
	static void AddClient();
	static void RemoveClient();
	static void CheckClient();

	static int GetInput();
};