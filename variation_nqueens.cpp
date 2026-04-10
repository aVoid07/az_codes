#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> queens;
int queenplaced = 0;

void visualize(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==queens[i])cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}


bool check(int row,int col){
    if(col==-1)return 1;
    for(int pr=0;pr<row;pr++){
        int pc = queens[pr];
        if(pc==-1)continue;
        if(pc==col)return 0;
        if(abs(pc-col)==abs(row-pr))return 0;
    }
    return 1;
}

int ans = 0;
void rec(int row){
    if(queenplaced>k)return; // Pruning
    // basecase
    if(row==n){
        if(queenplaced==k){
            for(auto v:queens)cout<<v<<" ";cout<<endl;
            ans++;
            visualize();
        }else{
            // rejected
        }
        return;
    }
    for(int ch=-1;ch<m;ch++){
        if(check(row,ch)){
            queens.push_back(ch);
            if(ch!=-1)queenplaced++;
            rec(row+1);
            if(ch!=-1)queenplaced--;
            queens.pop_back();
        }
    }
}


void solve(){
    cin>>n>>m>>k;
    // if(k>min(n,m))cout<<0<<endl;
    rec(0);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}