


#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/11404
using namespace std;
int v, e;

const int INF = 0x3f3f3f3f;
int m[105][105];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        fill(m[i], m[i]+1+v, INF);

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //간선이 입력값으로 여러개 주어짐
        m[a][b] = min(m[a][b],c);
    }

    for (int i = 1; i <= v; i++)
        m[i][i] = 0;

    for (int k = 1; k <= v; k++) 
        for (int i = 1; i <= v; i++) 
            for (int j = 1; j <= v; j++) 
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
          

      for (int i = 1; i <= v; i++) {
          for (int j = 1; j <= v; j++) {
              if (m[i][j] == INF)
                  cout << "0 ";
              else
                cout << m[i][j] << ' ';
          }
          
          cout << '\n';
      }
         
  

}