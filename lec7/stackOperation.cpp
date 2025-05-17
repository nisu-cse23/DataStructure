#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Create an empty stack
    stack<int> s;

    // Add new items
    s.push(10);
    s.push(20);
    s.push(30);

    // Check if the stack is empty
    if (s.empty()) {
        cout << "The stack is empty.\n";
    } else {
        cout << "The stack is not empty.\n";
    }

    // Retrieve the top item
     cout << "Top item: " << s.top() << "\n";  // 30

    // Remove the top item
    s.pop();  // Removes 30

    // Retrieve the new top item
    cout << "New top item: " << s.top() << "\n";  // 20

    // Destroy the stack by resetting it
    s = stack<int>();  // Now the stack is empty

    return 0;
}
