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
    vector<string> grid;
    string line;
    while (cin >> line) {
        grid.push_back(line);
    }

    int rows = sza(grid);
    int cols = sza(grid[0]);
    ll ans = 0;
    bool running = true;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (running) {
        running = false;
        vector<pair<int, int>> toRemove;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '@') {
                    int neighbors = 0;
                    for (int i = 0; i < 8; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '@') {
                            neighbors++;
                        }
                    }
                    if (neighbors < 4) {
                        toRemove.push_back({r, c});
                    }
                }
            }
        }

        if (!toRemove.empty()) {
            running = true;
            ans += sza(toRemove);
            for (auto p : toRemove) {
                grid[p.first][p.second] = '.';
            }
        }
    }

    cout << ans << endl;
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