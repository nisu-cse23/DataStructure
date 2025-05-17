#include <iostream>
#include <vector>
using namespace std;

void printEvenIndices(const vector<int>& arr, int index) {
    if (index < 0) return; 
    if (index % 2 == 0) cout << arr[index] << " ";
    printEvenIndices(arr, index - 1); 
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter " << N << " numbers: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cout << "Numbers at even indices in reverse order: ";
    printEvenIndices(arr, N - 1);
    return 0;
}
