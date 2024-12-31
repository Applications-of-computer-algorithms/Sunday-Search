// SUNDAY ALGORITHM
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

ofstream out;

// Function to read the entire content of a file into a string
string readInputText(const string& filePath) {
    ifstream input(filePath);
    stringstream sstream;

    if (!input.is_open()) {
        return string();        // Return an empty string if the file cannot be opened
    }

    sstream << input.rdbuf();   // Read the file content into a string stream
    return sstream.str();       // Return the content as a string
}

// Function to output the contents of the BCH array to the output file
void outputBCH(const vector<int>& BCH) {
    for (int i = 0; i < BCH.size(); i++) {
        out << BCH[i] << ' ';
    }
    out << endl;
}

// Implementation of the Sunday string search algorithm
void sunday(const string& text, const string& pattern) {
    int patternLength = pattern.length();
    vector<int> BCH(240, patternLength + 1);    // Initialize BCH table with default values

    // Populate the BCH table based on the pattern
    for (int i = 0; i < patternLength; i++) {
        BCH[pattern[i]] = patternLength - i;
    }
    cout << "BCH array successfully created!" << endl;
    outputBCH(BCH); // Output the BCH table to the output file

    string comparisonString;
    int index = 0;
    int j = 0;
    int i = 0;

    // Perform the search
    while ((j + pattern.length()) < text.length()) {
        if (pattern[i] == text[j + i]) {
            if (i == 0) {
                index = j;                          // Store the index where the pattern starts matching
            }
            comparisonString += text[j + i];        // Build the comparison string
            i++;

            if (comparisonString == pattern) { 
                out << index << ' ';                // Output the starting index of the match
                comparisonString = "";              // Reset the comparison string
                i = 0;
                j += patternLength;                 // Move the search window by the pattern length
            }
        }
        else {
            j += BCH[text[j + patternLength - i]];  // Use the BCH table for the jump
            i = 0;
            comparisonString = "";                  // Reset the comparison string
        }
    }
}

int main(int argc, const char* const argv[]) {
    if (argc != 3) {
        cout << "Incorrect number of parameters! You need to pass: <pattern> <input_file>" << endl;
        return -1; 
    }

    string text = readInputText(argv[2]);   // Read the text file
    string pattern = argv[1];               // Pattern to search for
    out.open("out.txt");                    // Open the output file

    if (!out) {
        cout << "The output file cannot be opened." << endl;
        return -2; // Return error if the output file cannot be opened
    }

    sunday(text, pattern); // Perform the Sunday search
    cout << "Sunday search completed! Results are in file 'out.txt'" << endl;
    return 0;
}