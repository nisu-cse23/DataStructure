#include <iostream>
using namespace std;

// Function to print "I love Recursion" N times using recursion
void printRecursion(int N) {
    // Base case: when N reaches 0, stop recursion
    if (N == 0) {
        return;
    }
    // Print the message
    cout << "I love Recursion" << endl;
    // Recur with N-1
    printRecursion(N - 1);
}

int main() {
    int N;
    
    // Take input from the user
    cout << "Enter the number N (how many times to print the message): ";
    cin >> N;
    
    // Call the recursive function
    printRecursion(N);
    
    return 0;
}