#include <bits/stdc++.h>
using namespace std;

//https://www.acmicpc.net/problem/6603
int a[20] = {0,};
int b[20] = { 0,};


void sol(int n)
{
    do {
        for (int i = 0; i < n; i++) {
            if (b[i] == 0)
                cout << a[i] << ' ';
        }

        cout << '\n';
    } while (next_permutation(b, b + n));
    cout << '\n';
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        fill(a, a + 20, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < 6; i++)
            b[i] = 0;
        for (int i = 6; i < n; i++)
            b[i] = 1;
        sol(n);
    }
   
    
  
}