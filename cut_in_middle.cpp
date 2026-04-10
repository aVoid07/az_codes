//question link: https://atcoder.jp/contests/abc237/tasks/abc237_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> l, r;
    int c = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            r.push_front(c);
        } else {
            l.push_back(c);
        }
        c = i + 1;
    }

    for (int x : l) cout << x << " ";
    cout << c;
    for (int x : r) cout << " " << x;
    cout << endl;

    return 0;
}