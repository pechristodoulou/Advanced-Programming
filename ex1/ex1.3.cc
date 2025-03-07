#include <iostream>
#include <string.h>  // for strlen()

using namespace std;
/*
d) We need to use the new[] operator because the functions join
and joinb need to create a string that persists after the function
ends. If it was a local array it would be destroyed and if it was
a string literal it would be immutable.

e) Yes we must allocate space for the null terminator since
it is required to mark the end of the string although it is
implicitly put after a string.

g) The caller (main function) is responsible for delete[] 
to avoid memory leaks.You must not delete[] the memory inside join()!
If you do, you will return a pointer to deallocated memory, causing undefined behavior.
*/
// Routines that concatenate 2 strings
char* join(const char* str1, const char* str2) {
    // const char* conc_word;
    int len1, len2;

    len1 = strlen(str1);
    len2 = strlen(str2);

    char* conc_word = new char[len1 + len2 + 1]; // +1 for 0 end of string
    conc_word[0] = '\0';
    conc_word = strcpy(conc_word, str1);
    // conc_word = str1;  // cant do that because one is const
    conc_word = strcat(conc_word, str2);

    return conc_word;
}; 

// Same function almost but adds space in between words
char* joinb(const char* str1, const char* str2) {  
    int len1, len2;

    len1 = strlen(str1);
    len2 = strlen(str2);

    char* conc_word = new char[len1 + len2 + 1]; // +1 for 0 end of string
    conc_word[0] = '\0';
    conc_word = strcpy(conc_word, str1);
    conc_word = strcat(conc_word, " ");  // no other mods required
    conc_word = strcat(conc_word, str2);

    return conc_word;
}; 


int main() {
    char* result;
    result = join("alpha", "bet");
    cout << result << endl;
    result = joinb("duck", "soup");
    cout << result << endl; 
    delete[] result;

    return 0;
}

