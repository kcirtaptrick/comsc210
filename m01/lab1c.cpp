#include <string>
#include <iostream>
using namespace std;

void reverse(string input, int size) {
    if(size!=-1) {
        cout << input[size];
        reverse(input, size-1);
    }
    // while(size!=-1) {
    //     cout << input[size];
    //     size--;
    // }
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int size = input.size();
    cout << "\nThe reversed is ";
    
    reverse(input, size);
    // while(size!=-1) {
    //     cout << input[size];
    //     size--;
    // }
}