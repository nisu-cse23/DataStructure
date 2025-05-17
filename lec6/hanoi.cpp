
#include <iostream>
using namespace std;

// Task1:Recursive function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    
    // Move n-1 disks to the auxiliary rod
    hanoi(n - 1, from, aux, to);
    
    // Move the remaining disk to the target rod
    cout << from << " " << to << endl;
    
    // Move the n-1 disks from the auxiliary rod to the target rod
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    
    // Take input from the user
    cout << "Enter the number of disks: ";
    cin >> n;
    
    // Output the minimum number of moves: 2^n - 1
    cout << (1 << n) - 1 << endl; // (1 << n) is the same as 2^n
    
    // Start the recursive disk movement
    hanoi(n, 1, 3, 2);
    
    return 0;
}
