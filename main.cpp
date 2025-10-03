#include<bits/stdc++.h>

#define MAXN 1000

using namespace std;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    int x, y, c;

    vector<int> o_graph[MAXN];
    pair<pair<int, int>, int> o_edge[MAXN];

    int i;
    for (i = 0; i < m; i++) {
        cin >> x >> y >> c;

        x--;
        y--;

        o_graph[x].push_back(i);
        o_graph[y].push_back(i);

        o_edge[i] = make_pair(make_pair(x, y), c);
    }

    bool graph[MAXN][MAXN];
    memset(graph, false, sizeof(graph));

    for (i = 0; i < m; i++) {
        pair<int, int> vertices = o_edge[i].first;
        int color = o_edge[i].second;

        for (auto item : o_graph[vertices.first]) {
            if (o_edge[item].second != color) {
                graph[i][item] = true;
            }
        }

        for (auto item : o_graph[vertices.second]) {
            if (o_edge[item].second != color) {
                graph[i][item] = true;
            }
        }
    }

    // ---------------------------------------------

    int j;
    // for (i = 0; i < m; i++) {
    //     for (j = 0; j < m; j++) {
    //         cout << graph[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    // cout << "PROCURANDO... \n";

    stack<pair<int, int>> pilha;
    pilha.push(make_pair(0, 0));

    int res[MAXN];

    pair<int, int> top;
    int depth, curr;
    bool found;

    while (!pilha.empty()) {
        top = pilha.top();
        depth = top.first;
        curr = top.second;
        pilha.pop();

        // cout << "DESEMPILHANDO: " << curr << " | DEPTH: " << depth << "\n";

        res[depth++] = curr;

        if (depth == m && graph[res[m - 1], 0]) {
            if (m == 1) {
                cout << o_edge[0].first.first + 1 << "\n";
            } else {
                int u = o_edge[0].first.first;
                int v = o_edge[0].first.second;
                int w = o_edge[1].first.first;
                int x = o_edge[1].first.second;

                if (u == w || u == x) {
                    cout << v + 1 << "\n";
                } else {
                    cout << u + 1 << "\n";
                }
            }

            for (i = 0; i < m - 1; i++) {
                cout << res[i] + 1 << " ";
            }

            cout << res[m - 1] + 1 << "\n";
 
            break;
        }

        for (i = 0; i < m; i++) {
            if (!graph[curr][i]) continue;

            found = false;
            for (j = 0; j < depth; j++) {
                if (res[j] == i) found = true;
            }
            
            if (found) continue;

            // cout << "\tEMPILHANDO: " << i << " | DEPTH: " << depth << "\n";

            pilha.push(make_pair(depth, i));
        }
    }

    if (depth != m) {
        cout << "-1\n";
    }

    return 0;
}