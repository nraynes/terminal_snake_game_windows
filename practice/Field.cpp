#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Snake.cpp"
#include "Declarations.h"

class Field
{
private:
	char matrix[22][42];
	short foodOnPlate = 0;

public:

	bool render(Snake& player, bool& ateFood) {
		// 10% chance to add food to the field if not at max.
		bool addFood = rand() % 100 + 1 < 10 && foodOnPlate < 5;
		short food_x = -1;
		short food_y = -1;
		if (addFood) {
			food_x = rand() % 40;
			food_y = rand() % 20;
		}
		for (short i = 0; i < player.size(); i++) {
			char displayCharacter = '|';
			SnakeNode currentNode = player.getNode(i);
			// Detect collisions.
			if (currentNode.x < 0 || currentNode.x > 40 || currentNode.y < 0 || currentNode.y > 20) {
				return true;
			}
			// Check if food was eaten.
			if (matrix[currentNode.y][currentNode.x] == 'O') {
				ateFood = true;
				foodOnPlate--;
			}
			if (addFood) {
				if (currentNode.x == food_x && currentNode.y == food_y) {
					addFood = false;
				}
			}
			switch (currentNode.direction) {
				case Direction::RIGHT:
				case Direction::LEFT:
					displayCharacter = '-';
			}
			matrix[currentNode.y][currentNode.x] = displayCharacter;
		}
		if (addFood) {
			matrix[food_y][food_x] = 'O';
			foodOnPlate++;
		}

		// Build the field.
		std::string playingField;
		for (short i = 0; i < 22; i++) {
			for (short j = 0; j < 42; j++) {
				if (matrix[i][j] != '|' && matrix[i][j] != '-' && matrix[i][j] != 'O') {
					matrix[i][j] = i == 21 || j == 41 ? '+' : ' ';
				}
				playingField += matrix[i][j];
				if (matrix[i][j] != 'O')
					matrix[i][j] = ' ';
			}
			playingField += "\n";
		}

		// Clear the screen and display the current field.
		clearscreen();
		std::cout << playingField;
		return false;
	}
};