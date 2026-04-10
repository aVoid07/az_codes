//problem link: https://cses.fi/problemset/task/2428/
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int> mp;
    int head = -1, tail = 0;
    long long ans = 0;
    while(tail < n){
        while(head + 1 < n && (mp.size() < k || mp.find(arr[head + 1]) != mp.end()) ){
            head++;
            mp[arr[head]]++;
        }
        ans += head - tail + 1;
        if(tail <= head){
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0){
                mp.erase(arr[tail]);
            }
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); 
    solve();
}