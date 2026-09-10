#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

/*
Why are we doing this?
→ To replicate the behaviour of the Unix 'wc' tool and practise working with file input,
   line-by-line reading, character counting, and word parsing using stringstreams.
*/

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./wordcount <filename>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    if (!infile) {
        cout << "Error: could not open file " << argv[1] << endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    const int BUFLEN = 2048;
    char buffer[BUFLEN];

    while (infile.getline(buffer, BUFLEN)) {
        ++lineCount;
        charCount += strlen(buffer);
        charCount++; // for newline

        istringstream line(buffer);
        char word[BUFLEN];
        while (line >> word) {
            ++wordCount;
        }
    }

    infile.close();

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}
