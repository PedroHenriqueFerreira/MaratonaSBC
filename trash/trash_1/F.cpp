#include<bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    char res[n];

    cin >> k >> n;

    float p = (float) n / k;

    if (p > 3 || p < 1 || (p < 2 && (n % k) != k - 1)) {
        cout << "*\n"; 
        return 0;
    }

    if (p < 2 || abs(p - 2) < 1e-9) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << "X";
            } else {
                cout << "-";
            }
        }
        cout << "\n";
        return 0;
    }

    if (p > 2 && floor(n / k) == k) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << "-";
            } else {
                cout << "X";
            }
        }
        cout << "\n";
        return 0;
    }

    if (abs(p - 3) < 1e-9) {
        for (int i = 0; i < ceil(n / 3); i++) {
            cout << "-X-";
        }
        cout << "\n";
        return 0;
    }

    int resto = n % k;
    int pares = k - resto;
 
    for (int i = 0; i < pares; i++) {
        cout << "X-";
    }

    for (int i = 0; i < resto; i++) {
       cout << "-X-"; 
    }

    cout << "\n";

    return 0;
}