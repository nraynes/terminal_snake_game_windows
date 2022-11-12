#include <iostream>
#include <string>

void log(const char* message) {
	std::cout << message << "\n";
}

void log(int message) {
	std::cout << message << "\n";
}

int multiply(int a, int b) {
	int c = a * b;
	log(c);
	return c;
}