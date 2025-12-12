#include <bits/stdc++.h>

using namespace std;

long long int n, k;
  
int brute(long long int curr, long long int div) {
    if (curr % div != 0) return 0;
    if (div == 1 || curr == div) return 1;
    
    long long int ori = curr;

    div -= 1;

    long long int prev_curr = curr;

    if (curr % div == 0) {
        curr -= div;
    } else {
        curr -= curr % div;
    }  

    long long int res = 0;

    for (long long int i = curr; i >= 1; i -= div) {
        if (prev_curr - i > k) break;

        res += brute(i, div);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (n == 1) {
        cout << k << "\n";

        return 0;
    }

    /*
    int decimals = (k - 1) / 3;
    int rest = (k - 1) % 3;

    int units;

    if (rest == 0) {
        units = 1;
    } else if (rest == 1) {
        units = 2;
    } else {
        units = 5;
    }

    int res = units * pow(10, decimals);

    cout << res << "\n";
    */

    long long int total = 0, current;
    for (int i = 1; i < k; i++) {
        current = brute(n * i, n);

        cout << n * i << " | " << n << " | " << current << "\n";

        total += current;
    }

    total += 1;

    cout << total << "\n";


    return 0;
}