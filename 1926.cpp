
/*
����
� ū ��ȭ���� �׸��� �׷��� ���� ��, �� �׸��� ������, �� �׸� �� ���̰� ���� ���� ���� ���̸� ����Ͽ���. ��, �׸��̶�� ���� 1�� ����� ���� �� �׸��̶�� ��������. ���γ� ���η� ����� ���� ������ �� ���̰� �밢������ ������ �� ���� ������ �׸��̴�. �׸��� ���̶� �׸��� ���Ե� 1�� �����̴�.

�Է�
ù° �ٿ� ��ȭ���� ���� ũ�� n(1 �� n �� 500)�� ���� ũ�� m(1 �� m �� 500)�� ���ʷ� �־�����. �� ��° �ٺ��� n+1 �� ���� �׸��� ������ �־�����. (�� �׸��� ������ 0�� 1�� ������ �ΰ� �־�����, 0�� ��ĥ�� �ȵ� �κ�, 1�� ��ĥ�� �� �κ��� �ǹ��Ѵ�)

���
ù° �ٿ��� �׸��� ����, ��° �ٿ��� �� �� ���� ���� �׸��� ���̸� ����Ͽ���. ��, �׸��� �ϳ��� ���� ��쿡�� ���� ���� �׸��� ���̴� 0�̴�.

*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using namespace std;
int board[502][502];
bool vis[502][502];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0;
int bfs(int sx,int sy)
{
    if(vis[sx][sy])
         return -1;
    
    cnt++;
    queue<pair<int,int>>Q;
    vis[sx][sy]=1;
    Q.push({sx,sy});
    int size=1;
    while(!Q.empty())
    {
        pair<int,int>cur=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(vis[nx][ny]||board[nx][ny]!=1)continue;
            vis[nx][ny]=1;
            Q.push({nx,ny});
            size++;
        }
    }
    
    return size;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    int max=0;
    
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==1)
            {
                int size=bfs(i,j);
                if(size>max)
                  max=size;
            }
               
               
        }
    }
    
    cout<<cnt<<"\n"<<max;
    return 0;
}
