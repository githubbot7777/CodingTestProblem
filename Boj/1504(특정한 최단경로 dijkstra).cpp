//https://www.acmicpc.net/problem/1504
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
int dist[1002];

vector<pair<int,int>> adj[1002];
priority_queue<pair< int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

//m1, m2는 반드시 거쳐야 되는 정점
//v는 정점의 갯수, 도착점
int v,e,m1,m2;

//st에서 en으로 가는 최단거리
ll di(int st,int en)
{
    fill(dist,dist+v+1,INF);
   
    dist[st]=0;
    pq.push({dist[st],st});
    
    while(!pq.empty())
    {
        int cw,cv;
        tie(cw,cv)=pq.top(); pq.pop();
        if(dist[cv]!=cw)continue;
        
        for(auto nxt:adj[cv])
        {
            int nw,nv;
            tie(nw,nv)=nxt;
            if(dist[nv]>dist[cv]+nw)
            {
                dist[nv]=dist[cv]+nw;
                pq.push({dist[nv],nv});
            }
              
        }
        
    }
    return dist[en];
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin>>m1>>m2;
    
    ll ans1=di(1,m1)+di(m1,m2)+di(m2,v);
    ll ans2=di(1,m2)+di(m2,m1)+di(m1,v);
    
    ll ans=min(ans1,ans2);
    if(ans>=INF)
    {
        cout<<-1;
        return 0;
    }
    
    cout<<ans;
    

    return 0;
}
