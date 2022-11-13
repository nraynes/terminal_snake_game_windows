#pragma once

enum class Direction {
	RIGHT = 'A',
	DOWN = 'B',
	LEFT = 'C',
	UP = 'D'
};

void displayScore(size_t& finalLength);

void inputController(Direction& direction, bool& endControl);

void clearscreen();

void hideCursor();