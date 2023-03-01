/*
https://www.acmicpc.net/problem/1068
*/


#include <bits/stdc++.h>

using namespace std;

/*

*/

int n,del;
int a[51];
int isleaf[51];
int result = 0;

void dfs(int cur)
{
    if (a[cur] == -2)
        return;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == -2)continue;
        if (a[i] == cur)
        {
            dfs(i);
          
        }
    }
         a[cur] = -2;
   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(isleaf, isleaf + 51, 1);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> del;
    dfs(del);

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
           isleaf[a[i]] = 0;

       
    }
    

    for (int i = 0; i < n; i++)
    {
        if (isleaf[i]&&a[i]!=-2)
            result++;
    
    }
    cout << result;
   
        return 0;
}



