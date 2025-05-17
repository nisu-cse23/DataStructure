#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets (power set)
void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    // Add the current subset to the list of all subsets
    allSubsets.push_back(currentSubset);
    
    // Explore further subsets by adding elements one by one
    for (int i = index; i < nums.size(); i++) {
        currentSubset.push_back(nums[i]); // Include the element
        generateSubsets(nums, i + 1, currentSubset, allSubsets); // Recurse for the next element
        currentSubset.pop_back(); // Backtrack, remove the last element
    }
}

int main() {
    int n;
    
    // Input the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    
    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<vector<int>> allSubsets;
    vector<int> currentSubset;
    
    // Generate all subsets
    generateSubsets(nums, 0, currentSubset, allSubsets);
    
    // Output all subsets with comma formatting
    cout << "The subsets are:" << endl;
    for (size_t i = 0; i < allSubsets.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < allSubsets[i].size(); ++j) {
            cout << allSubsets[i][j];
            if (j != allSubsets[i].size() - 1) {
                cout << ", ";  // Add comma between elements in the subset
            }
        }
        cout << "]";
        
        // Print a comma after each subset except the last one
        if (i != allSubsets.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}