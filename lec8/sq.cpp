#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    // Push element x onto stack.
    void push(int x) {
        // Always push onto q2
        q2.push(x);
        
        // Push all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }
    
    // Removes the element on the top of the stack and returns it.
    int pop() {
        if (!q1.empty()) {
            int topElement = q1.front();
            q1.pop();
            return topElement;
        }
        throw runtime_error("Stack is empty");
    }
    
    // Get the top element.
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        throw runtime_error("Stack is empty");
    }
    
    // Returns true if the stack is empty, false otherwise.
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);          // stack is: [1]
    myStack.push(2);          // stack is: [2, 1]
    
    cout << myStack.top() << endl;   // return 2
    cout << myStack.pop() << endl;    // return 2, stack is [1]
    cout << myStack.empty() << endl;  // return false

    return 0;
}