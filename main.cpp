#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int list[n];

    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> list[i];

        total += list[i];
    }

    if (total % 3 != 0) {
        cout << "0\n";
        return 0;
    }

    int size = total / 3;

    int list_acc[n];

    unordered_map<int, int> hash;

    list_acc[0] = list[0];
    hash[list[0]] = 0;

    for (int i = 1; i < n; i++) {
        list_acc[i] = list_acc[i - 1] + list[i];
        hash[list_acc[i]] = i;
    } 

    int buscando;

    unordered_map<int, bool> finaliza;

    int triangulos = 0;

    for (int i = 0; i < n; i++) {
        if (list_acc[i] >= size) {
            buscando = list_acc[i] - size;

            if (buscando == 0) {
                
            } else {
                if (hash.count(buscando) != 0) {
                    if (finaliza.count(hash[buscando]) != 0 && finaliza[hash[buscando]] == true) {
                        triangulos += 1;
                    }

                    finaliza[i] = true;
                }
            }
        }
    }

    cout << triangulos << "\n";

    return 0;
}