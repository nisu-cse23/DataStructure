#include <iostream>
#include <vector>
using namespace std;

// Function to find the safe position using Josephus problem
int josephus(int n, int k) {
    // Base case: If there is only one person, they are the survivor
    if (n == 1)
        return 0;
    
    // Recursively find the safe position for n-1 persons and adjust for the current step
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    
    // Take input from user
    cout << "Enter the number of persons (n): ";
    cin >> n;
    cout << "Enter the value of k (number of persons skipped): ";
    cin >> k;
    
    // Find the safe position and adjust the result as it is 0-based in the function
    int safePosition = josephus(n, k) + 1; // +1 to convert to 1-based indexing
    
    // Output the safe position
    cout << "The safe position is: " << safePosition << endl;
    
    return 0;
}