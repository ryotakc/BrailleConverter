/*
Title: Cpp Assignment
Description: Convert the sentence to braille characters, search and save the word to the dictionary file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


const int ROWS = 3; // Rows
const int COLS = 54; // Columns

// Function prototypes
string getUserInput();
bool isWordInDictionary(const vector<string>& dictionary, const string& word);
void addWordToDictionary(vector<string>& dictionary, const string& word);
void saveDictionaryToFile(const string& filename, const vector<string>& dictionary);
vector<string> readDictionaryFromFile(const string& filename);
vector<string> extractWordsFromSentence(const string& sentence, int, int);
void printBraille(char c);


// Braille array 
char Braille[ROWS][COLS] = {
    { 'o', '.',   'o', '.',   'o', 'o',   'o', 'o',   'o', '.',   'o', 'o',   'o', 'o',   'o', '.',   '.', 'o',   '.', 'o',   'o', '.',   'o', '.',   'o','o',  'o', 'o',   'o', '.',   'o', 'o',   'o', 'o',   'o', '.',   '.', 'o',   '.', 'o',   'o', '.',   'o', '.',   '.', 'o',   'o', 'o',   'o', 'o',   'o', '.',   '.', '.',}, // Row 1
    { '.', '.',   'o', '.',   '.', '.',   '.', 'o',   '.', 'o',   'o', '.',   'o', 'o',   'o', 'o',   'o', '.',   'o', 'o',   '.', '.',   'o', '.',   '.','.',  '.', 'o',   '.', 'o',   'o', '.',   'o', 'o',   'o', 'o',   'o', '.',   'o', 'o',   '.', '.',   'o', '.',   'o', 'o',   '.', '.',   '.', 'o',   '.', 'o',   '.', '.',}, //　Row 2
    { '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   '.', '.',   'o', '.',   'o', '.',   'o','.',  'o', '.',   'o', '.',   'o', '.',   'o', '.',   'o', '.',   'o', '.',   'o', '.',   'o', 'o',   'o', 'o',   '.', 'o',   'o', 'o',   'o', 'o',   'o', 'o',   '.', '.',}  // Row 3
};



int main() {

    char option;
    string sentence;
    do {
        sentence = getUserInput();

        // pickup words
        vector<string> words = extractWordsFromSentence(sentence, 4, 6);

        // read dictionary from file
        vector<string> dictionary = readDictionaryFromFile("dictionary.txt");

        // add words to dictionary vector
        for (const auto& word : words) {
            if (!isWordInDictionary(dictionary, word)) {
                addWordToDictionary(dictionary, word);
                saveDictionaryToFile("dictionary.txt", dictionary);
            }
        }


        cout << "Convert the sentence to Braille character" << endl;
        // print Braille
        for (int i = 0; i < sentence.length(); i++) {
            printBraille(sentence[i]);
        }

        cout << endl;
        cout << "Would you like to play again Y/y for yes and N/n for no?" << endl;
        cin >> option;
        cin.ignore();
    } while (option == 'y' || option == 'Y');
    return 0;
}



// input user sentence 
string getUserInput() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    return sentence;
}



// read dictionary vector from dictionary file
vector<string> readDictionaryFromFile(const string& filename)
{
    vector<string> dictionary;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            dictionary.push_back(line);
        }
        inFile.close();
    }
    return dictionary;
}



// save dictionary vector to file
void saveDictionaryToFile(const string& filename, const vector<string>& dictionary)
{
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& word : dictionary) {
            outFile << word << endl;
        }
        outFile.close();
    }
}



//Convert the word to Braille
void printBraille(char c) {
    int index = 0;
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        index = c - 'A';
        for (int i = 0; i < ROWS; i++) {
            for (int j = index * 2; j < (index + 1) * 2; j++) {
                cout << Braille[i][j];
            }
            cout << endl;

        }
        cout << "------" << endl;
    }
    else if (c == ' ') { // space
        for (int i = 0; i < ROWS; i++) {
            //cout << ".." << endl;
            cout << Braille[i][COLS - 2] << Braille[i][COLS - 1] << endl;
        }
        cout << "------" << endl;
    }
}




// check the word that is included in the dictionary vector
bool isWordInDictionary(const vector<string>& dictionary, const string& word)
{
    for (const auto& dictWord : dictionary) {
        if (dictWord == word) {
            return true;
        }
    }
    return false;
}



// add word to dictionary
void addWordToDictionary(vector<string>& dictionary, const string& word)
{
    dictionary.push_back(word);
}






// extract words from sentence
vector<string> extractWordsFromSentence(const string& sentence, int minLen, int maxLen) {
    vector<string> words;
    string word;
    for (const auto& c : sentence) {
        if (c == ' ' || c == ',' || c == '.') {
            if (word.length() >= minLen && word.length() <= maxLen) {
                words.push_back(word);
            }
            word.clear();
        }
        else {
            word += c;
        }
    }

    // check the last word 
    if (word.length() >= minLen && word.length() <= maxLen) {
        words.push_back(word);
    }

    return words;
}
