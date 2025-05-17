#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if an array is a palindrome
bool isPalindrome(const vector<int>& arr, int start, int end) {
    // Base case: if start index is greater than or equal to end, it's a palindrome
    if (start >= end)
        return true;
    
    // If the elements at the current start and end are different, it's not a palindrome
    if (arr[start] != arr[end])
        return false;
    
    // Recurse for the next pair of elements
    return isPalindrome(arr, start + 1, end - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;  // Input size of the array
    
    vector<int> arr(n);
    
    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Check if the array is a palindrome
    if (isPalindrome(arr, 0, n - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}