/*
 * MainClass.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Lubo
 */

#include <iostream>
#include "Roulette.cpp"
#include <random>

int main() {
	srand(time(nullptr));

	Roulette roulette;
	roulette.spin(10000);

	return 0;
}
