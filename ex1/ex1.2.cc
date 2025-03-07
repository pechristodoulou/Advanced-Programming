#include <iostream>
using namespace std;

int main() {
    int len = 100;
    char str[len];
    // const char* word = "yessir";
    // cout << word << endl;
    cout << "Please give a word: ";
    cin.getline(str, len); // Read input up to newline or length
    // cout << typeid(str).name() << endl;
    char* letter = &str[0];

    // Counting the different types in word
    int n_upper = 0, n_lower = 0;
    int n_digits = 0, n_other = 0;
    do {
        // cout << "Letter: " << *letter << endl; # check letter
        
        if (*letter >= 'A' && *letter <= 'Z') {
            n_upper++;
        } else if (*letter >= 'a' && *letter <= 'z') {
            n_lower++;
        } else if (*letter >= '0' && *letter <= '9') {
            n_digits++;
        } else {
            n_other += 1;
        }

        letter++;
        
    } while (*letter != '\0');

    cout << "Number of lowercase characters: " << n_lower << endl
         << "Number of uppercase characters: " << n_upper << endl
         << "Number of digits: " << n_digits << endl
         << "Number of other characters: " << n_other << endl;
        
    // return 0;
}