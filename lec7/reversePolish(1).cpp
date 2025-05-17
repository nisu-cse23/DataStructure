#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib> // For atoi()

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    
    for (const string& token : tokens) {
        if (token == "+"  ||token == "-" ||  token == "*" || token == "/") {
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
    vector<string> tokens;
    string token;
    
    cout << "Enter the Reverse Polish Notation tokens (separate with spaces, type 'end' to stop):" << endl;
    while (true) {
        cin >> token;
        if (token == "end") {
            break;
        }
        tokens.push_back(token);
    }
    
    cout << "Result: " << evalRPN(tokens) << endl;
    return 0;
}