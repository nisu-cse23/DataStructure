#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;  // Input the number of test cases

    while (T--) {
        int N;
        cout << "Enter number of elements in the queue: ";
        cin >> N;  // Input the number of elements in the queue
        
        queue<int> q;
        cout << "Enter the elements for the queue: ";
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;  // Enqueue elements into the queue
            q.push(x);
        }

        // Using a stack to reverse the queue
        stack<int> s;
        while (!q.empty()) {
            s.push(q.front());  // Pop from queue and push to stack
            q.pop();
        }

        // Now pop from stack and print the reversed order
        cout << "Reversed queue: ";
        while (!s.empty()) {
            cout << s.top() << " ";  // Print the reversed order
            s.pop();
        }
        cout << endl;
    }

    return 0;
}