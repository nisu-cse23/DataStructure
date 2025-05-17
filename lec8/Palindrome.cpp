
#include <iostream>
#include <cctype>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {
    stack<char> s;
    queue<char> q;
    char ch;
    char stlem, qltem;
    int mismatches = 0;

    
    cout << "Enter string: " << endl;

    while (cin.peek() != '\n') {
        cin >> ch;
        if (isalpha(ch)) {
            s.push(toupper(ch));
            q.push(toupper(ch));
        }
    }

    while (!q.empty() && !s.empty()) {
        stlem = s.top();
        s.pop();

        qltem = q.front();
        q.pop();

        if (stlem != qltem) {
            ++mismatches;
        }
    }
    if (mismatches == 0) {
        cout << "That is a palindrome" << endl;
    } else {
        cout << "That is not a palindrome" << endl;
    }

    return 0;
}
