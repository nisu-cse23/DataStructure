#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
    // Stack to hold the result characters
    stack<char> st;
    
    // Frequency of characters in the string
    unordered_map<char, int> freq;
    
    // Record if the character is already in the stack
    unordered_map<char, bool> inStack;
    
    // Count the frequency of each character in the string
    for (char c : s) {
        freq[c]++;
    }
    
    for (char c : s) {
        // Decrease the frequency of the current character
        freq[c]--;
        
        // If the character is already in the stack, skip it
        if (inStack[c]) continue;
        
        // Remove characters from the stack if they are greater than the current character
        // and they appear later in the string (so we can add them later)
        while (!st.empty() && st.top() > c && freq[st.top()] > 0) {
            inStack[st.top()] = false;
            st.pop();
        }
        
        // Add the current character to the stack
        st.push(c);
        inStack[c] = true;
    }
    
    // Build the result from the stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

int main() {
    string s;
    
    // Take input from the user
    cout << "Enter the string: ";
    cin >> s;
    
    // Call the function and display the result
    cout << "Result after removing duplicates: " << removeDuplicateLetters(s) << endl;
    
    return 0;
}