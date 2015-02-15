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
	Roulette(long long currentNumberOfSpins) {
		setNumberOfSpins(currentNumberOfSpins);

	}

	void spin(bool calculateAndPrintStatistics) {
		spin(getNumberOfSpins(), calculateAndPrintStatistics);
	}

	void spin(long long currentNumberOfSpins, bool calculateAndPrintStatistics) {
		statistics = vector<long long>();
		printStartingInfo(currentNumberOfSpins);
		long long biggestSequence = getBiggestSequence(currentNumberOfSpins, calculateAndPrintStatistics);
		printSpinResultInfo(biggestSequence);
	}

	long long getNumberOfSpins() {
		return numberOfSpins;
	}

	void setNumberOfSpins(long long currentNumberOfSpins) {
		numberOfSpins = currentNumberOfSpins;
	}

	vector<long long> getStatistics() {
		return statistics;
	}

private:
	long long getBiggestSequence(long long currentNumberOfSpins, bool calculateAndPrintStatistics) {
		if (calculateAndPrintStatistics) {
			return setSequencesAndGetTheBiggest(currentNumberOfSpins);
		} else {
			return getBiggestSequence(currentNumberOfSpins);
		}
	}

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
		long long biggestSequence = 0;
		long long currentSequence = 0;

		SectorColor previousColor = getRandomColor();
		SectorColor currentColor;

		for (long long i = 0; i < currentNumberOfSpins; ++i) {
			currentColor = getRandomColor();
			currentSequence = calculateCurrentSequence(currentColor, previousColor, currentSequence);
			biggestSequence = max(biggestSequence, currentSequence);
			previousColor = currentColor;
		}

		return biggestSequence;
	}

	long long setSequencesAndGetTheBiggest(long long currentNumberOfSpins) {
		setSequences(currentNumberOfSpins);
		return statistics.size();
	}

	void setSequences(long long currentNumberOfSpins) {
		long long* x = new long long(0);
		SectorColor previousColor = getRandomColor();
		SectorColor currentColor;
		long long currentSequence = 0;

		for (long long i = 0; i < currentNumberOfSpins; ++i) {
			if (currentSequence == 15) {
//				system("pause");
			}

			currentColor = getRandomColor(x);

			if (currentSequence == 15) {
//				cout << previousColor << " " << currentColor << " " << *x << endl;
			}

			currentSequence = calculateCurrentSequence(currentColor, previousColor, currentSequence);
			syncSequence(currentSequence);
			previousColor = currentColor;
		}
	}

	SectorColor getRandomColor(long long* x = nullptr) {
		long long randomNumber = rand();

		if (x != nullptr) {
			*x = randomNumber;
		}

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

	void syncSequence(size_t currentSequence) {
		if (currentSequence > statistics.size()) {
			statistics.push_back(1);
		} else {
			statistics[currentSequence - 1] += 1;
		}
	}

	long long numberOfSpins;

	vector<long long> statistics;

	string STARTING_INFO_FORMAT = "Spinned %I64d times.\n";

	string RESULT_INFO_FORMAT = "The biggest sequence was %I64d.\n\n";

	string ARRAY_PRINT_FORMAT = "%I32d:\t%I64d\n";
};
