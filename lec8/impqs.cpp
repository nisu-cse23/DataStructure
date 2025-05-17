
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;//Two stacks to simulate the queue

public:
    //Push element x to the back of the queue
    void push(int x) {
        s1.push(x);//Simply push the element onto the first stack
    }

    // Task1:Removes the element from the front of the queue and returns it
    int pop() {
        if (s2.empty()) {
            //Move elements from s1 to s2 if s2 is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            int front = s2.top();//The top of s2 is the front of the queue
            s2.pop();//Remove the element from the front
            return front;
        }
        return -1;//Return -1 if the queue is empty
    }

    //Task2:Get the front element
    int peek() {
        if (s2.empty()) {
            //Move elements from s1 to s2 if s2 is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            return s2.top();//The top of s2 is the front of the queue
        }
        return -1;//Return -1 if the queue is empty
    }

    //Return whether the queue is empty or not
    bool empty() {
        return s1.empty() && s2.empty();//The queue is empty if both stacks are empty
    }
};

int main() {
    MyQueue q;
    string operation;
    int x;

    // Task2:Reading multiple operations
    while (true) {
        cout << "Enter operation (push , pop, peek, empty, or exit): ";
        cin >> operation;
        
        if (operation == "push") {
            cin >> x;
            q.push(x);
            cout << "null" << endl;//Since push doesn't return anything, print "null"
        } 
        else if (operation == "pop") {
            int result = q.pop();
            if (result != -1) {
                cout << result << endl;//Output the popped element
            } else {
                cout << "null" << endl;//If the queue is empty, print "null"
            }
        }
        else if (operation == "peek") {
            int result = q.peek();
            if (result != -1) {
                cout << result << endl;//Output the front element
            } else {
                cout << "null" << endl;//If the queue is empty, print "null"
            }
        }
        else if (operation == "empty") {
            if (q.empty()) {
                cout << "true" << endl;//If the queue is empty, print "true"
            } else {
                cout << "false" << endl;//Otherwise print false
            }
        }
        else if (operation == "exit") {
            break;//Exit the loop and end the program
        }
        else {
            cout << "Invalid operation! Please try again." << endl;
        }
    }

    return 0;
}