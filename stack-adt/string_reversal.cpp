// String reversal using stack
#include <iostream>
#include <stack> // stack from standard template library (STL)
#include <cstring> // for strlen
using namespace std;

// Function prototype
void reverse(char *C, int n);

int main() {
    char C[51];
    cout << "Enter a string: ";
    cin.getline(C, 51);
    reverse(C, strlen(C));
    cout << "Output = " << C << endl;
}

void reverse(char *C, int n) {
    stack<char> S;
    // Push all characters of string to stack
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    // Pop all characters from stack and put them back to string
    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}