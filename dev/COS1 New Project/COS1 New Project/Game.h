#pragma once
#include "Bowler.h"
#include "Scorecard.h"
#include "PinSet.h"
#include "Ball.h"
#include "Roll.h"

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

	int GetMenuChoice();
	void ShowMenu();
	void StartGame();
	void Practice();
	void ShowLeaderboard();
	void PlayFrames(int count);

	bool PlayRoll(Frames& frame, int rollNumber);
	Ball::Type SelectBall();
	Roll::ThrowStyle SelectedThrowStyle();
	int SimulateRoll(const Ball& ball, Roll::ThrowStyle style);
};
