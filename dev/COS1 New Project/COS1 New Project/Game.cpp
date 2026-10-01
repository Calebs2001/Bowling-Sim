#include <iostream>
#include "Game.h"
#include "PinSet.h"

Game::Game()
{  }

void Game::Run() 
{
	TestPinSet();
}

void Game::TestPinSet()
{
	PinSet pins;

	pins.Display();

	pins.KnockDown(1);
	pins.KnockDown(5);
	pins.KnockDown(10);

	pins.Display();

	pins.Reset();

	pins.Display();
}