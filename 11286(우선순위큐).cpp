// https://www.acmicpc.net/problem/11286
#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout <<"ans" << pq.top() << '\n';
                pq.pop();
            }

        }
        else pq.push(x);
    }
}