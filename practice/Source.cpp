#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "Field.cpp"
#include "declarations.h"

int main() {
	Snake player;
	Field container;
	bool ateFood = false;
	char direction = 'A';
	while (true) {
		if (GetKeyState('D') & 0x8000) {
			direction = 'A';
		} else if (GetKeyState('S') & 0x8000) {
			direction = 'B';
		} else if (GetKeyState('A') & 0x8000) {
			direction = 'C';
		} else if (GetKeyState('W') & 0x8000) {
			direction = 'D';
		}
		bool collided = player.update(direction, ateFood);
		if (ateFood) {
			ateFood = false;
		}
		if (collided) {
			break;
		} else {
			collided = container.render(player, ateFood);
			if (collided) {
				break;
			}
		}
		Sleep(200);
	}
	system("CLS");
	size_t currentSize = player.size();
	displayScore(currentSize);
	std::cin.get();
}