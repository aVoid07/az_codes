//https://codeforces.com/problemset/problem/214/A
// #include <bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n, m;
//     cin>> n >> m;
//     int ans =0;
//     int c = ceil(sqrt(n)), d = ceil(sqrt(m));
//     for(int a = 0; a <= max(m, c); a++){
//         for(int b = 0; b <= max(n, d); b++){
//             if(a* a + b == n && a + b* b == m){
//                 ans++;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>> n;
    vector<int> arr(n);
    vector<int> prev(n,0), next(n,0);
    int k = 0, total_ones = 0;
    for(int i = 0; i < n; i++){
        cin>> arr[i];
        prev[i] = k;
        if(arr[i] == 1) k++;
        total_ones += arr[i];
    }
    int ans = total_ones;
    k = 0;
    for(int i = n-1; i >=0; i--){
        next[i] = k;
        if(arr[i] == 1) k++;
    }
    for(int i = 0; i < n; i++){
        int ones = 0;
        int zeroes = 0;
        for(int j = i; j < n; j++){
            if(arr[j] == 0)zeroes++;
            else ones++;
            ans = max(ans,prev[i] + zeroes - ones + next[j]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}


