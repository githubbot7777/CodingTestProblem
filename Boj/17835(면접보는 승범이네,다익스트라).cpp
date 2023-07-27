// https://www.acmicpc.net/problem/17835
/*
출발->도착 정석으로 구하면 시간복잡도(10^5*10^5)로 인해 시간초과
면접장->도시(도착->출발) 로 하고 모든 간선의 출발,도착을 반대로 받는다.

자료형 크기 주의
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
