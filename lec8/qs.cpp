#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    // Перемещает элементы из inputStack в outputStack, если outputStack пуст
    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {}

    // Добавляет элемент в конец очереди
    void push(int x) {
        inputStack.push(x);
    }

    // Удаляет элемент из начала очереди и возвращает его
    int pop() {
        transfer(); // Убедимся, что элементы находятся в outputStack
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }

    // Возвращает элемент из начала очереди без его удаления
    int peek() {
        transfer();
        return outputStack.top();
    }

    // Проверяет, пуста ли очередь
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    vector<string> commands = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<vector<int>> values = {{}, {1}, {2}, {}, {}, {}};
    vector<string> output;

    MyQueue myQueue;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "MyQueue") {
            output.push_back("null");
        } else if (commands[i] == "push") {
            myQueue.push(values[i][0]);
            output.push_back("null");
        } else if (commands[i] == "pop") {
            output.push_back(to_string(myQueue.pop()));
        } else if (commands[i] == "peek") {
            output.push_back(to_string(myQueue.peek()));
        } else if (commands[i] == "empty") {
            output.push_back(myQueue.empty() ? "true" : "false");
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
