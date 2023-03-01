//https://www.acmicpc.net/problem/11652
#include <bits/stdc++.h>
using namespace std;

int n, cnt, mxcnt;
long long card, mxval;
long long cards[100005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mxval = -(1ll << 62) - 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
    sort(cards, cards + n);



    for (int i = 0; i < n; i++)
    {

        if (i == 0 || cards[i - 1] == cards[i])
            cnt++;
        else {
            if (mxcnt < cnt)
            {
                mxcnt = cnt;
                mxval = cards[i - 1];
            }
            cnt = 1;
        }


    }

    if (mxcnt < cnt) mxval = cards[n - 1];

    cout << mxval;


    return 0;

}