#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <algorithm>
using namespace std;
double computeAverageWordLength(istream& inputStream) {
	string word;
	int totalLength = 0;
	int wordCount = 0;


	while (inputStream >> word) {
		
		totalLength += word.length();
		wordCount++;
	}
	if (wordCount == 0) {
		return 0.0;
	}
	else {
		return static_cast<double>(totalLength) / wordCount;
	}
}
int main() {
	ifstream inputFile("input.txt");
	if (!inputFile) {
		cerr << "error opening i file" << endl;
		return 1;
	}
		cout << "The average word length is " << computeAverageWordLength(inputFile) << endl;
		inputFile.close();
		return 0;
	}