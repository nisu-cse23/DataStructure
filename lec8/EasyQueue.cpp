#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cout << "Enter the number of queries: ";
    cin >> T;//Read the number of queries

    queue<int> q;//Declare the queue
    
    for (int i = 0; i < T; ++i) {
        int query;
        cout << "Enter query " << i+1 << ": ";
        cin >> query;//Read the query type
        
        if (query == 1) {// Enqueue operation
            int  n;
            cout << "Enter number to enqueue: ";
            cin >> n;
            q.push(n);//Add the number to the queue
        }
        
        else if (query == 2) {// Dequeue operation

            if (!q.empty()) {
                q.pop();//Remove the front element from the queue
            } 
            else {
                cout << "Queue is empty, cannot dequeue." << endl;
            }
        } 
        else if (query == 3) {// Print operation

            if (q.empty()) {
                cout << "Empty!" << endl;//If the queue is empty, print "Empty!"
            } 
            else {
                cout<<"Frist element:" <<q.front() <<endl;
                 // Print the first element of the queue
            }
        } 
        else {
            cout << "Invalid query." << endl;
        }
    }

    return 0;
}