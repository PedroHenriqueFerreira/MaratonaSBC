#include<bits/stdc++.h>

#define INF 300000000.0
#define PI 3.14159265358979323846

using namespace std;

double deg_to_rad(int deg) {
    return deg * (PI / 180.0);
}

int main() {
    int teta, n;

    cin >> teta >> n;

    double cos_teta = cos(deg_to_rad(teta)), sin_teta = sin(deg_to_rad(teta));

    int x, h;
    double y;

    vector<pair<int, double>> pairs;

    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        y = (cos_teta * h / sin_teta) + x;

        pairs.push_back(make_pair(x, y));
    }

    sort(pairs.begin(), pairs.end());

    int x_min;
    double x_max, total = 0;

    x_min = pairs[0].first;
    x_max = pairs[0].second;

    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i].first <= pairs[i - 1].second) {
            x_max = max(pairs[i].second, pairs[i - 1].second);
            pairs[i].second = x_max;
        } else {
            total += x_max - x_min;

            x_min = pairs[i].first;
            x_max = pairs[i].second;
        }
    }
    
    total += x_max - x_min;

    cout << setprecision(16) << total << "\n";

    return 0;
}