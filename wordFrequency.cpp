#include "lib.h"
#include "std.h"
#include "wordFrequency.h"

void wordFrequency(string text, string foutput, int lineCount, string lineArray[50], string wordArray[50], string urls) {
	map<string, int> words;
	map<string, int>::iterator m;
	stringstream ss(text);
	string word;
	int counter{ 0 };
	int count{};
	int c{ 0 };

	while (ss >> word) {
		words[word]++;
		wordArray[counter] = word;

		counter++;
	}

	ofstream fout(foutput);

	for (m = words.begin(); m != words.end(); m++) {
		if (m->second > 1)
			fout << m->first << " = " << m->second << '\n';
	}

	fout << '\n';

	fout << setw(20) << left << "Words";

	for (int i = 0; i < lineCount; i++) {
		fout << left << setw(6);
		fout << i + 1;
	}
	fout << '\n';

	for (m = words.begin(); m != words.end(); m++) {
		if (m->second > 1) {
			fout << left << setw(20) << m->first;
			for (int i = 0; i < lineCount; i++) {
				for (int j = 0; j < counter; j++) {
					if ((lineArray[i].find(m->first + ' ') != std::string::npos) ||
						(lineArray[i].find(m->first + '.') != std::string::npos) ||
						(lineArray[i].find(m->first + ',') != std::string::npos) ||
						(lineArray[i].find(m->first + '"') != std::string::npos) ||
						(lineArray[i].find(m->first + "'") != std::string::npos) ||
						(lineArray[i].find(m->first + ')') != std::string::npos) ||
						(lineArray[i].find(m->first + ':') != std::string::npos)) {
						fout << left << setw(6) << "+";
						break;
					}
					else {
						fout << left << setw(6) << "-";
						break;
					}
				}
			}
			fout << '\n';
		}
		c += m->second;
	}

	fout << "\nWord Count: " << c << '\n';

	fout << "\nFound URL addresses:\n";
	fout << urls;

	fout.close();
}