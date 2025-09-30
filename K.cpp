#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    string s;

    cin >> k >> s;

    int count = 1;
    int total = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) count++;
        else count = 1;
        
        if (count == k) {
            count = 1;

            if (k == 2) {
                continue;
            }

            total++;
            if (i + 1 < s.size() && s[i+1] == s[i]) {
                s[i] = s[i] == '0' ? '1' : '0';
            } else {
                s[i-1] = s[i-1] == '0' ? '1' : '0';
            }
        }
    }

    if (k == 2) {
        int err0 = 0, err1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                err0 += s[i] == '0' ? 0 : 1;
                err1 += s[i] == '1' ? 0 : 1;
            } else {
                err0 += s[i] == '1' ? 0 : 1;
                err1 += s[i] == '0' ? 0 : 1;
            }
        }

        total = min(err0, err1);

        for (int i = 0; i < s.size(); i++) {
            if (err0 < err1) {
                s[i] = i % 2 == 0 ? '0' : '1';
            } else {
                s[i] = i % 2 == 0 ? '1' : '0';
            }
        }
    }

    cout << total << ' ' << s << '\n';

    return 0;
}