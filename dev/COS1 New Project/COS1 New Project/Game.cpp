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

		default: // Will run in  a inifinite loop if a letter or multile numbers are entered
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

	std::cout << "Great! Now press Enter to start playing";
	std::cin.ignore();
	std::cin.get();

	std::system("cls");

	// Clear scorecard and starts new gamne of 10 frames
	_scorecard.Reset();
	PlayFrames(10); 

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

	std::cout << "\nPractice Scorecard\n";
	_scorecard.Display();

	std::cout << "\nPress Enter to return to the menu.";
	std::cin.get();
}

void Game::PlayFrames(int count)
{
	bool playing = true;
	if (count < 1)
	{
		return;
	}

	if (count > 10)
	{
		count = 10;
	}

	// Needs to run until the end of the 10th frame. Or until the user chooses to quit the game back to the menu at anytime
	for (int i = 0; i < count and playing; i++) // rotates through number of frames. 10 for the game, and count number for practice
	{
		Frames& frame = _scorecard.GetCurrentFrame(); // shows the scorcard for that frame
		_pinSet.Reset();

		// cout bowler name with each frame
		std::cout << "Scorecard:\n";
		std::cout << "Bowler: " << _bowler.GetName();
		std::cout << "\n--- Frame " << _scorecard.GetCurrentFrameNumber() << " of " << count << " ---\n";
		std::cout << "============================\n";
		std::cout << "Current score: " << _scorecard.GetTotalScore() << "\n";

		// Add in user option to pick a ball, roll stright or hook, or to exit the game back to the menu. clear screen after sleection
		bool continuePlaying = PlayRoll(frame, 1);

		if (!continuePlaying)
		{
			std::cout << "\nReturning to menu.";
			return;
		}

		if (!frame.IsStrike())
		{
			continuePlaying = PlayRoll(frame, 2);

			if (!continuePlaying)
			{
				std::cout << "\nReturning to menu.";
				return;
			}

			if (frame.IsSpare())
			{
				std::cout << "\nSPARE!\n";
			}
		}
		else
		{
			std::cout << "\nSTRIKE!\n";
		}

		std::cout << "\nFrame" << frame.GetFrameNumber() << " total pins: " << frame.GetPinsKnockedDown() << "\n";
		std::cout << "Press Enter to continue";
		std::cin.ignore();
		std::cin.get();

		std::system("cls");

		if (i < count - 1)
		{
			_scorecard.AdvanceFrame();
		}
	}

	std::cout << "\nFinal score: " << _scorecard.GetTotalScore() << "\n";
}

bool Game::PlayRoll(Frames& frame, int rollNumber)
{
	int choice;
	std::cout << "Roll " << rollNumber << "\n";

	std::cout << "\nWhat would you like to do?\n";
	std::cout << "1. Choose ball and roll\n";
	std::cout << "2. Exit game to menu\n";
	std::cout << "Choice: ";
	std::cin >> choice;

	if (choice == 2)
	{
		return false;
	}

	if (choice != 1)
	{
		std::cout << "\nInvalid choice. Please choose a number 1-2.\n";
	}


	Ball::Type ballType = SelectBall();
	Roll::ThrowStyle throwStyle = SelectedThrowStyle();
	Ball* ball = new Ball(ballType);
	Roll* roll = new Roll(ball, throwStyle);

	switch (ballType)
	{
	case Ball::Type::Spare:
		std::cout << "Spare Ball";
		break;

	case Ball::Type::PearlReactive:
		std::cout << "Pearl Reactive";
		break;

	case Ball::Type::SolidReactive:
		std::cout << "Solid Reactive";
		break;

	case Ball::Type::Urethane:
		std::cout << "Urethane";
		break;
	}

	std::cout << "\nThrow: ";
	if (throwStyle == Roll::ThrowStyle::Straight)
	{
		std::cout << "Straight\n";
	}
	else
	{
		std::cout << "Hook\n";
	}

	int knocked = SimulateRoll(*ball, throwStyle);

	int standing = _pinSet.GetStandingCount();

	if (knocked > standing)
	{
		knocked = standing;
	}

	int knockedDown = 0;

	for (int pin = 1; pin <= 10 and knockedDown < knocked; pin++)
	{
		if (_pinSet.GetIsStanding(pin))
		{
			_pinSet.KnockDown(pin);
			++knockedDown;
		}
	}

	(*roll).SetPinsKnockedDown(knockedDown);
	frame.AddRoll(roll);

	std::cout << "\nPins left standing\n";
	_pinSet.Display();
	std::cout << "\nYou knocked down " << knockedDown << " pins.\n";

	return true;
}



Ball::Type Game::SelectBall()
{
	int choice;

	std::cout << "\nChoose your ball:\n";
	std::cout << "1. Spare Ball\n";
	std::cout << "2. Pearl Reactive\n";
	std::cout << "3. Solid Reactive\n";
	std::cout << "4. Urethane\n";
	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		return Ball::Type::Spare;

	case 2:
		return Ball::Type::PearlReactive;

	case 3:
		return Ball::Type::SolidReactive;

	case 4:
		return Ball::Type::Urethane;

	default:
		std::cout << "\nInvalid choice. Enter a number 1-4.\n";
		break;
	}
}



Roll::ThrowStyle Game::SelectedThrowStyle()
{
	int choice;

	std::cout << "\nChoose your throw:\n";
	std::cout << "1. Straight\n";
	std::cout << "2. Hook\n";
	std::cout << "Choice: ";
	std::cin >> choice;

	if (choice == 1)
	{
		return Roll::ThrowStyle::Straight;
	}

	if (choice == 2)
	{
		return Roll::ThrowStyle::Hook;
	}

	std::cout << "\nInvalid choice. Please enter a number 1-2\n";
}



int Game::SimulateRoll(const Ball& ball, Roll::ThrowStyle style)
{
	int standing = _pinSet.GetStandingCount();

	if (standing == 0)
	{
		return 0;
	}

	int minimum = 0;
	int maximum = standing;

	switch (ball.GetType())
	{
	case Ball::Type::Spare:
		maximum = standing;
		break;

	case Ball::Type::PearlReactive:
		maximum = standing;
		break;

	case Ball::Type::SolidReactive:
		maximum = standing;
		break;

	case Ball::Type::Urethane:
		maximum = standing;
		break;
	}

	if (style == Roll::ThrowStyle::Hook and maximum < 10)
	{
		++maximum;
	}

	if (maximum > standing)
	{
		maximum = standing;
	}

	return minimum + (std::rand() % (maximum - minimum + 1));
}



void Game::ShowLeaderboard()
{
	std::cout << "\nLeaderboard loading\n";
}
