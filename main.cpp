#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;

    int total_n = 0, total_m = 0;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total_n += v[i];
    } 

    cin >> m;
    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
        total_m += w[i];
    }

    if (total_n != total_m) {
        cout << "N\n";
        return 0;
    }

    if (m == 1) {
        if (total_n == w[0]) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }

        return 0;
    } else if (n == m) {
        bool is_equal = true, is_reverse = true;

        for (int i = 0; i < n; i ++) {
            if (v[i] != w[i]) is_equal = false;
            if (v[i] != w[n - i - 1]) is_reverse = false;
        }

        if (is_equal || is_reverse) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }

        return 0;
    }

    cout << "OLA MUNDO\n";

    return 0;
}