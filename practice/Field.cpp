#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Snake.cpp"


class Field
{
private:
	char matrix[22][22];
	int foodOnPlate = 0;

public:
	bool render(Snake& player, bool& ateFood) {
		system("CLS");
		bool addFood = rand() % 100 + 1 < 10 && foodOnPlate < 5;
		int food_x = -1;
		int food_y = -1;
		if (addFood) {
			food_x = rand() % 20;
			food_y = rand() % 20;
		}
		for (int i = 0; i < player.size(); i++) {
			char displayCharacter = '|';
			SnakeNode currentNode = player.getNode(i);
			// Detect collisions.
			if (currentNode.x < 0 || currentNode.x > 20 || currentNode.y < 0 || currentNode.y > 20) {
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
				case 'A':
				case 'C':
					displayCharacter = '-';
					break;
				default:
					break;
			}
			matrix[currentNode.y][currentNode.x] = displayCharacter;
		}
		// 10% chance to add more food to the field if the max hasn't been reached
		if (addFood) {
			matrix[food_y][food_x] = 'O';
			foodOnPlate++;
		}
		// Display current field.
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {
				if (matrix[i][j] != '|' && matrix[i][j] != '-' && matrix[i][j] != 'O') {
					matrix[i][j] = i == 21 || j == 21 ? '+' : ' ';
				}
				std::cout << matrix[i][j];
				if (matrix[i][j] != 'O')
					matrix[i][j] = ' ';
			}
			std::cout << "\n";
		}
		return false;
	}
};