#include<bits/stdc++.h>

#define MAXN 1000

using namespace std;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    int x, y, c;

    vector<int> o_graph[MAXN];
    pair<pair<int, int>, int> o_edge[MAXN];

    int i, j;
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

    // for (i = 0; i < m; i++) {
    //     for (j = 0; j < m; j++) {
    //         cout << graph[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    // ---------------------------------------------

    stack<pair<int, int>> pilha;
    pilha.push(make_pair(0, 0));

    int res[MAXN];

    pair<int, int> top;
    int depth, curr;
    bool found;

    int a, b, d, e, f, g, h, first, last;
    while (!pilha.empty()) {
        top = pilha.top();
        depth = top.first;
        curr = top.second;
        pilha.pop();

        // cout << "DESEMPILHANDO: " << curr << " | DEPTH: " << depth << "\n";

        res[depth++] = curr;

        if (depth != 1 && depth == m && graph[res[m - 1]][res[0]] == true) {
            a = o_edge[res[0]].first.first;
            b = o_edge[res[0]].first.second;
            c = o_edge[res[1]].first.first;
            d = o_edge[res[1]].first.second;

            first = (a == c || a == d) ? b : a;

            e = o_edge[res[m - 1]].first.first;
            f = o_edge[res[m - 1]].first.second;
            g = o_edge[res[m - 2]].first.first;
            h = o_edge[res[m - 2]].first.second;

            last = (e == g || e == h) ? f : e;

            if (first == last) {
                cout << first + 1 << "\n";
                
                for (i = 0; i < m - 1; i++) {
                    cout << res[i] + 1 << " ";
                }

                cout << res[m - 1] + 1 << "\n";
    
                return 0;
            }
        }

        for (i = 0; i < m; i++) {
            if (graph[curr][i] == false) continue;

            found = false;
            for (j = 0; j < depth; j++) {
                if (res[j] == i) {
                    found = true;
                    break;
                }
            }
            if (found) continue;

            if (depth > 1) { 
                a = o_edge[res[depth - 1]].first.first;
                b = o_edge[res[depth - 1]].first.second;
                c = o_edge[res[depth - 2]].first.first;
                d = o_edge[res[depth - 2]].first.second;

                e = o_edge[i].first.first;
                f = o_edge[i].first.second;

                last = (a == c || a == d) ? b : a;

                
            }

            // cout << "\tEMPILHANDO: " << i << " | DEPTH: " << depth << "\n";

            pilha.push(make_pair(depth, i));
        }
    }

    cout << "-1\n";

    return 0;
}