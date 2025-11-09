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
    for (i = 0; i < m; i++) { // O(m)
        cin >> x >> y >> c;

        x--;
        y--;

        o_graph[x].push_back(i);
        o_graph[y].push_back(i);

        o_edge[i] = make_pair(make_pair(x, y), c);
    }

    for (i = 0; i < n; i++) {
        if (o_graph[i].size() % 2 != 0) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> graph[2 * MAXN];
    pair<int, int> uv;

    for (i = 0; i < m; i++) {
        uv = o_edge[i].first;
        c = o_edge[i].second;

        for (auto item : o_graph[uv.first]) {
            if (o_edge[item].second != c) {
                if (o_edge[item].first.first == uv.first) {
                    graph[i + m].push_back(item);
                } else {
                    graph[i + m].push_back(item + m);
                }
            }
        }

        for (auto item : o_graph[uv.second]) {
            if (o_edge[item].second != c) {
                if (o_edge[item].first.first == uv.second) {
                    graph[i].push_back(item);
                } else {
                    graph[i].push_back(item + m);
                }
            }
        }
    }
    
    stack<pair<int, int>> pilha;
    pilha.push(make_pair(0, 0));

    int res[MAXN];

    pair<int, int> top;
    int depth, curr;

    int a, b, d, e;

    bool visited[MAXN];
    memset(visited, false, sizeof(visited));

    while (!pilha.empty()) {
        top = pilha.top();
        depth = top.first;
        curr = top.second;
        pilha.pop();

        res[depth++] = curr;

        if (depth > 1 && depth == m) {
            a = res[m - 1] < m ? o_edge[res[m - 1]].first.first : o_edge[res[m - 1] - m].first.second;
            b = res[m - 1] < m ? o_edge[res[m - 1]].first.second : o_edge[res[m - 1] - m].first.first;
            d = res[0] < m ? o_edge[res[0]].first.first : o_edge[res[0] - m].first.second;
            e = res[0] < m ? o_edge[res[0]].first.second : o_edge[res[0] - m].first.first;
            
            if (b == d && o_edge[res[0] % m].second != o_edge[res[m - 1] % m].second) {
                cout << o_edge[res[0]].first.first + 1 << '\n';
                
                for (i = 0; i < m - 1; i++) {   
                    cout << (res[i] % m) + 1 << " ";
                }

                cout << (res[m - 1] % m) + 1 << "\n";

                return 0;
            }
        }
    
        memset(visited, false, sizeof(visited));   
        for (i = 0; i < depth; i++) {
            visited[res[i] % m] = true;
        }

        for (auto item : graph[curr]) {
            if(visited[item % m] == false) {
                pilha.push(make_pair(depth, item));
            }
        }
    }

    cout << "-1\n";

    return 0;
}