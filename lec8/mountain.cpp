#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of mountain peaks: ";
    cin >> n;//Input the number of mountain peaks
    
    vector<int> heights(n);//Vector to store the heights of the peaks
    cout << "Enter the heights of the peaks: ";

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];//Input the heights
    }
    
    vector<int> result(n, -1);//Initialize the result array with -1 (default is no higher peak)
    stack<int> s;//Stack to help track the next greater peak
    
    //Task1: Traverse the peaks from right to left
    for (int i = n - 1; i >= 0; --i) {

        // While there are elements in the stack and the top of the stack is less than or equal to the current height
        while (!s.empty() && heights[s.top()] <= heights[i]) {
            s.pop();  // Pop the elements that are not useful
        }
        
        // If the stack is not empty, the top element is the index of the next higher peak
        if (!s.empty()) {
            result[i] = heights[s.top()];//Store the next greater element
        }
        
        // Push the current index to the stack
        s.push(i);
    }
    
    // Task2:The final result
    cout << "Next greater peaks for each mountain: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";// Print the next higher peak or -1 if not found
    }
    cout << endl;
    
    return 0;
}