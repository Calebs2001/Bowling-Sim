#include "Bowler.h"
#include "Scorecard.h"
#include "PinSet.h"

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
};
