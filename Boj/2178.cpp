
// 문제
// N×M크기의 배열로 표현되는 미로가 있다.

// 1	0	1	1	1	1
// 1	0	1	0	1	0
// 1	0	1	0	1	1
// 1	1	1	0	1	1
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

// 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

// 입력
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int board[102][102];
int vis[102][102]; 
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
      string temp;
      cin>>temp;
      
       for(int j=0;j<m;j++)
        {
              board[i][j]=temp[j]-'0';
            
         }
        
  }

  queue<pair<int,int>> Q;
  vis[0][0] = 1; 
  Q.push({0,0});
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; 
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
      if(vis[nx][ny] || board[nx][ny] != 1) continue; 
      vis[nx][ny] = vis[cur.X][cur.Y]+1;
      Q.push({nx,ny});
    }
  }
  
  cout<<vis[n-1][m-1];

}