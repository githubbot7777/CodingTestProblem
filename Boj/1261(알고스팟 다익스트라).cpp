// https://www.acmicpc.net/problem/1261
/*
목적지까지 가는 최소 벽을 뚫는 횟수를 구하여야한다.
놓친 발상
1. 최소비용과 좌표를 튜플로 하는 최소힙 만들기
2. 다음위치가 갈 수 있는 곳이면 동일한 비용, 벽인경우 1 추가해서 최소힙에 넣는다.
3. 다익스트라 시간복잡도 O( E*LOG(E) ) E:간선수
*/
#include <bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int m[102][102];
int d[102][102];
int r,c;

priority_queue< tuple<int,int,int>,
                vector< tuple<int,int,int>>,
                greater< tuple<int,int,int>> > pq;


void init()
{
     for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            d[i][j]=INF;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>r;
    init();
    for(int i=1;i<=r;i++){
        string str;
        cin>>str;
        for(int j=0;j<c;j++)
            m[i][j+1]=str[j]-'0';
    }
    
    d[1][1]=0;
   
    pq.push({0,1,1});
    while(!pq.empty())
    {
        int cw,cx,cy;
        tie(cw,cx,cy)=pq.top();pq.pop();
       
        if(d[cx][cy]!=cw)continue;
        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nw=cw;
            if(nx<1||ny<1||nx>r||ny>c)continue;
            if(m[nx][ny]==1)
               nw++;
               
            if(d[nx][ny]>nw) //실수한 부분  실수: if(d[nx][ny]>d[cx][cy]+nw)
             {
                 d[nx][ny]=nw;
                 pq.push({nw,nx,ny});
             }
            
          
        }
    }
    
    cout<<d[r][c];
 
    
    return 0;
}

/*
도착 장소인 (n, m)의 값을 그대로 활용하기 위해
배열을 1-indexed로 사용합니다.

벽을 부수는 횟수를 최소 하는 길을 찾는 문제기 때문에
벽을 부수는 횟수를 비용으로 둡니다.

튜플을 담는 최소힙을 선언하고,
초기 위치와 비용을 넣습니다.

이후 최소힙을 활용해 다익스트라 알고리즘을 활용합니다.

다음으로 건너갈 위치가 갈 수 있는 곳이면 동일한 비용을,
다음으로 건너갈 위치가 벽인 경우 비용을 1 추가해 최소힙에 넣습니다.

다음 위치가 방문했던 곳이라도 기록된 비용보다
더 적은 비용으로 접근 가능할 경우
비용을 갱신하고 최소힙에 다시 넣습니다.
모든 과정을 마친 후 최소힙이 비면 d[n][m]을 반환합니다.

가로 크기 100, 세로 크기 100으로 제한되므로,
최대 10^4 수준의 답이 나오므로 solve는 int 변수를 반환하게 둡니다.
*/
