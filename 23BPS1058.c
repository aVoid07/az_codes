#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n)
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans = 0;
    for(int i =0;i<n;i++)
    {
        ans+=  a[i] * (2*i - n + 1);
    }
}
int main()
{
    solve();
}