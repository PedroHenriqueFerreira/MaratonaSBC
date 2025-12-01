#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    int num = 0;

    int places = min(10, (int) str.size());

    for (int i = 0; i < places; i++) {
        num += (str[i] - '0') * pow(10, places - i - 1);
    }

    cout << num;

    return 0;
}