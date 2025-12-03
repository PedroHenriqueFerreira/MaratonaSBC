#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    unsigned long long int num = 0;

    int places = min(10, (int) str.size());

    for (int i = 0; i < places; i++) {
        num += ((str[i] - '0') * pow(10, places - i - 1));
    }

    int n_primes = 100000000;
    vector<bool> primes(n_primes + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= n_primes; i++) {
        if (primes[i] == true) {
            for (int j = i * i; j <= n_primes; j += i) {
                primes[j] = false;
            }
        }
    }

    cout << "OK\n";

    // pair<int, int> ;
    // for (int i = 2; i < n_primes; i++) {
    //     if (primes[i] == false) continue;

    //     if (num == 1) break;

    //     int qtd = 0;
    //     while (num % i == 0) {
    //         num = num / i;
    //         qtd += 1;
    //     }

    //     if (qtd > 0) {
    //         cout << i << " " << qtd << "\n";
    //     }
    // }

    return 0;
}