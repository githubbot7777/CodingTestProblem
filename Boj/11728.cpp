//  https://www.acmicpc.net/problem/11728
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000002];
int b[1000002];
int c[2000004];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int index_a = 0;
    int index_b = 0;
    int index_c = 0;
    while (index_a < n && index_b < m)
    {
        if (a[index_a] <= b[index_b])
        {
            c[index_c++] = a[index_a++];
        }
        else {
            c[index_c++] = b[index_b++];
        }
    }

    if (index_a >= n)
    {
        for (int i = index_b; i < m; i++)
            c[index_c++] = b[i];
    }
    else {
        for (int i = index_a; i < n; i++)
            c[index_c++] = a[i];
    }



    for (int i = 0; i < index_c; i++)
    {
        cout << c[i] << " ";
    }





    return 0;
}
