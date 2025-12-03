#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n_primes = 999999999;
    vector<bool> primes(n_primes + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (long long int i = 4; i <= n_primes; i += 2) {
        primes[i] = false;
    }

    cout << "int primes[] = { 2, ";

    for (long long int i = 3; i * i <= n_primes; i += 2) {
        if (primes[i] == true) {
            for (int j = i * i; j <= n_primes; j += i) {
                primes[j] = false;
            }

            cout << i << ", ";
        }
    }

    cout << "};\n";

    return 0;
}