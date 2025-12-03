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

ll part1(const vector<string> &lines) {
    ll ans = 0;
    for (auto &s : lines) {
        int n = sza(s);
        int maxJ = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = (s[i] - '0') * 10 + (s[j] - '0');
                maxJ = max(maxJ, val);
            }
        }
        ans += maxJ;
    }
    return ans;
}

ll part2(const vector<string> &lines) {
    ll ans = 0;
    for (auto &s : lines) {
        string res = "";
        int n = sza(s);
        int k = 12;
        int drop = n - k;
        
        for (char c : s) {
            while (drop > 0 && !res.empty() && res.back() < c) {
                res.pop_back();
                drop--;
            }
            res += c;
        }
        
        string best = res.substr(0, 12);
        ans += stoll(best);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    vector<string> lines;
    string s;
    while (cin >> s) lines.push_back(s);
    
    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}