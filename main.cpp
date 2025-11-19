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

    pair<int, int> norte;
    pair<int, int> sul;
    pair<int, int> esq;
    pair<int, int> dir;
    bool has_norte = false;
    bool has_sul = false;
    bool has_esq = false;
    bool has_dir = false;

    pair<int, int> prox;
    bool has_prox = false;

    int prox_dist = 0;

    pair<int, int> par;
    for (int i = 0; i < n; i++) {
        par = pares[i];

        int norte_dist = no - par.second;
        int esq_dist = par.first - es;
        int sul_dist = par.second - su;
        int dir_dist = di - par.first;

        if (no == par.second) {
            if (!has_norte) {
                has_norte = true;
                norte = par;
            } else if (min(esq_dist, dir_dist) < min(abs(norte.first-es), abs(norte.first-di))) {
                norte = par;
            }
        }

        if (su == par.second) {
            if (!has_sul) {
                has_sul = true;
                sul = par;
            } else if (min(sul_dist, dir_dist) < min(abs(sul.first-es), abs(sul.first-di))) {
                sul = par;
            }
        }

        if (es == par.first) {
            if (!has_esq) {
                has_esq = true;
                esq = par;
            } else if (min(norte_dist, sul_dist) < min(abs(esq.second-no), abs(esq.second-su))) {
                esq = par;
            }
        }

        if (di == par.first) {
            if (!has_dir) {
                has_dir = true;
                dir = par;
            } else if (min(norte_dist, sul_dist) < min(abs(dir.second-no), abs(dir.second-su))) {
                dir = par;
            }
        }

        int curr_dist = max(max(norte_dist, sul_dist), max(esq_dist, dir_dist));

        if (!has_prox) {
            has_prox = true;
            prox = par;

            prox_dist = curr_dist;
        } else if (prox_dist > curr_dist) {
            prox = par;
            prox_dist = curr_dist;
        } else if (prox_dist == curr_dist) {
            if (largura < altura) {
                if (min(abs(par.first - es), abs(par.first - di)) < min(abs(prox.first - es), abs(prox.first - di))) {
                    prox = par;
                }
            } else {
                if (min(abs(par.second - no), abs(par.second - su)) < min(abs(prox.second - no), abs(prox.second - su))) {
                    prox = par;
                }
            }
        }
    }

    if (dir == norte || dir == sul || esq == norte || esq == sul || norte == sul || esq == dir) {
        largura += k;
        altura += k;

        cout << largura * altura << "\n";

        return 0;
    } 

    int norte_dist = min(abs(norte.first - es), abs(norte.first - di));
    int sul_dist = min(abs(sul.first - es), abs(sul.first - di));
    int esq_dist = min(abs(esq.second - no), abs(esq.second - su));
    int dir_dist = min(abs(dir.second - no), abs(dir.second - su));

    if (min(min(min(norte_dist, sul_dist), min(esq_dist, dir_dist)), prox_dist) >= k) {
        for (int i = 0; i < k; i++) {
            if (largura > altura) {
                altura++;
            } else {
                largura++;
            }
        }

        cout << largura * altura << "\n";

        return 0;
    }

    long long int largura_1 = largura, altura_1 = altura;
    
    int norte_sul = min(norte_dist, sul_dist);
    int esq_dir = min(esq_dist, dir_dist);

    if (norte_sul < esq_dir) {
        altura_1 += norte_sul;
        altura_1 += k - norte_sul;
        largura_1 += k - norte_sul;
    } else if (norte_sul > esq_dir) {
        largura_1 += esq_dir;
        largura_1 += k - esq_dir;
        altura_1 += k - esq_dir;
    } else {
        if (largura_1 < altura_1) {
            largura_1 += esq_dir;
            largura_1 += k - esq_dir;
            altura_1 += k - esq_dir;
        } else {
            altura_1 += norte_sul;
            altura_1 += k - norte_sul;
            largura_1 += k - norte_sul;
        }
    }

    long long int largura_2 = largura, altura_2 = altura;

    for (int i = 0; i < k; i++) {
        if (largura_2 > altura_2) {
            altura_2++;
        } else {
            largura_2++;
        }
    }

    long long int largura_3 = largura, altura_3 = altura;

    if (prox == norte || prox == sul || prox == esq || prox == dir) {
        norte_dist = no - prox.second;
        esq_dist = prox.first - es;
        sul_dist = prox.second - su;
        dir_dist = di - prox.first;

        norte_sul = min(norte_dist, sul_dist);
        esq_dir = min(esq_dist, dir_dist);

        k = k - min(norte_sul, esq_dir);

        if (norte_sul < esq_dir) {
            esq_dir -= norte_sul;
            norte_sul = 0;
        } else {
            norte_sul -= esq_dir;
            esq_dir = 0;
        }

        if (norte_sul < esq_dir) {
            altura_3 += norte_sul;
            altura_3 += k - norte_sul;
            largura_3 += k - norte_sul;
        } else if (norte_sul > esq_dir) {
            largura_3 += esq_dir;
            largura_3 += k - esq_dir;
            altura_3 += k - esq_dir;
        } else {
            if (largura_3 < altura_3) {
                largura_3 += esq_dir;
                largura_3 += k - esq_dir;
                altura_3 += k - esq_dir;
            } else {
                altura_3 += norte_sul;
                altura_3 += k - norte_sul;
                largura_3 += k - norte_sul;
            }
        }
    }

    long long int res = max(largura_1 * altura_1, max(largura_2 * altura_2, largura_3 * altura_3));

    cout << res << "\n";

    return 0;
}