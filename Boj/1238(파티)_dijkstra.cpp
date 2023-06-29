/*
문제:https://www.acmicpc.net/problem/1238
플로이드가 더 어울리는 문제인것 같다.
1. 모든 출발점에서-> 도착점 까지의 거리
2. 도착점-> 모든 출발점 거리
1번 2번의 합을 정렬 후 가장 큰 거리를 출력 해줬다.

  */
#define W first
#define V second

#include <bits/stdc++.h>

using namespace std;
const int INF=0x3f3f3f3f;
int v,e,st,en;
vector<pair<int,int>> adj[1002];
int dist_r[1002];
 int dist[1002];

void di(int start)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
  
   fill(dist,dist+v+1,INF);
   
   dist[start]=0;
   pq.push({dist[start],start});
   while(!pq.empty())
   {
       auto cur=pq.top();pq.pop();
       if(dist[cur.V]!=cur.W)continue;
       for(auto nxt:adj[cur.V])
       {
           if(dist[nxt.V]>dist[cur.V]+nxt.W)
           {
               dist[nxt.V]=dist[cur.V]+nxt.W;
               pq.push({dist[nxt.V],nxt.V});
           }   
       }
   }
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin>>v>>e>>en;
   
   for(int i=0;i<e;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({w,v});
   }
   
   for(int i=1;i<=v;i++)
   {
       di(i);
       dist_r[i]+=dist[en];
       
       di(en);
       dist_r[i]+=dist[i];
   }
   sort(dist_r+1,dist_r+v+1);
  
   cout<<dist_r[v];

    return 0;
}
