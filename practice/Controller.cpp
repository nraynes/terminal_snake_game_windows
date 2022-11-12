#include <Windows.h>
#include "declarations.h"

void inputController(char& direction, bool& endControl) {
	while (!endControl) {
		if ((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000)) {
			direction = 'A';
		} else if ((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000)) {
			direction = 'B';
		} else if ((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000)) {
			direction = 'C';
		} else if ((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000)) {
			direction = 'D';
		}
	}
}