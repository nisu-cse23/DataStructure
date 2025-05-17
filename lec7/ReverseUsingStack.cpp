#include <iostream>
#include <stack>
using namespace std;

// Function to reverse the string using stack
string reverse(string s) {
    stack<char> st;
    
    // Push all characters of the string to the stack
    for (char c : s) {
        st.push(c);
    }

    // Pop characters from the stack and build the reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string s;
    
    // Take input from the user
    cout << "Enter the string to reverse: ";
    cin >> s;
    
    // Call the reverse function and display the result
    cout << "Reversed string: " << reverse(s) << endl;

    return 0;
}