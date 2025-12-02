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

bool isDouble(ll x) {
    string s = to_string(x);
    int m = s.size();
    if (m % 2) return false;
    string a = s.substr(0, m / 2);
    string b = s.substr(m / 2);
    return a == b;
}

void solve() {
    string s;
    cin >> s;
    vector<pair<ll,ll>> v;
    string cur = "";
    for (char c : s) {
        if (c == ',') {
            int p = cur.find('-');
            ll l = stoll(cur.substr(0, p));
            ll r = stoll(cur.substr(p + 1));
            v.push_back({l, r});
            cur = "";
        } else cur += c;
    }
    ll ans = 0;
    for (auto &p : v) {
        for (ll x = p.first; x <= p.second; x++) {
            if (isDouble(x)) ans += x;
        }
    }
    cout << ans;
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