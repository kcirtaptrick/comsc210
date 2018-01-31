#include <iostream>
#include <vector>

using namespace std;

vector<int> start, dest, temp;
void show_hanoi() {
    cout << "start: ";
    for(auto item:start) cout << item << " ";
    cout << " | dest: ";
    for(auto item:dest) cout << item << " ";
    cout << " | temp: ";
    for(auto item:temp) cout << item << " ";
    cout << endl;
}

void hanoi(int n, vector<int> &start, vector<int> &dest, vector<int> &temp) {
// the 3 hanoi disc stacks are modeled as vectors!

}

int main() {
    int height;
    cout << "Enter the height: ";
    cin >> height;
    
    for(int i=0; i<height; i++) // setup a test case
        start.push_back(height-i);
    show_hanoi();
    hanoi(height, start, dest, temp);
    
    cout << "\nProgram Exit!";
}