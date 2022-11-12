#include <iostream>
#include <vector>
#include <string>

/*
	Directions:
	A = right
	B = down
	C = left
	D = right
*/

struct SnakeNode {
	int x, y;
	char direction;

	SnakeNode(int i_x = 0, int i_y = 0, char i_direction = 'A') : x(i_x), y(i_y), direction(i_direction) {}
};

class Snake {
	private:
		std::vector<SnakeNode> nodes;

		char oppositeDirection(char& direction) {
			switch (direction) {
				case 'A':
					return 'C';
				case 'B':
					return 'D';
				case 'C':
					return 'A';
				case 'D':
					return 'B';
				default:
					return 'U';
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

		SnakeNode getNode(int index) {
			return nodes[index];
		}

		bool update(char& command, bool& ateFood) {
			// Add a new node to end of snake if food was eaten.
			if (ateFood) {
				SnakeNode& lastNode = nodes[nodes.size() - 1];
				int n_x = lastNode.x;
				int n_y = lastNode.y;
				char n_direction = lastNode.direction;
				switch (n_direction) {
					case 'A':
						n_x--;
						break;
					case 'B':
						n_y--;
						break;
					case 'C':
						n_x++;
						break;
					case 'D':
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
			if (command == 'U' || command == oppositeDirection(headNode.direction)) {
				command = headNode.direction;
			} else {
				headNode.direction = command;
			}
			// Update all the node coordinates and directions to move the snake.
			char prevDirection = nodes[0].direction;
			bool collisionDetected = false;
			for (int i = 0; i < nodes.size(); i++) {
				SnakeNode& currentNode = nodes[i];
				// Change position.
				switch (currentNode.direction) {
					case 'A':
						currentNode.x++;
						break;
					case 'B':
						currentNode.y++;
						break;
					case 'C':
						currentNode.x--;
						break;
					case 'D':
						currentNode.y--;
						break;
					default:
						break;
				}
				// Change Direction.
				char temp = currentNode.direction;
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

		void display() {
			std::string nodeDirection;
			for (int i = 0; i < nodes.size(); i++) {
				switch (nodes[i].direction) {
					case 'A':
						nodeDirection = "Right";
						break;
					case 'B':
						nodeDirection = "Down";
						break;
					case 'C':
						nodeDirection = "Left";
						break;
					case 'D':
						nodeDirection = "Up";
						break;
					default:
						break;
				}
				std::cout << "Node " << i + 1 << (i == 0 ? " (HEAD)" : i == nodes.size() - 1 ? " (TAIL)" : "") << ": { " << nodes[i].x << ", " << nodes[i].y << ", " << nodeDirection << " }\n";
			}
			std::cout << "\n";
		}
};