#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    multiset<unsigned int> values;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x > 0) {
            values.insert(x);
        } else {
            auto it = values.find((abs(x)));
            values.erase(it);
        }

        for (int ele : values) {
            cout << ele << " ";
        }

        cout << "\n";
    }

    return 0;
}