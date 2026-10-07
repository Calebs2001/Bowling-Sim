#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "ASCII.h"


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

		default:
			std::cout << "\nInvalid choice. Please choose a number 1-4.Press enter to try again.";
			std::cin.ignore();
			std:cin.get();
			std::system("cls");
			break;
		}
	}
}

void Game::ShowMenu()
{
	drawMenuSign();
	std::cout << "\n\n\n";
	std::cout << "1. Start New Game\n";
	std::cout << "2. Practice\n";
	std::cout << "3. Leaderboard\n";
	std::cout << "4. Exit\n";
}

int Game::GetMenuChoice()
{
	int choice;

	std::cout << "Enter a number choice 1-4: ";
	std::cin >> choice;

	return choice;
}

void Game::StartGame()
{
	// Get the Bowler name and store it, and get the hand the Bowler throws with and store it.
	int handChoice;
	std::string userName;

	// user is prompted to enter their name and Bowler name is set then returned
	std::cout << "\nStarting game\n";
	std::cout << "Enter a name: ";
	std::cin >> userName;
	_bowler.SetName(userName);
	std::cout << "Welcome " << _bowler.GetName() << " to Bowling Sim!\n";

	//user is prompted and selects which hand they throw with. user enters which hand they want, set the hand, and cout get hand the user selected.
	std::cout << "\nWhich hand do you throw with?\n";
	std::cout << "1. Left\n";
	std::cout << "2. Right\n";
	std::cout << "3. Exit to Menu\n";
	std::cout << "Choice: ";
	std::cin >> handChoice;

	if (handChoice == 1)
	{
		_bowler.SetHand(Bowler::Hand::Left);
	}
	else if (handChoice == 2)
	{
		_bowler.SetHand(Bowler::Hand::Right);
	}
	else if (handChoice == 3) //Exit back to the menu
	{
		std::system("cls");
		return;
	}
	else
	{
		std::cout << "\nInvalid choice. Please select a number 1-2.\n";
	}

	// Clear scorecard and starts new gamne of 10 frames
	_scorecard.Reset();
	PlayFrames(10); 
	_scorecard.Display();

	std::cout << "\nFinal Scorecard:\n";
	_scorecard.Display();
	std::cout << "\nPress Enter to return to the menu.";
	std::cin.get();
}

void Game::Practice()
{
	std::cout << "\nEnter number of frames to practice: ";
	int frames = 0;
	// user input thr number of frames they want to play
	std::cin >> frames;
	// Resets the scorecard and plays they set number of frames
	_scorecard.Reset();
	PlayFrames(frames);
	_scorecard.Display();
}

void Game::PlayFrames(int count)
{
	// Needs to run until the end of the 10th frame. Or until the user chooses to quit the game back to the menu at anytime
	for (int i = 0; 0 < count; i++) // rotates through number of frames. 10 for the game, and count number for practice
	{
		Frames& frame = _scorecard.GetCurrentFrame(); // shows the scorcard for that frame
		_pinSet.Reset();

		// cout bowler name with each frame
		std::cout << "Scorecard:\n";
		std::cout << "Bowler: " << _bowler.GetName();
		std::cout << "\n--- Frame " << _scorecard.GetCurrentFrameNumber() << " ---\n";

		// Add in user option to pick a ball, roll stright or hook, or to exit the game back to the menu. clear screen after sleection

		for (int j = 0; j < 2; j++) // 2 rolls for each frame
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
		std::cout << "Current score: " << _scorecard.GetTotalScore() << "\n\n";
		_scorecard.AdvanceFrame();
		// loop back to the start to get the user's input again.
	}
	std::cout << "Total score: " << _scorecard.GetTotalScore() << "\n";
}

void Game::ShowLeaderboard()
{
	std::cout << "\nLeaderboard loading\n";
}
