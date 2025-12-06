/*
Author: kashsuks
*/

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    vector<pair<ll, ll>> ranges;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) break;

        size_t dashPos = line.find('-');
        if (dashPos == string::npos) continue;

        ll start = stoll(line.substr(0, dashPos));
        ll end = stoll(line.substr(dashPos + 1));

        ranges.push_back({start, end});
    }

    if (ranges.empty()) {
        cout << 0 << endl;
        return;
    }

    sort(all(ranges));

    ll total = 0;
    ll curStart = ranges[0].first;
    ll curEnd = ranges[0].second;

    for (int i = 1; i < sza(ranges); i++) {
        if (ranges[i].first <= curEnd) {
            curEnd = max(curEnd, ranges[i].second);
        } else {
            total += (curEnd - curStart + 1);
            curStart = ranges[i].first;
            curEnd = ranges[i].second;
        }
    }

    total += (curEnd - curStart + 1);
    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}