#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    
    cin >> a >> b >> c;

    if (a + b + c == 3 || a + b + c == 0) {
        cout << "*\n";

        return 0;
    }

    if ((a == 0 && b == 0 && c == 1) || (a == 1 && b == 1 && c == 0)) {
        cout << "C\n";
    } else if ((a == 0 && b == 1 && c == 0) || (a == 1 && b == 0 && c == 1)) {
        cout << "B\n";
    } else {
        cout << "A\n";
    }

    return 0;
}