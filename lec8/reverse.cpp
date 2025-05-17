#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue
void reverseQueue(queue<int>& q) {
    if (q.empty()) {
        return;
    }
    
    // Get the front element and remove it from the queue
    int frontElement = q.front();
    q.pop();
    
    // Reverse the remaining queue recursively
    reverseQueue(q);
    
    // Push the front element to the back of the queue
    q.push(frontElement);
}

int main() {
    queue<int> q;
    
    // Ask user for number of elements
    int N;
    cout << "Enter the number of elements in the queue: ";
    cin >> N;
    
    // Add elements to the queue
    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    // Reverse the queue
    reverseQueue(q);
    
    // Print the reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}