#include <iostream>
#include <vector>
#include <string>
#include "Declarations.h"

struct SnakeNode {
	short x, y;
	Direction direction;

	SnakeNode(short i_x = 0, short i_y = 0, Direction i_direction = Direction::RIGHT) : x(i_x), y(i_y), direction(i_direction) {}
};

class Snake {
	private:
		std::vector<SnakeNode> nodes;

		Direction oppositeDirection(Direction& direction) {
			switch (direction) {
				case Direction::RIGHT:
					return Direction::LEFT;
				case Direction::DOWN:
					return Direction::UP;
				case Direction::LEFT:
					return Direction::RIGHT;
				case Direction::UP:
					return Direction::DOWN;
				default:
					return Direction::RIGHT;
			}
		}

	public:
		Snake() {
			SnakeNode headNode(2);
			SnakeNode middleNode(1);
			SnakeNode endNode;
			nodes.push_back(headNode);
			nodes.push_back(middleNode);
			nodes.push_back(endNode);
		}

		size_t size() {
			return nodes.size();
		}

		SnakeNode getNode(short index) {
			return nodes[index];
		}

		bool update(Direction& command, bool& ateFood) {
			// Add a new node to end of snake if food was eaten.
			if (ateFood) {
				SnakeNode& lastNode = nodes[nodes.size() - 1];
				short n_x = lastNode.x;
				short n_y = lastNode.y;
				Direction n_direction = lastNode.direction;
				switch (n_direction) {
					case Direction::RIGHT:
						n_x--;
						break;
					case Direction::DOWN:
						n_y--;
						break;
					case Direction::LEFT:
						n_x++;
						break;
					case Direction::UP:
						n_y++;
						break;
					default:
						break;
				}
				SnakeNode newNode(n_x, n_y, n_direction);
				nodes.push_back(newNode);
			}
			// change the direction of the head node to the command if issues.
			SnakeNode& headNode = nodes[0];
			if (command == oppositeDirection(headNode.direction)) {
				command = headNode.direction;
			} else {
				headNode.direction = command;
			}
			// Update all the node coordinates and directions to move the snake.
			Direction prevDirection = nodes[0].direction;
			bool collisionDetected = false;
			for (short i = 0; i < nodes.size(); i++) {
				SnakeNode& currentNode = nodes[i];
				// Change position.
				switch (currentNode.direction) {
					case Direction::RIGHT:
						currentNode.x++;
						break;
					case Direction::DOWN:
						currentNode.y++;
						break;
					case Direction::LEFT:
						currentNode.x--;
						break;
					case Direction::UP:
						currentNode.y--;
						break;
					default:
						break;
				}
				// Change Direction.
				Direction temp = currentNode.direction;
				currentNode.direction = prevDirection;
				prevDirection = temp;
				// Check for collision.
				if (i == 0) {
					headNode = nodes[i];
				} else if (headNode.x == currentNode.x && headNode.y == currentNode.y) {
					collisionDetected = true;
				}
			}
			return collisionDetected;
		}
};