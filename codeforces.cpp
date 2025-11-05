
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    int len = n.size();
    int binval = 0;

    for(char c:n){
        binval = (binval << 1) + (c == '7');
    }
    int pos = (1 << len) - 1 + binval;
    cout << pos << endl;
    return 0;
}