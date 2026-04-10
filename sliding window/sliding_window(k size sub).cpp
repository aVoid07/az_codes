#include <bits/stdc++.h>
using namespace std;

struct monotone_deque
{
    deque<int> dq;

    void insert(int x)
    { // O(k)
        while (!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }
    void erase(int x)
    { // O(1)
        if (dq.front() == x)
            dq.pop_front();
    }
    int getmin()
    { // O(1)
        return dq.front();
    }
};


int main()
{ // O(n)
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    monotone_deque mt;
    for (int i = 0; i < n; i++)
    {                      // O(n)
        mt.insert(arr[i]); // O(1)
        if ((i - k) >= 0)
            mt.erase(arr[i - k]); // O(1)
        if (i >= (k - 1))
            cout << mt.getmin() << endl; // O(1)
    }
}
