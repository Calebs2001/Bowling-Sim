#include <iostream>
#include "Game.h"

Game::Game()
{  }

void Game::Run() 
{
	bool running = true;

	while (running)
	{
		ShowMenu();

		int userChoice = GetMenuChoice();

		switch (userChoice)
		{
		case 1:
			StartGame();
			break;

		case 2:
			Practice();
			break;

		case 3:
			ShowLeaderboard();
			break;

		case 4:
			running = false;
			break;
		}
	}
}

void Game::ShowMenu()
{
	std::cout << "\n";
	std::cout << "=========================\n";
	std::cout << "      BOWLING GAME\n";
	std::cout << "=========================\n";
	std::cout << "1. Start New Game\n";
	std::cout << "2. Practice\n";
	std::cout << "3. Leaderboard\n";
	std::cout << "4. Exit\n";
}

int Game::GetMenuChoice()
{
	int choice;

	std::cout << "Enter choice: ";
	std::cin >> choice;

	return choice;
}

void Game::StartGame()
{
	std::cout << "\nStarting game\n";
}

void Game::Practice()
{
	std::cout << "\nStarting practice\n";
}

void Game::ShowLeaderboard()
{
	std::cout << "\nLeaderboard loading\n";
}
