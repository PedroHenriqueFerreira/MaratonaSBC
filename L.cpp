#include<bits/stdc++.h>

#define NMAX 500
#define INF 500000

using namespace std;

int main() {
    int n, t, i, j;

    cin >> n >> t;

    int matrix[NMAX][NMAX];

    int temp;
    for (i = 0; i < n; i++) {
        temp = i + 1;

        for (j = 0; j < n; j++) {
            matrix[i][j] = temp;

            if (temp == n) {
                temp = 1;
            } else {
                temp++;
            }
        }
    }
    
    cout << "-----------------------------\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << matrix[i][n - 1] << "\n";
    }

    char x;
    int a, b;
    for (i = 0; i < t; i++) {
        cin >> x >> a >> b;

        a--;
        b--;

        for (j = 0; j < n; j++) {
            if (x == 'R') {
                temp = matrix[a][j];
                matrix[a][j] = matrix[b][j];
                matrix[b][j] = temp;
            } else {
                temp = matrix[j][a];
                matrix[j][a] = matrix[j][b];
                matrix[j][b] = temp;
            }
        }
    }

    cout << "--------------\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << matrix[i][n - 1] << "\n";
    }

    int x_pos;
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp = matrix[i][j] - 1;
            x_pos = temp / n;

            matrix[x_pos][temp % n] = matrix[i][j];
        }
    }

    bool error = false;
    set<int> group1, group2;

    int min_v = INF, max_v = -INF;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            group1.insert(matrix[i][j]);
            group2.insert(matrix[j][i]);

            min_v = min(min_v, matrix[i][j]);
            max_v = max(max_v, matrix[i][j]);
        }

        if (group1.size() != n || group2.size() != n) {
            error = true;
            break;
        }
        
        group1.clear();
        group2.clear();
    }

    if (error) {
        cout << "*\n";

        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            cout << matrix[i][j] - min_v + 1 << " ";
        }

        cout << matrix[i][n - 1] - min_v + 1 << "\n";
    }

    return 0;
}