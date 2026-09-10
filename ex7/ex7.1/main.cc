#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

/*
Why are we doing this?
→ To learn how to use STL maps for counting.
→ We associate each word with its frequency using map<string, int>.

b) Explain what does 'myMap[word] += 1' do?

- 'myMap' is a 'std::map<std::string, int>', so it associates a word (key) with a count (value).
- When we access 'myMap[word]', the map automatically inserts the key if it doesn't exist yet and sets its value to 0.
- Then '+= 1' increments the count.

So:
- The first time we see a word, 'myMap[word]' creates an entry with value 0, then adds 1 → count becomes 1.
- Every subsequent time, it retrieves the existing count and increments it.

*/

int main() {
    ifstream infile("example.txt");  // use any .txt file

    if (!infile) {
        cout << "Could not open file." << endl;
        return 1;
    }

    map<string, int> wordMap;
    string word;

    while (infile >> word) {
        wordMap[word] += 1;  // count occurrences
    }

    cout << "Word Frequency Catalogue:\n";
    for (auto it = wordMap.begin(); it != wordMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
