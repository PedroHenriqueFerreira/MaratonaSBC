#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int x;
    int max = 0;

    cin >> x;
    max = x;
    
    int res = 1;

    for (int i = 1; i < n; i++) {
        cin >> x;

        if (x > max) {
            res++;
            max = x;
        } else {

        }
    }
    
    cout << res;



    return 0;
}