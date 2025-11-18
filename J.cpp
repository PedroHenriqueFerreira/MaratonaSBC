#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    int score = 0;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == 'a' && str[i - 1] == 'h') {
            score += 1;
        }
    }

    for (int i = 4; i < str.size(); i++) {
        if (str[i] == 'o' && str[i - 1] == 'o' && str[i - 2] == 'o' && str[i - 3] == 'o' && str[i - 4] == 'b') {
            score -= 1;
        }
    }

    for (int i = 4; i < str.size(); i++) {
        if (str[i] == 'o' && str[i - 1] == 'v' && str[i - 2] == 'a' && str[i - 3] == 'r' && str[i - 4] == 'b') {
            score += 3;
        }
    }

    cout << score << "\n";

    return 0;
}