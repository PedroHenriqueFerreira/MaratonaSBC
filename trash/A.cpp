#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;

    int i;
    for (i = s.size() - 1; i > 0; i--) {
        if (s[i] <= s[i - 1]) break;
    }

    cout << i << "\n";

    return 0;
}