//problem link: https://atcoder.jp/contests/arc061/tasks/arc061_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> dp(101, vector<int>(100100, -1));
vector<vector<int>> knap;
int n, w;
int rec(int level, int w) {
    if(level == n) {
        return 0;
    }
    if(dp[level][w] != -1) {
        return dp[level][w];
    }
    int ans = rec(level + 1, w);
    if(knap[level][0] <= w) {
        ans = max(ans, knap[level][1] + rec(level+1, w - knap[level][0]));
    }
    return dp[level][w] = ans;
}
signed main() {
    cin>> n>> w;
    knap.resize(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin>> knap[i][0] >> knap[i][1];
    }
    cout<< rec(0, w) << endl;
}