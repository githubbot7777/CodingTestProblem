#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int board[1002][1002];
int vis[1002][1002]; 
int n,m; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int day=0;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>m>>n;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
        cin>>board[i][j];
  }
  queue<pair<int,int> > Q;
  
   for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(board[i][j]==1)
          {
               vis[i][j] = 1; 
               Q.push({i,j}); 
          }
      }
  }
 
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
  
    for(int dir = 0; dir < 4; dir++){ 
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; 
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
      if(vis[nx][ny] || board[nx][ny] !=0) continue; 
      vis[nx][ny] = vis[cur.X][cur.Y]+1; 
      day=vis[nx][ny];
      Q.push({nx,ny});
    }
  }
   for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
        
          if((board[i][j]+vis[i][j])==0)
          {
               cout<<-1;
               return 0;
          }
      }
   
  }
  if(day==0)
  {
      cout<<0;
      return 0;
  }
  
  
  cout<<day-1;
}