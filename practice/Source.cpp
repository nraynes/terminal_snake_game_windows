#include <iostream>
#include <future>
#include <stdlib.h>
#include <Windows.h>
#include "Field.cpp"
#include "declarations.h"

int main() {
	Snake player;
	Field container;
	bool ateFood = false;
	char direction = 'A';
	bool stopInputController = false;

	// Start the input controller to watch for key presses.
	std::future<void> inputControllerObj = std::async(inputController, std::ref(direction), std::ref(stopInputController));

	// Start the game loop.
	while (true) {
		bool collided = player.update(direction, ateFood);
		if (ateFood) {
			ateFood = false;
		}
		if (collided) {
			stopInputController = true;
			break;
		} else {
			collided = container.render(player, ateFood);
			if (collided) {
				stopInputController = true;
				break;
			}
		}
		Sleep(200);
	}

	// Display score at end of game, stop the input controller, and wait for the escape key to be pressed to close game.
	size_t currentSize = player.size();
	clearscreen();
	displayScore(currentSize);
	inputControllerObj.get();
	bool endGame = false;
	while (!endGame) {
		if (GetKeyState(VK_ESCAPE) & 0x8000) {
			endGame = true;
		}
	}
}