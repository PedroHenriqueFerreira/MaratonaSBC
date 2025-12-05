#include <bits/stdc++.h>
#define N 99999

using namespace std;

vector<int> primes;
vector<bool> is_prime(N + 1, true);

void load_primes() {
    is_prime[0] = false;
    is_prime[1] = false;

    primes.push_back(2);
    primes.push_back(5);
    primes.push_back(3);

    int i;
    for (i = 3; i * i <= N; i += 2) {
        if (i % 5 == 0) continue;

        if (is_prime[i] == true) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }

            if (i != 3) {
                primes.push_back(i);
            }
        }
    }

    for (int j = i; j < N; j += 2) {
        if (i % 5 != 0 && is_prime[j]) {
            primes.push_back(j);
        }
    }
}

void factorization(unsigned long long int value, int size) {
    vector<pair<int, int>> res;
    int qtd;
    int ct = 0;
    for (int prime : primes) {
        if (value < prime || value == 1) break;

        qtd = 0;
        while (value % prime == 0) {
            value /= prime;
            qtd++;
        }
        if (qtd > 0) {
            ct += 1;
            res.push_back(make_pair(prime, qtd));
        }
    }

    if (value != 1) {
        res.push_back(make_pair(value, 1));
        ct++;
    }

    if (size > 10) {
        size -= 10;
        if (res[0].first == 2) {
            res[0].second += size;
        } else {
            res.push_back(make_pair(2, size));
            ct += 1;
        }
        if (res[0].first == 5) {
            res[0].second += size;
        } else if (res.size() >= 2 && res[1].first == 5) {
            res[1].second += size;
        } else {
            res.push_back(make_pair(5, size));
            ct += 1;
        }
    }

    cout << ct << "\n";
    
    for (pair<int, int> par : res) {
        cout << par.first << " " << par.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    load_primes();

    unsigned long long int num = 0;

    int places = min(10, (int) str.size());

    for (int i = 0; i < places; i++) {
        num += ((str[i] - '0') * pow(10, places - i - 1));
    }

    if (str.size() < 10) {
        factorization(num, str.size()); 
    } else {
        int error = str[0] - '0';
        int last = str[9] - '0';

        if (error == 1) {
            if (last % 2 == 0) factorization(num, str.size());
            else factorization(num + 1, str.size());
        } else if (error == 2) {
            if (last % 2 == 0) {
                if (num % 4 == 0) factorization(num, str.size());
                else factorization(num + 2, str.size());
            } else {
                if ((num + 1) % 4 == 0) factorization(num + 1, str.size());
                else factorization(num - 1, str.size());
            }
        } else {
            if (last == 0 || last == 5) factorization(num, str.size());
            else {
                int dist_0 = 0 - last;
                int dist_5 = 5 - last;
                int dist_10 = 10 - last;

                if (abs(dist_0) < min(abs(dist_5), abs(dist_10))) factorization(num + dist_0, str.size());
                else if (abs(dist_5) < abs(dist_10)) factorization(num + dist_5, str.size());
                else factorization(num + dist_10, str.size());
            }
        }
    } 

    return 0;
}