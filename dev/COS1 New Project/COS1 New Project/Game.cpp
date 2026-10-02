#include <iostream>
#include <cstdlib>
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
	std::cout << "      BOWLING Sim\n";
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
	_scorecard.Reset();
	PlayFrames(10); // check back with this
	_scorecard.Display();
}

void Game::Practice()
{
	std::cout << "\nEnter ammount of frames to practice: ";
	int frames = 0;
	std::cin >> frames;
	_scorecard.Reset();
	PlayFrames(frames);
	_scorecard.Display();
}

void Game::PlayFrames(int count)
{
	for (int i = 0; 0 < count; i++)
	{
		Frames& frame = _scorecard.GetCurrentFrame();
		_pinSet.Reset();

		std::cout << "\n--- Frame " << _scorecard.GetCurrentFrameNumber() << " ---\n";

		for (int j = 0; j < 2; j++)
		{
			_pinSet.Display();

			Roll* roll = new Roll(new Ball(Ball::Type::Spare), Roll::ThrowStyle::Straight);

			int standing = _pinSet.GetStandingCount();
			int knocked = std::rand() % (standing + 1);

			int toKnock = knocked;
			for (int p = 1; p <= 10 and toKnock > 0; p++)
			{
				if (_pinSet.GetIsStanding(p))
				{
					_pinSet.KnockDown(p);
					--toKnock;
				}
			}

			(*roll).SetPinsKnockedDown(knocked);
			frame.AddRoll(roll);

			std::cout << "Pins knocked down - " << knocked << " pins.\n";

			if (j == 0 and frame.IsStrike())
			{
				std::cout << "STRIKE!\n";
				break;
			}
		}
		_scorecard.AdvanceFrame();
	}
}

void Game::ShowLeaderboard()
{
	std::cout << "\nLeaderboard loading\n";
}
