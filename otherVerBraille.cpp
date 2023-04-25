#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <cctype>

using namespace std;

const int ROWS = 3; // 縦列
const int COLS = 2; // 横列

struct BrailleData {
    char chr;
    char braille[ROWS][COLS];
};

// Braille array
static const BrailleData brailleTable[] = {
	{
		'A',
		'o', '.',
		'.', '.',
		'.', '.',
	},
	{
		'B',
		'o', '.',
		'o', '.',
		'.', '.',
	},
	{
		'C',
		'o', 'o',
		'.', '.',
		'.', '.',
	},
	{
		'D',
		'o', 'o',
		'.', 'o',
		'.', '.',
	},
	{
		'E',
		'o', '.',
		'.', 'o',
		'.', '.',
	},
	{
		'F',
		'o', 'o',
		'o', '.',
		'.', '.',
	},
	{
		'G',
		'o', 'o',
		'o', 'o',
		'.', '.',
	},
	{
		'H',
		'o', '.',
		'o', 'o',
		'.', '.',
	},
	{
		'I',
		'.', 'o',
		'o', '.',
		'.', '.',
	},
	{
		'J',
		'.', 'o',
		'o', 'o',
		'.', '.',
	},
	{
		'K',
		'o', '.',
		'.', '.',
		'o', '.',
	},
	{
		'L',
		'o', '.',
		'o', '.',
		'o', '.',
	},
	{
		'M',
		'o', 'o',
		'.', '.',
		'o', '.',
	},
	{
		'N',
		'o', 'o',
		'.', 'o',
		'o', '.',
	},
	{
		'O',
		'o', '.',
		'.', 'o',
		'o', '.',
	},
	{
		'P',
		'o', 'o',
		'o', '.',
		'o', '.',
	},
	{
		'Q',
		'o', 'o',
		'o', 'o',
		'o', '.',
	},
	{
		'R',
		'o', '.',
		'o', 'o',
		'o', '.',
	},
	{
		'S',
		'.', 'o',
		'o', '.',
		'o', '.',
	},
	{
		'T',
		'.', 'o',
		'o', 'o',
		'o', '.',
	},
	{
		'U',
		'o', '.',
		'.', '.',
		'o', 'o',
	},
	{
		'V',
		'o', '.',
		'o', '.',
		'o', 'o',
	},
	{
		'W',
		'.', 'o',
		'o', 'o',
		'.', 'o',
	},
	{
		'X',
		'o', 'o',
		'.', '.',
		'o', 'o',
	},
	{
		'Y',
		'o', 'o',
		'.', 'o',
		'o', 'o',
	},
	{
		'Z',
		'o', '.',
		'.', 'o',
		'o', 'o',
	},
	{
		' ',
		'.', '.',
		'.', '.',
		'.', '.',
	},
};




void printBraille(char c) {
    for (const BrailleData& b: brailleTable) {
        if (b.chr == toupper(c)) {
            for (int i = 0; i < ROWS; i++) {
                printf("%.*s\n", COLS, b.braille[i]);
            }
            printf("------\n");
            break;
        }
    }
}


string getUserInput() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);  // getlineによる文章の入力
    return sentence;
}

int main() {
    string sentence = getUserInput();
    for (int i = 0; i < sentence.length(); i++) {
            printBraille(sentence[i]);
        }

    return 0;
}
