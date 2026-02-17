#include <bits/stdc++.h>
using namespace std;
bool cust(pair<int,int> a1, pair<int,int> a2 ){
    return a1.first + a1.second < a2.first + a2.second;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i ++){
        cin>>b[i];
    }
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({a[i],b[i]});
    }
    sort(v.begin(), v.end(), cust);
    long long al = 0;
    if(n%2){
       for(int i = 0; i < (n/2) + 1; i ++){
        al+=v[i].first;
       }
       for(int i = (n/2) + 1; i < n;i++){
        al -= v[i].second;
       } 
    }
    else{
        for(int i = 0; i < (n/2); i ++){
        al+=v[i].first;
       }
       for(int i = (n/2) ; i < n;i++){
        al -= v[i].second;
       } 
    }
    if(al > 0){
        cout<<"Alice\n";
    }
    else if(al<0){
        cout<<"Bob\n";
    }
    else{
        cout<<"Tie\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}