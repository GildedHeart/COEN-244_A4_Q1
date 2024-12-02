#include "Utility.h"
#include <iostream>
#include <string>

void nextLine(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << std::endl;
	}
}

void charLine(char c, int l1, int l2, int n) {
	nextLine(l1);
	for (int i = 0; i < n; i++) {
		std::cout << c;
	}
	nextLine(l2);
}
