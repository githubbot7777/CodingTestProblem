
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1991
using namespace std;


int lc[30],rc[30];
int n;

void pre_order(int root)
{
    char c=root + 'A'-1;
    cout << c;
    if (lc[root]!=0)pre_order(lc[root]);
    if (rc[root]!=0)pre_order(rc[root]);
}

void in_order(int root)
{
    char c = root + 'A' - 1;
    if (lc[root] != 0)in_order(lc[root]);
    cout << c;
    if (rc[root] != 0)in_order(rc[root]);
}

void post_order(int root)
{
    char c = root + 'A' - 1;
   
    if (lc[root] != 0)post_order(lc[root]);
    if (rc[root] != 0)post_order(rc[root]);
    cout << c;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char cur, l, r;
        cin >> cur >> l >> r;
        if (l != '.')lc[cur - 'A' + 1] = l - 'A' + 1;
        if (r != '.')rc[cur - 'A' + 1] = r - 'A' + 1;
    }
   
    pre_order(1);
    cout << "\n";
    in_order(1);
    cout << "\n";
    post_order(1);
}
