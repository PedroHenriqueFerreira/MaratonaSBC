#include<bits/stdc++.h>

using namespace std;

#define MAXN 100000

int main() {
    int n, v[MAXN];
    vector<int> stations;
    bool mark[MAXN + 1];

    cin >> n;

    for (int i = 0; i <= n; i++) mark[i] = false;

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (v[i] != 0) {
            mark[v[i]] = true;
            stations.push_back(v[i]);
        }
    }

    int current = 0;

    while (v[current] == 0) {
        

        current++;
    }

    for (int i = 0; i < n; i++) {

    }

    return 0;
}