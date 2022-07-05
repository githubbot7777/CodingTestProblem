/*����
�����̴� �̷ο��� ���� �Ѵ�. �����̸� �̷ο��� Ż���ϵ��� ��������!

�̷ο����� �������� ��ġ�� ���� ���� ��ġ�� �����ؼ� �����̰� �ҿ� Ÿ������ Ż���� �� �ִ����� ����, �׸��� �󸶳� ���� Ż���� �� �ִ����� �����ؾ��Ѵ�.

�����̿� ���� �� �и��� ��ĭ�� ����Ǵ� ��������(�񽺵��ϰ� �̵����� �ʴ´�)  �̵��Ѵ�. 

���� �� �������� �� �������� Ȯ��ȴ�. 

�����̴� �̷��� �����ڸ��� ���� �������� Ż���� �� �ִ�. 

�����̿� ���� ���� �ִ� ������ ������� ���Ѵ�.

�Է�
�Է��� ù° �ٿ��� �������� ���е� �� ���� R�� C�� �־�����. ��, 1 �� R, C �� 1000 �̴�. R�� �̷� ���� ����, C�� ���� �����̴�.

���� �Է����� R�ٵ��� ������ �̷� ���� �־�����.

 ������ ���ڵ��� ������ ���Ѵ�.

#: ��
.: ������ �� �ִ� ����
J: �������� �̷ο����� �ʱ���ġ (������ �� �ִ� ����)
F: ���� �� ����
J�� �Է¿��� �ϳ��� �־�����.

���
�����̰� ���� �����ϱ� ���� �̷θ� Ż�� �� �� ���� ��� IMPOSSIBLE �� ����Ѵ�.

�����̰� �̷θ� Ż���� �� �ִ� ��쿡�� ���� ���� Ż��ð��� ����Ѵ�. */

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int vis1[1002][1002];
int vis2[1002][1002];
string board[1002];
int n,m;

queue<pair<int,int>>JQ,FQ;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        fill(vis1[i],vis1[i]+m,-1);
        fill(vis2[i],vis2[i]+m,-1);
    }
     
     for(int i=0;i<n;i++)
    {
        cin>>board[i];
    }
      
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(board[i][j]=='J')
             {
                JQ.push({i,j});
                vis1[i][j]=0;
             }
             
              if(board[i][j]=='F')
             {
                FQ.push({i,j});
                vis2[i][j]=0;
             }
         }
     }
     
     //fire
     while(!FQ.empty())
     {
         auto cur=FQ.front(); FQ.pop();
         for(int dir=0;dir<4;dir++)
         {
             int nx=cur.X+dx[dir];
             int ny=cur.Y+dy[dir];
             if(nx<0||nx>=n||ny<0||ny>=m)continue;
             if(board[nx][ny]=='#'||vis2[nx][ny]>=0)continue;
             
             vis2[nx][ny]=vis2[cur.X][cur.Y]+1;
             FQ.push({nx,ny});
         }
     }
     
     //����
      while(!JQ.empty())
     {
         auto cur=JQ.front(); JQ.pop();
         for(int dir=0;dir<4;dir++)
         {
             int nx=cur.X+dx[dir];
             int ny=cur.Y+dy[dir];
             if(nx<0||nx>=n||ny<0||ny>=m)
             {
                 cout<<vis1[cur.X][cur.Y]+1;
                 return 0;
             }
             if(board[nx][ny]=='#'||vis1[nx][ny]>=0)continue;
             if(vis2[nx][ny]!=-1&&vis1[cur.X][cur.Y]+1>=vis2[nx][ny])continue;
            
             vis1[nx][ny]=vis1[cur.X][cur.Y]+1;
              JQ.push({nx,ny});
         }
     }
    
    cout<<"IMPOSSIBLE";
    
    return 0;
}

