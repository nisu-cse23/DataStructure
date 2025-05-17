#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream> // For stringstream to split input
#include <cstdlib> // For atoi()

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    
    for (const string& token : tokens) {
        if (token == "+" ||  token == "-" || token == "*" || token == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            
            if (token == "+") {
                stk.push(a + b);
            } else if (token == "-") {
                stk.push(a - b);
            } else if (token == "*") {
                stk.push(a * b);
            } else if (token == "/") {
                stk.push(a / b);
            }
        } else {
            stk.push(atoi(token.c_str())); // Convert string to integer and push to stack
        }
    }
    
    return stk.top(); // The result will be the only element left in the stack
}

int main() {
    string input;
    vector<string> tokens;
    
    cout << "Enter the Reverse Polish Notation tokens (separate with spaces):" << endl;
    getline(cin, input);  // Read the whole line of input
    
    stringstream ss(input);
    string token;
    
    // Split the input string by spaces and push each token into the vector
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    cout << "Result: " << evalRPN(tokens) << endl;  // Output the result
    return 0;
}