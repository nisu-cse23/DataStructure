#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack, outputStack;

    // Helper function to transfer elements from inputStack to outputStack
    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    // Push element x to the back of the queue.
    void push(int x) {
        inputStack.push(x);
    }
    
    // Removes the element from the front of the queue and returns it.
    int pop() {
        if (outputStack.empty()) {
            transfer();
        }
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }
    
    // Returns the element at the front of the queue.
    int peek() {
        if (outputStack.empty()) {
            transfer();
        }
        return outputStack.top();
    }
    
    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);          // queue is: [1]
    myQueue.push(2);          // queue is: [1, 2]
    
    cout << myQueue.peek() << endl;   // return 1
    cout << myQueue.pop() << endl;    // return 1, queue is [2]
    cout << myQueue.empty() << endl;  // return false

    return 0;
}
