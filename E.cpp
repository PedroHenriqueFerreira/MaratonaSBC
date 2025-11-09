#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r;

    cin >> n >> r;

    bool res[n];
    memset(res, false, sizeof(res));

    int returned;
    for (int i = 0; i < r; i++) {
        cin >> returned;

        res[returned - 1] = true;
    }
    
    bool any = false;

    for (int i = 0; i < n; i++) {
        if (res[i]) continue;

        any = true;

        cout << i + 1 << " ";
    }
    

    if (!any) {
        cout << "*\n";
    } else {
        cout << "\n";
    }

    return 0;
}