#include<bits/stdc++.h>

using namespace std;

#define MAXN 100000

int main() {
    int i, j, n, v[MAXN];
    vector<pair<int, int>> pairs;
    vector<pair<int, int>> pos_qtd;

    bool mark[MAXN + 1];
    memset(mark, false, sizeof(mark));

    cin >> n;

    int prev = 0, prev_i = 0, down = MAXN;
    for (i = 0; i < n; i++) {
        cin >> v[i];

        if (v[i] == 0) {
            continue;
        }

        mark[v[i]] = true;

        if ((i == 0 && v[i] == 0) || (i > 0 && v[i - 1] == 0)) {
            pairs.push_back(make_pair(prev, v[i]));
            pos_qtd.push_back(make_pair(prev_i, i - prev_i));

            if (down == MAXN && prev > v[i]) {
                down = pairs.size() - 1;
            }
        }

        prev = v[i];
        prev_i = i + 1;
    }

    if (v[n - 1] == 0) {
        pairs.push_back(make_pair(prev, 0));
        pos_qtd.push_back(make_pair(prev_i, n - prev_i));
    }

    vector<vector<int>> availables;

    for (i = 0; i < pairs.size(); i++) {
        vector<int> available;

        if (down == MAXN) {
            for (j = 1; j <= n; j++) {
                if (mark[j] == false) available.push_back(j);
            }
        } else {
            if (i < down) {
                for (j = pairs[i].first + 1; j <= pairs[i].second - 1; j++) {
                    if (mark[j] == false) available.push_back(j);
                }
            } else if (i > down) {
                for (j = pairs[i].second + 1; j <= pairs[i].first - 1; j++) {
                    if (mark[j] == false) available.push_back(j);
                }
            } else {
                for (j = min(pairs[i].first + 1, pairs[i].second + 1); j <= n; j++) {
                    if (mark[j] == false) available.push_back(j);
                }
            }
        }

        availables.push_back(available);

        cout << i << " ****** \n";

        for (j = 0; j < available.size(); j++) {
            cout << available[j] << " ";
        }

        cout << "\n";
    }


    cout << "-----------------\n";
    
    for (i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs[i].first << "," << pairs[i].second << ")\n";
    }

    cout << "-----------------\n";

    for (i = 0; i < pos_qtd.size(); i++) {
        cout << "(" << pos_qtd[i].first << "," << pos_qtd[i].second << ")\n";
    }

    cout << "-----------------\n";

    cout << down << "\n";


    return 0;
}