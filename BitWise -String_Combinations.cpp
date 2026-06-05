//To Generate All Combinations of a String 
#include <iostream>
using namespace std;

void solve(string s) {
    int L = s.length();

    for (int ctr = 1; ctr < (1 << L); ctr++) {
        string subseq = "";
        for (int sh = 0; sh < L; sh++) {
            if (ctr & (1 << sh)) {
                subseq += s[sh];
            }
        }
        cout << subseq << endl;
    }
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}