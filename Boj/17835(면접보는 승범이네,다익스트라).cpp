// https://www.acmicpc.net/problem/17835
/*
출발->도착 정석으로 구하면 시간복잡도 O(VElgE)로 인해 시간초과
출발 도착점을 바꿔서 다익스트라 한번에 구할 수 있게한다.
면접장->도시(도착->출발) 로 하고 모든 간선의 출발,도착을 반대로 받는다.

도시의 수 10^5,도시의 길이가 10^5이기 때문에
int 범위 넘을 가능성 있음-> long long 사용

다익스트라 시작점 여러개여도 됨. 
다익스트라의 원리가 현재까지 최단 거리임이 보장된 정점들의 비용을 기반으로
아직 보장되지 않은 정점 중 코스트가 가장 작은 정점을 확장해나가는 방식이기에
시작점이 여러 개여도 상관없다.
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 0x7f7f7f7f7f7f;   
int n, m, k;

ll dist[100002];

vector<pair<ll, int>> adj[100002];

priority_queue< pair<ll, int>,
	vector<pair<ll, int>>,
	greater<pair<ll, int>> >pq;


void solve()
{
	while (!pq.empty())
	{
		int cv, nv;
		ll cw, nw;	
		tie(cw, cv) = pq.top(); pq.pop();
		if (dist[cv] != cw)continue;
		for (auto it : adj[cv])
		{
			
			tie(nw, nv) = it;
			if (dist[nv] > cw + nw)
			{
				dist[nv] = cw + nw;
				pq.push({ dist[nv],nv });
			}
		}
	
	}

}

int main() {
	cin >> n >> m >> k;
	fill(dist + 1, dist + n + 1, INF);

	int u, v;
	ll w;
	while (m--)
	{
		cin >> u >> v >> w;
		adj[v].push_back({ w,u });
	}

	while (k--)
	{
		int t;
		cin >> t;
		dist[t] = 0;
		pq.push({ dist[t],t });
	}

	solve();
	
	int idx = max_element(dist + 1, dist + n + 1) - dist;
	cout << idx << '\n' << dist[idx];

	
	return 0;
}
