#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> valores(n);

    int x;
    cin >> x;

    int count = 1;
    cout << count << " ";

    int parou = x;

    for (int i = 1; i < n; i++) {
        cin >> x;
        
        if (x > 0) {
            valores[i] = x;

            if (x > parou) {
                int se_nao_trocasse = count + 1;
                
                int se_trocasse = x + valores.size() - ;
            }

        } else {
            valores.erase(x * -1);
        }
    }

    return 0;
}