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
    char dir;
    int amt;
    int pos = 50;
    ll p1 = 0, p2 = 0;

    while (cin >> dir >> amt) {
        for (int i = 0; i < amt; i++) {
            if (dir == 'L') {
                pos--;
                if (pos < 0) pos = 99;
            } else if (dir == 'R') {
                pos++;
                if (pos > 99) pos = 0;
            }

            if (pos == 0) p2++;
        }

        if (pos == 0) p1++;
    }

    cout << p1 << "\n" << p2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}