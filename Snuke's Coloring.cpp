//problem link: https://atcoder.jp/contests/arc061/tasks/arc061_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int h, w, n;
    cin>> h>>w>>n;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++){
        int r,c;
        cin>>r>>c;
        for(int i = r - 1; i <= r + 1; i++){
            for(int j = c - 1; j <= c + 1; j++){
                if(i >= 2 && i <= h-1 && j >= 2 && j <= w-1){
                    mp[{i, j}]++;
                }
            }
        }
    }
    long long ans[10] = {0};
    ans[0] = (h-2) * (w-2);
    for(auto it: mp){
        ans[it.second]++;
        ans[0]--;
    }
    for(auto it: ans){
        cout<<it<<endl;
    }
}