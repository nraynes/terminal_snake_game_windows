#include <Windows.h>
#include "Declarations.h"

void inputController(Direction& direction, bool& endControl) {
	while (!endControl) {
		if ((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000)) {
			direction = Direction::RIGHT;
		} else if ((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000)) {
			direction = Direction::DOWN;
		} else if ((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000)) {
			direction = Direction::LEFT;
		} else if ((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000)) {
			direction = Direction::UP;
		}
	}
}