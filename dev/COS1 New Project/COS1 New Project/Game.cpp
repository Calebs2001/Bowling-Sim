#include <iostream>
#include <cstdlib>
#include <random>
#include "Game.h"
#include "ASCII.h"
#include "Input.h"

Game::Game()
{  }

void ClearScreen()
{
	std::system("cls");
}

void EnterScreenClear()
{
	std::cin.get();
	ClearScreen();
}

void Game::Run()
{
	bool running = true;
	ClearScreen();

	while (running)
	{
		ShowMenu();

		int userChoice = Input::GetNumber("\nEnter a mneu option number 1-4: ", 1, 4);

		switch (userChoice)
		{
		case 1:
			ClearScreen();
			StartGame();
			break;

		case 2:
			Practice();
			break;

		case 3:
			ClearScreen();
			ShowLeaderboard();
			break;

		case 4:
			running = false;
			break;

		default: 
			std::cout << "Invalid option. Please enter a number 1-4.\n";
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


void Game::StartGame()
{
	// user is prompted to enter their name and Bowler name is set then returned
	std::cout << "Starting game\n";
	setColor(BRIGHT_WHITE);
	std::string userName = Input::GetString("Enter a name: ");
	setColor(WHITE);
	_bowler.SetName(userName);
	std::cout << "Welcome " << _bowler.GetName() << " to Bowling Sim!\n";

	//user is prompted and selects which hand they throw with. user enters which hand they want, set the hand, and cout get hand the user selected.
	while (true)
	{
		std::cout << "\nWhich hand do you throw with? Enter a number 1-3:\n";
		setColor(BRIGHT_WHITE);
		std::cout << "1. Left\n";
		std::cout << "2. Right\n";
		setColor(RED);
		std::cout << "3. Exit to Menu\n";
		setColor(WHITE);
		int handChoice = Input::GetNumber("Enter a number 1-3: ", 1, 3);

		// Handle valid numeric choices
		if (handChoice == 1)
		{
			_bowler.SetHand(Bowler::Hand::Left);
			break;
		}
		else if (handChoice == 2)
		{
			_bowler.SetHand(Bowler::Hand::Right);
			break;
		}
		else if (handChoice == 3)
		{
			ClearScreen();
			return;
		}
	}
	
	std::cout << "Great! Now press Enter to start playing!";
	std::cin.get();

	ClearScreen();

	// Clear scorecard and starts new gamne of 10 frames
	_scorecard.Reset();
	PlayFrames(10); 

	setColor(BRIGHT_WHITE);
	std::cout << "\nFinal Scorecard:\n";
	setColor(YELLOW);
	_scorecard.Display();
	setColor(WHITE);
	std::cout << "\nPress Enter to return to the Menu.";
	EnterScreenClear();
}

void Game::Practice()
{
	std::cout << "\nEnter number of frames to practice: ";
	int frames = 0;
	// user input thr number of frames they want to play
	std::cin >> frames;

	// Resets the scorecard and plays they set number of frames
	ClearScreen();
	_scorecard.Reset();
	PlayFrames(frames);

	std::cout << "\nPractice Scorecard\n";
	_scorecard.Display();

	std::cout << "\nPress Enter to return to the Menu.";
	EnterScreenClear();
}

void Game::PlayFrames(int count)
{
	bool playing = true;

	if (count < 1) // if frames left is less than one returns and moves on to show scorecard
	{
		return;
	}

	for (int i = 0; i < count and playing; i++) // rotates through number of frames. 10 for the game, and count number for practice
	{
		Frames& frame = _scorecard.GetCurrentFrame(); // shows the scorcard for that frame
		_pinSet.Reset();

		// cout bowler name with each frame
		setColor(YELLOW);
		std::cout << "Scorecard:\n";
		setColor(CYAN);
		std::cout << "Bowler: " << _bowler.GetName();
		std::cout << "\n--- Frame " << _scorecard.GetCurrentFrameNumber() << " of " << count << " ---\n";
		std::cout << "============================\n";
		std::cout << "Current score: " << _scorecard.GetTotalScore() << "\n";
		setColor(WHITE);

		// First roll of frame
		bool continuePlaying = PlayRoll(frame, 1);
		bool tenthFrame = (frame.GetFrameNumber() == 10);

		if (!continuePlaying) // quit playing
		{
			ClearScreen();
			return;
		}

		// second roll if user doesn't strike
		if (!frame.IsStrike() or tenthFrame)
		{
			if (tenthFrame and frame.IsStrike())
			{
				_pinSet.Reset();
			}

			std::cout << "\nPress Enter for second roll!";
			EnterScreenClear();
			continuePlaying = PlayRoll(frame, 2);

			if (!continuePlaying)
			{
				ClearScreen();
				return;
			}

			if (frame.IsSpare())
			{
				setColor(YELLOW);
				std::cout << "\nSPARE!\n";
				setColor(WHITE);
			}
		}
		else
		{
			setColor(GREEN);
			std::cout << "\nSTRIKE!\n";
			setColor(WHITE);
		}

		if (tenthFrame and (frame.IsStrike() or frame.IsSpare()))
		{
			_pinSet.Reset();
			std::cout << "\n10th frame bonus roll! Press Enter to continue!";
			EnterScreenClear();

			continuePlaying = PlayRoll(frame, 3);

			if (!continuePlaying)
			{
				ClearScreen();
				return;
			}
		}

		// Outputs the frame number and gets how many pins were knocked down to display to the user then advances to the next frame with a lear screen
		std::cout << "\nFrame" << frame.GetFrameNumber() << " total pins: " << frame.GetPinsKnockedDown() << "\n";
		std::cout << "Press Enter to continue";
		EnterScreenClear();

		if (i < count - 1)
		{
			_scorecard.AdvanceFrame();
		}
	}
}

// Gets the user input on if they want to rool. Which ball to use, and how to throw the ball
bool Game::PlayRoll(Frames& frame, int rollNumber)
{
	setColor(BRIGHT_WHITE);
	std::cout << "Roll " << rollNumber << "\n";
	setColor(WHITE);

	setColor(YELLOW);
	std::cout << "1. Choose ball and roll\n";
	setColor(RED);
	std::cout << "2. Exit to Menu\n";
	setColor(WHITE);
	int choice = Input::GetNumber("Enter a number 1-2: ", 1, 2);

	////// Add catch all user input vlaidation/////////
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

	// Select ball
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

	// Select how to throw
	std::cout << "\nThrow: ";
	if (throwStyle == Roll::ThrowStyle::Straight)
	{
		std::cout << "Straight\n";
	}
	else
	{
		std::cout << "Hook\n";
	}

	// Is an int because need the number of knocked pins but using the simulation method
	int knocked = SimulateRoll(*ball, throwStyle, rollNumber);
	// is an int because need to know the number of standing pins from the PinSet class
	int standing = _pinSet.GetStandingCount();

	//initalize the number of pins knocked down to 0
	int knockedDown = 0;

	// As lomng a 1 pin is less than or equal to 10 and the number od knocked down pins is less than
	// the number of pins knocked from the simulation, then add how the number of pins knocked down.
	for (int pin = 1; pin <= 10 and knockedDown < knocked; pin++)
	{
		if (_pinSet.GetIsStanding(pin))
		{
			_pinSet.KnockDown(pin);
			++knockedDown;
		}
	}

	(*roll).SetPinsKnockedDown(knockedDown);
	// adds the second roll for the frame
	frame.AddRoll(roll);

	std::cout << "\nPins left standing:\n";
	_pinSet.Display();
	std::cout << "\nYou knocked down " << knockedDown << " pins.\n";

	return true;
}

// Ball selection menu
Ball::Type Game::SelectBall()
{
	while (true)
	{
		setColor(YELLOW);
		std::cout << "1. Spare Ball\n";
		std::cout << "2. Pearl Reactive\n";
		std::cout << "3. Solid Reactive\n";
		std::cout << "4. Urethane\n";
		setColor(WHITE);
		int choice = Input::GetNumber("Enter a number 1-4: ", 1, 4);


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
			std::cout << "\nInvalid choice. Please choose a number 1-4.\n";
			break;
		}
	}
}


// How to throw the ball menu selection
Roll::ThrowStyle Game::SelectedThrowStyle()
{
	setColor(BRIGHT_WHITE);
	std::cout << "1. Straight\n";
	std::cout << "2. Hook\n";
	
	int choice = Input::GetNumber("Enter a number 1-2: ", 1, 2);

	if (choice == 1)
	{
		return Roll::ThrowStyle::Straight;
	}
	if (choice == 2)
	{
		return Roll::ThrowStyle::Hook;
	}
}


// Gets the ball strike and spare chances and randomizes the score based on pins hit
int Game::SimulateRoll(const Ball& ball, Roll::ThrowStyle style, int rollNumber)
{
	int standing = _pinSet.GetStandingCount();

	if (standing == 0)
	{
		return 0;
	}

	// Initalize strike and spare chance
	int strikeChance = 0;
	int spareChance = standing;

	// Sets the chance of a strike or spare for each ball
	switch (ball.GetType())
	{
	case Ball::Type::Spare:
		strikeChance = 10;
		spareChance = 75;
		break;

	case Ball::Type::PearlReactive:
		strikeChance = 40;
		spareChance = 25;
		break;

	case Ball::Type::SolidReactive:
		strikeChance = 30;
		spareChance = 25;
		break;

	case Ball::Type::Urethane:
		strikeChance = 35;
		spareChance = 20;
		break;
	}

	// increases the chance to strike or does nothing to ball if the user chooses to hook
	// Might want to add it subtracting spare chance to some of the balls
	if (style == Roll::ThrowStyle::Hook)
	{
		switch (ball.GetType())
		{
		case Ball::Type::Spare:
			strikeChance += 0;
			spareChance -= 25;
			break;

		case Ball::Type::PearlReactive:
			strikeChance += 10;
			spareChance -= 10;
			break;

		case Ball::Type::SolidReactive:
			strikeChance += 10;
			spareChance -= 5;
			break;
			
		case Ball::Type::Urethane:
			strikeChance += 5;
			spareChance -= 10;
			break;
		}
	}

	// Makes sure strike and spare chance don't go over 100
	if (strikeChance > 100) strikeChance = 100;
	if (spareChance > 100) spareChance = 100;

	// Random seed generator so the game isn't repetative
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> chanceRoll(1, 100);

	if (standing == 10)
	{
		if (chanceRoll(rng) <= strikeChance)
		{
			return 10;
		}
		std::uniform_int_distribution<int> pinsRoll(0, 9);
		return pinsRoll(rng);
	}

	if (rollNumber == 2)
	{
		if (chanceRoll(rng) <= spareChance)
		{
			return standing;
		}
		std::uniform_int_distribution<int> pinsRoll(0, standing - 1);
		return pinsRoll(rng);
	}

	std::uniform_int_distribution<int> pinsRoll(0, standing);
	return pinsRoll(rng);
}


// Outputs the leaderboard of player name and their scoere. Will need File I/O for this
void Game::ShowLeaderboard()
{
	std::cout << "\nLeaderboard loading...\n";
	std::cout << "Press Enter to return to Menu.";
	EnterScreenClear();
}
