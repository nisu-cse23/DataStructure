#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;  // Create an empty stack

    // Push elements onto the stack
    stack.push(10);  
    stack.push(20);  
    stack.push(30);  

    // Pop the top item
    stack.pop();  // Removes 30

    // Check if the stack is empty
    if (stack.empty()) {
        cout << "The stack is empty.\n";
    } else {
        cout << "The stack is not empty.\n";
    }

    // Check if the stack is full (based on a manual size limit)
    const int MAX_SIZE = 5;
    if (stack.size() >= MAX_SIZE) {
        cout << "The stack is full.\n";
    } else {
        cout << "There is space in the stack.\n";
    }

    // Retrieve the top item
    cout << "Top item: " << stack.top() << endl;  // Output: 20

    return 0;
}
