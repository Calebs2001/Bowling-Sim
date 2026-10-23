#pragma once
#include "Bowler.h"
#include "Scorecard.h"
#include "PinSet.h"
#include "Ball.h"
#include "Roll.h"
#include "Input.h"
#include <vector>

class Game
{
public:

	Game();

	void Run();

	//void TestPinSet();

private:
	Bowler _bowler;
	Scorecard _scorecard;
	PinSet _pinSet;

	// Base game and menus
	void ShowMenu();
	void StartGame();
	void Practice();
	void ShowLeaderboard();
	bool PlayFrames(int count);

	//Playing game selection and sim managment
	bool PlayRoll(Frames& frame, int rollNumber);
	Ball::Type SelectBall();
	Roll::ThrowStyle SelectedThrowStyle();
	int SimulateRoll(const Ball& ball, Roll::ThrowStyle style, int rollNumber);

	//Ball and oil managment
	std::vector<Ball> _balls;
	Ball& GetBallByType(Ball::Type type);

	void SaveScore();
};
