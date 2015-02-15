/*
 * MainClass.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Lubo
 */

#include <iostream>
#include "Roulette.cpp"

using namespace std;

class MainClass {
public:
	static void main(string args[] = nullptr) {
		Roulette roulette(10);
			roulette.spin(5000000000, true);
	}
};

int main() {
	srand(time(nullptr));
	MainClass::main();
	return 0;
}
