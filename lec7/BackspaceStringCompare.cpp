#include <iostream>
#include <string>
using namespace std;

// Function to simulate backspacing
string applyBackspace(string str) {
    string result = "";
    for (char ch : str) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back();  // Remove the last character
            }
        } else {
            result += ch;  // Add the character to the result
        }
    }
    return result;
}

int main() {
    string s, t;
    
    // Take input from the user
    cout << "Enter the first string (s): ";
    cin >> s;
    
    cout << "Enter the second string (t): ";
    cin >> t;
    
    // Apply backspace operation on both strings
    string final_s = applyBackspace(s);
    string final_t = applyBackspace(t);
    
    // Compare the final strings and output the result
    if (final_s == final_t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}