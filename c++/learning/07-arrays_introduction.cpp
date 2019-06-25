#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> ints = vector<int>();
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        ints.push_back(b);
    }

    for (int i = ints.size() - 1; i >= 0; i--) {
        cout << ints[i];
        if (i != 0) printf(" ");
    }
}
