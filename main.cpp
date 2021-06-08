#include "lib.h"
#include "std.h"
#include "urlChecker.h"
#include "wordFrequency.h"

int main()
{

	cout << "Buffering...\n";

	stringstream ss2;
	string line;
	string lineArray[1000];
	string wordArray[10000];
	string urlArray[100];
	string wholeText;
	string bufferedText;
	string word;
	string urls;
	int lineCount{ 0 };
	int counter{ 0 };
	int count{};

	ifstream fin("text.txt");
	ofstream fout("output.txt");

	while (!fin.eof()) {
		getline(fin, line);
		lineArray[lineCount] = line;
		lineCount++;
		ss2 << line;
		wholeText += line + '\n';
	}

	stringstream ssUrl(wholeText);

	while (ssUrl >> word) {
		wordArray[counter] = word;

		if (urlChecker(word)) {
			urlArray[counter] = word;
			urls += urlArray[counter] + '\n';
		}
	}

	remove_copy_if(wholeText.begin(), wholeText.end(), std::back_inserter(bufferedText), std::ptr_fun<int, int>(&std::ispunct));

	wordFrequency(bufferedText, "output.txt", lineCount, lineArray, wordArray, urls);

	fin.close();
	fout.close();

	cout << "The given text in 'text.txt' has been buffered. Check the 'output.txt' file for results\n";

	return 0;
}