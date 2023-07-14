//https://www.acmicpc.net/problem/1916
/*
변수 이름을 중복해서 씀
다익스트라 구현 연습 필요

*/
#include <bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;

int v,e,st,en;
int dist[1002];
vector<pair<int,int>> adj[1002];

int sol()
{
   
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>> > pq;
   
   
    dist[st]=0;
    pq.push({0,st});
   
    while(!pq.empty())
    {
        int cw,cv,nw,nv;
        tie(cw,cv)=pq.top(); pq.pop();
        if(dist[cv]!=cw)continue;
       
        for(auto nxt:adj[cv])
        {
            tie(nw,nv)=nxt;
            nw+=cw;
            if(dist[nv]>nw){
                 dist[nv]=nw;
                 pq.push({nw,nv});
             
            }
           
        }
    }
   
    return dist[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin>>v>>e;
    fill(dist,dist+v+1,INF);
   
    int fr,to,w;
    while(e--)
    {
        cin>>fr>>to>>w;
        adj[fr].push_back({w,to});
       
    }
    cin>>st>>en;
    cout<<sol();
   
}
