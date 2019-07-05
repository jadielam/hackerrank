#include <vector>
#include <iostream>
using namespace std;

int main() {

    long n;
    long q;
    cin >> n;
    cin >> q;
    vector<vector<long> > lines = vector<vector<long> >();
    
    for (long i = 0; i < n; ++i) {
        long k;
        cin >> k;
        vector<long> line_entries = vector<long>();
        for (long j = 0; j < k; j++) {
            long a;
            cin >> a;
            line_entries.push_back(a);
        } 
        lines.push_back(line_entries);
    }

    for (long c = 0; c < q; ++c) {
        long i;
        long j;
        cin >> i;
        cin >> j;
        printf("%d\n", lines[i][j]);
    }
}
