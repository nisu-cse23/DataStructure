#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std; // Added using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2); // Using swap without std::
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    vector<string> commands = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<vector<int>> values = {{}, {1}, {2}, {}, {}, {}};
    vector<string> output;

    MyStack myStack;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "MyStack") {
            output.push_back("null");
        } else if (commands[i] == "push") {
            myStack.push(values[i][0]);
            output.push_back("null");
        } else if (commands[i] == "pop") {
            output.push_back(to_string(myStack.pop())); // Using to_string without std::
        } else if (commands[i] == "top") {
            output.push_back(to_string(myStack.top())); // Using to_string without std::
        } else if (commands[i] == "empty") {
            output.push_back(myStack.empty() ? "true" : "false");
        }
    }

    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}