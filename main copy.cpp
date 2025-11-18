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

    pair<int, int> norte;
    pair<int, int> sul;
    pair<int, int> esq;
    pair<int, int> dir;

    bool has_norte = false;
    bool has_sul = false;
    bool has_esq = false;
    bool has_dir = false;

    bool norte_dir = false;
    bool sul_dir = false;
    bool esq_norte = false;
    bool dir_norte = false;

    int norte_pontos = 0;
    int sul_pontos = 0;
    int esq_pontos = 0;
    int dir_pontos = 0;

    pair<int, int> par;
    for (int i = 0; i < n; i++) {
        par = pares[i];

        if (no == par.second) {
            if (!has_norte) {
                has_norte = true;

                norte = par;

                if (abs(par.first - es) < abs(par.first - di)) {
                    norte_dir = false;
                } else {
                    norte_dir = true;
                }

                norte_pontos = min(abs(par.first - es), abs(par.first - di));

            } else if (min(abs(par.first - es), abs(par.first - di)) < min(abs(norte.first - es), abs(norte.first - di))) {
                norte = par;

                if (abs(par.first - es) < abs(par.first - di)) {
                    norte_dir = false;
                } else {
                    norte_dir = true;
                }

                norte_pontos = min(abs(par.first - es), abs(par.first - di));
            }
        }

        if (su == par.second) {
            if (!has_sul) {
                has_sul = true;
                sul = par;

                if (abs(par.first - es) < abs(par.first - di)) {
                    sul_dir = false;
                } else {
                    sul_dir = true;
                }

                sul_pontos = min(abs(par.first - es), abs(par.first - di));

            } else if (min(abs(par.first - es), abs(par.first - di)) < min(abs(sul.first - es), abs(sul.first - di))) {
                sul = par;

                if (abs(par.first - es) < abs(par.first - di)) {
                    sul_dir = false;
                } else {
                    sul_dir = true;
                }

                sul_pontos = min(abs(par.first - es), abs(par.first - di));
            }
        }

        if (es == par.first) {
            if (!has_esq) {
                has_esq = true;
                esq = par;

                if (abs(par.second - no) < abs(par.second - su)) {
                    esq_norte = true;
                } else {
                    esq_norte = false;
                }

                esq_pontos = min(abs(par.second - no), abs(par.second - su));

            } else if (min(abs(par.second - no), abs(par.second - su)) < min(abs(esq.second - no), abs(esq.second - su))) {
                esq = par;

                if (abs(par.second - no) < abs(par.second - su)) {
                    esq_norte = true;
                } else {
                    esq_norte = false;
                }

                esq_pontos = min(abs(par.second - no), abs(par.second - su));
            }
        }

        if (di == par.first) {
            if (!has_dir) {
                has_dir = true;

                dir = par;

                if (abs(par.second - no) < abs(par.second - su)) {
                    dir_norte = true;
                } else {
                    dir_norte = false;
                }

                dir_pontos = min(abs(par.second - no), abs(par.second - su));

            } else if (min(abs(par.second - no), abs(par.second - su)) < min(abs(dir.second - no), abs(dir.second - su))) {
                dir = par;
                
                if (abs(par.second - no) < abs(par.second - su)) {
                    dir_norte = true;
                } else {
                    dir_norte = false;
                }

                dir_pontos = min(abs(par.second - no), abs(par.second - su));
            }
        }
    }

    long long int largura = dir.first - esq.first + 1, altura = norte.second - sul.second + 1;

    if (dir == norte || dir == sul || esq == norte || esq == sul || norte == sul || esq == dir) {
        largura += k;
        altura += k;

        cout << largura * altura << "\n";

        return 0;
    }

    if (min(min(norte_pontos, sul_pontos), min(esq_pontos, dir_pontos)) >= k) {
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

    if (min(norte_pontos, sul_pontos) < min(esq_pontos, dir_pontos)) {
        altura += min(norte_pontos, sul_pontos);
        altura += k - min(norte_pontos, sul_pontos);
        largura += k - min(norte_pontos, sul_pontos);
    } else if (min(norte_pontos, sul_pontos) > min(esq_pontos, dir_pontos)) {
        largura += min(esq_pontos, dir_pontos);
        largura += k - min(esq_pontos, dir_pontos);
        altura += k - min(esq_pontos, dir_pontos);
    } else {
        if (largura < altura) {
            largura += min(esq_pontos, dir_pontos);
            largura += k - min(esq_pontos, dir_pontos);
            altura += k - min(esq_pontos, dir_pontos);
        } else {
            altura += min(norte_pontos, sul_pontos);
            altura += k - min(norte_pontos, sul_pontos);
            largura += k - min(norte_pontos, sul_pontos);
        }
    }

    cout << largura * altura << "\n";

    return 0;
}