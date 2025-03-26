#include <iostream>
#include <vector>
using namespace std;

/*
Why are we doing this?
→ To learn how to use iterators for element-wise traversal.
→ To write generic code using template functions and STL containers.
*/

// c) Template function to check for palindrome
template <typename T>
bool isPalindrome(const vector<T>& v) {
    typename vector<T>::const_iterator front = v.begin();
    typename vector<T>::const_iterator back = v.end();
    if (back != v.begin()) --back;

    while (front < back) {
        if (*front != *back)
            return false;
        ++front;
        --back;
    }
    return true;
}

int main() {
    // a) Integer palindrome test
    vector<int> v1 = {1, 2, 3, 2, 1};
    vector<int> v2 = {1, 2, 3, 4, 5};

    cout << "v1 is " << (isPalindrome(v1) ? "" : "not ") << "a palindrome." << endl;
    cout << "v2 is " << (isPalindrome(v2) ? "" : "not ") << "a palindrome." << endl;

    // b/c) String test
    vector<string> words = {"wow", "this", "wow"};
    cout << "words is " << (isPalindrome(words) ? "" : "not ") << "a palindrome." << endl;

    return 0;
}
