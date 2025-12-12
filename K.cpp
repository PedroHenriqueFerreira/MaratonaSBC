#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    if (n == 1) {
        int x, y;
        cin >> x >> y;
        cout << 1 << "\n";
        return 0;
    }
    
    vector<pair<int, int>> pares(n);
    cin >> pares[0].first >> pares[0].second;

    int no = pares[0].second;
    int di = pares[0].first;
    int su = pares[0].second;
    int es = pares[0].first;

    for (int i = 1; i < n; i++) {
        cin >> pares[i].first >> pares[i].second;

        no = max(no, pares[i].second);
        su = min(su, pares[i].second);
        es = min(es, pares[i].first);
        di = max(di, pares[i].first);
    }

    long long int largura = di - es + 1, altura = no - su + 1;
    long long int max_largura = largura, max_altura = altura;
    long long int curr_largura, curr_altura;
    int curr_k;

    pair<int, int> par;
    for (int i = 0; i < n; i++) {
        par = pares[i];

        int norte_dist = no - par.second;
        int esq_dist = par.first - es;
        int sul_dist = par.second - su;
        int dir_dist = di - par.first;

        int min_esq_dir_dist = min(esq_dist, dir_dist);
        int min_nor_sul_dist = min(norte_dist, sul_dist);

        curr_k = k - min(k, min(min_esq_dir_dist, min_nor_sul_dist));

        curr_largura = largura;
        curr_altura = altura;

        int diff = min(curr_k, abs(min_nor_sul_dist - min_esq_dir_dist)); 

        if (min_esq_dir_dist < min_nor_sul_dist) curr_largura += diff;
        else curr_altura += diff;

        curr_k -= diff;

        curr_largura += curr_k;
        curr_altura += curr_k;

        if (curr_largura * curr_altura > max_largura * max_altura) {
            max_altura = curr_altura;
            max_largura = curr_largura;
        }
    }

    curr_largura = largura;
    curr_altura = altura;

    for (int i = 0; i < k; i++) {
        if (curr_largura < curr_altura) {
            curr_largura++;
        } else {
            curr_altura++;
        }
    }

    if (curr_largura * curr_altura > max_largura * max_altura) {
        max_altura = curr_altura;
        max_largura = curr_largura;
    }

    cout << max_largura * max_altura << "\n";

    return 0;
}