/*
First One 

Problem Statement
-----------------
You are given N intervals on the number line.
Each interval is of the form [L, R] (inclusive of L, and ending exactly at R).
You are also given an integer K.
Your task is to compute the total duration of all points on the number line that are covered by at least K intervals simultaneously.

In other words:
- At every point x, check how many intervals cover x.
- If that count ≥ K, then that point contributes to the answer.
- Sum the lengths of all such portions.

Input
First line: two integers N and K
Next N lines: each contains two integers L and R, representing an interval [L, R].

Output
Print a single integer:
The total length of the union of all positions where the number of active intervals is ≥ K.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        events.push_back({l,+1});
        events.push_back({r,-1});
    }

    sort(events.begin(),events.end());

    int cnt=0;
    int ans=0;

    for(int i=0;i<events.size();i++)
    {
        cnt+=events[i].second;


        //Its Not n ﻿
        if(i+1<events.size() && cnt>=k)
        {
            ans += events[i+1].first - events[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}


/*Example :

N=3 , K=2
 

        .    .  .

1               5

        3               7

            4       6

1   2   3   4   5   6   7   8   9   10

 

 

 

 
(1, +1)
(5, -1)
(3, +1)
(7, -1)
(4, +1)
(6, -1)

 
(1, +1)
(3, +1)
(4, +1)
(5, -1)
(6, -1)
(7, -1)

*/
/*
==============================================================================================================================
Second One
    Sweep Line Works ONLY If Events Are in Sorted Order
    
    
    Problem Statement : 
    -------------------
    N intervals (N <= 10^5)
    Each interval: [Li, Ri, Xi] (<= 10^5 each) (inclusive)
    Each interval has Xi value associated with it.
    
    
    Q queries (<= 10^5 each)
    Y K
    K Value <= 10
    
    
    For each query point Y, find all intervals that cover Y.
    Take their Xi values, choose the top K values, and add them.
    If there are fewer than K intervals, just add all the values you have.
    
    
    N 
    L R X  (N Times) 
    Q
    Y K (Q Times)
    
    
    5
    1 9 1
    5 7 2
    3 10 3
    11 19 5
    13 15 6
    5
    2 2
    4 5
    6 2
    14 2
    14 1
    
    
    Ans:
    1
    4
    5
    11
    6
    
    
    1               9
    ----------------- -> X=1
    
            5   7
            ----- -> X=2
            
        3             10
        --------------- -> X=3
        
                         11                      19
                         -------------------------- -> X=5
                         
                               13    15
                               -------- -> X=6
                               
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20   ->   Axis
    
    */








    /*
        2
        1 10 1   
        5 15 2    
        3
        7 3
        12 2 
        2 1 
    
    
        1                 10
        --------------------  X = 1
        
                5                        15
                ---------------------------   X = 2 
                
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17   ->   Axis
        
          |         |           |
         2,1      7,3         12,2 
         y,k      y,k          y,k
         3rd      1st         2nd Query  
          1        3            2       -> Answers For Each Query 
          
        
    
        0 7 3     -> 0,1,2 Are Indexing
        1 12 2
        2 2 1 
        
        Sorting Based On Y Value
        
        2 2 1     -> 0,1,2 Are Indexing
        0 7 3
        1 12 2
    */


    
    #include <bits/stdc++.h>
    using namespace std;
    int getSumTopK(multiset<int>& st, int k) 
    {
        int sum = 0;
        int currk = 0;
        for(auto it = st.rbegin(); it != st.rend() && currk < k; it++, currk++) 
        {
            sum += *it;
        }
        return sum;
    }
    signed main() 
    {
        /*
            add     -> 0
            remove  -> 2
            query   -> 1
        */
        int n;
        cin >> n;
        vector< pair< pair<int, int>, pair<int, int> > > events;
        for(int i = 0; i < n; i++) 
        {
            int l, r, x;
            cin >> l >> r >> x;
            events.push_back( { {l,0},{x,i} } );
            events.push_back( { {r,2},{x,i} } );     
        }
    
        int q;
        cin >> q;
    
        for(int i = 0; i < q; i++) 
        {
            int y, k;
            cin >> y >> k;
            events.push_back( { {y,1},{k,i} } );      
        }
    
        sort(events.begin(), events.end()); // l r y were used for sorting so that events are in sequence now
        int ans[q]; // for outputing ans
        
        multiset<int> st;
    
        for(int i = 0; i < events.size(); i++) 
        {
            // { { _ , _ } , { _ , _ } }  
            
            int point = events[i].first.first;
            int type = events[i].first.second;
            int metaData = events[i].second.first;   
            int idx = events[i].second.second;
    
            if(type == 0) 
            {
                st.insert(metaData);  // here metaData is value of the segment, add to the multiset
            } 
            else if(type == 2) 
            {
                st.erase(st.find(metaData)); // here metaData is value of the segment end here, remove from the multiset
            } 
            else if(type == 1) 
            {
                int k = metaData; // for query type, metaData is K value
                ans[idx] = getSumTopK(st, k);
            }
        }
    
        // print the ans in correct sequence
        for(int i = 0; i < q; i++) 
        {
            cout << ans[i] << "\n";
        }
        return 0;
    }


    /*
    2
    1 10 1
    5 15 2
    3
    7 3
    12 2
    2 1


    3
    2
*/