


#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/11780
using namespace std;
int v, e;

const int INF = 0x3f3f3f3f;
int m[105][105];
int nxt[105][105];//edge<a,b> a에서 b까지 최단거리로 가려면 어디로가야하는가?


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
        nxt[a][b] = b;
    }

    for (int i = 1; i <= v; i++)
        m[i][i] = 0;

    for (int k = 1; k <= v; k++) 
        for (int i = 1; i <= v; i++) 
            for (int j = 1; j <= v; j++)
                if (m[i][j] > m[i][k] + m[k][j])
                {
                    m[i][j] = m[i][k] + m[k][j];
                    nxt[i][j] = nxt[i][k];
                }
                   
           
              
      for (int i = 1; i <= v; i++) {
          for (int j = 1; j <= v; j++) {
              if (m[i][j] == INF)
                  cout << "0 ";
              else
                cout << m[i][j] << ' ';
          }
          
          cout << '\n';
      }
         
      for (int i = 1; i <= v; i++) {
          for (int j = 1; j <= v; j++) {
              if (m[i][j] == 0 || m[i][j] == INF) {
                  cout << "0\n";
                  continue;
              }
              vector<int> path;
              int st = i;
              while (st != j) {
                  path.push_back(st);
                  st = nxt[st][j];
              }
              path.push_back(j);
              cout << path.size() << ' ';
              for (auto x : path) cout << x << ' ';
              cout << '\n';
          }
      }

}