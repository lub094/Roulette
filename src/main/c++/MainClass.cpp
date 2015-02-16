/*
 * MainClass.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Lubo
 */

#include <iostream>
#include "Roulette.cpp"

int main() {
	srand(time(nullptr));

	Roulette roulette;
	roulette.spin(10000000);

	return 0;
}
