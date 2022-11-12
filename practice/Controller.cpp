#include <Windows.h>

void inputController(char& direction, bool& endControl) {
	while (!endControl) {
		if (GetKeyState('D') & 0x8000) {
			direction = 'A';
		}
		else if (GetKeyState('S') & 0x8000) {
			direction = 'B';
		}
		else if (GetKeyState('A') & 0x8000) {
			direction = 'C';
		}
		else if (GetKeyState('W') & 0x8000) {
			direction = 'D';
		}
	}
}