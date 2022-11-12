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
	std::future<void> inputControllerObj = std::async(inputController, std::ref(direction), std::ref(stopInputController));
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
	system("CLS");
	size_t currentSize = player.size();
	displayScore(currentSize);
	inputControllerObj.get();
	bool endGame = false;
	while (!endGame) {
		if (GetKeyState(VK_ESCAPE) & 0x8000) {
			endGame = true;
		}
	}
}