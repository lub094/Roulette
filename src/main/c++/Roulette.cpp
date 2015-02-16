/*
 * Roulette.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Lubo
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>

#include "SectorColor.cpp"

using namespace std;

class Roulette {
public:
	void spin(long long currentNumberOfSpins) {
		statistics = vector<long long>();
		long long biggestSequence = getBiggestSequence(currentNumberOfSpins);
		printStartingInfo(currentNumberOfSpins);
		printSpinResultInfo(biggestSequence);
	}

	vector<long long> getStatistics() {
		return statistics;
	}

private:
	void printSpinResultInfo(long long biggestSequence) {
		printf(RESULT_INFO_FORMAT.c_str(), biggestSequence);
		for (size_t i = 0; i < statistics.size(); ++i) {
			printf(ARRAY_PRINT_FORMAT.c_str(), i + 1, statistics[i]);
		}
		printf("\n");
	}

	void printStartingInfo(long long currentNumberOfSpins) {
		printf(STARTING_INFO_FORMAT.c_str(), currentNumberOfSpins);
	}

	long long getBiggestSequence(long long currentNumberOfSpins) {
		setSequences(currentNumberOfSpins);
		return statistics.size();
	}

	void setSequences(long long currentNumberOfSpins) {
		SectorColor previousColor = getRandomColor();
		SectorColor currentColor;
		long long currentSequence = 0;

		for (long long i = 0; i < currentNumberOfSpins; ++i) {
			currentColor = getRandomColor();
			currentSequence = calculateCurrentSequence(currentColor, previousColor, currentSequence);
			syncSequence(currentSequence);
			previousColor = currentColor;
		}
	}

	SectorColor getRandomColor() {
		long long randomNumber = rand();
		if (randomNumber % 2 == 0) {
			return SectorColor::BLACK;
		} else {
			return SectorColor::RED;
		}
	}

	long long calculateCurrentSequence(SectorColor currentColor, SectorColor previousColor, long long currentSequence) {
		if (currentColor == previousColor) {
			currentSequence++;
		} else {
			currentSequence = 1;
		}

		return currentSequence;
	}

	void syncSequence(long long currentSequence) {
		if (currentSequence > statistics.size()) {
			statistics.push_back(1);
		} else {
			statistics[currentSequence - 1] += 1;
		}
	}

	vector<long long> statistics;

	string STARTING_INFO_FORMAT = "Spinned %I64d times.\n";

	string RESULT_INFO_FORMAT = "The biggest sequence was %I64d.\n\n";

	string ARRAY_PRINT_FORMAT = "%I32d:\t%I64d\n";
};
