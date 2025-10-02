#include <bits/stdc++.h>

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

    int graph[MAXN][MAXN];
    memset(graph, 0, sizeof(graph));

    int item;
    for (i = 0; i < m; i++) {
        pair<int, int> vertices = o_edge[i].first;
        int color = o_edge[i].second;

        for (int item : o_graph[vertices.first]) {
            if (o_edge[item].second != color) {
                graph[i][item] = 1;
            }
        }

        for (int item : o_graph[vertices.second]) {
            if (o_edge[item].second != color) {
                graph[i][item] = 1;
            }
        }
    }

    // ---------------------------------------------

    int came[m];
    memset(came, -1, sizeof(came));

    stack<int> stack;
    stack.push(0);

    int neighbor;

    vector<int> res;
o
    bool ignore = true;
    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();

        if (!ignore && top == 0) {
            int parent = came[top];

            while(parent != 0) {
                parent = came[parent];

                res.push_back(parent + 1);
            }

            break;
        }

        ignore = false;

        for (i = 0; i < m; i++) {
            if (came[i] >= 0 || !graph[top][i]) continue;

            came[i] = top;

            stack.push(i);
        }
    }

    for (i = 0; i < (res.size() - 1); i++) {
        cout << res[i] << " ";
    }

    cout << res[res.size() - 1] << "\n";

    cout << "SEM ERROS\n";


    return 0;
}