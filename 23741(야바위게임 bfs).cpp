#include<bits/stdc++.h>
//https://www.acmicpc.net/problem/23741
using namespace std;
int v, e, st, mv;
int visited[1005][1005];//[위치][움직인횟수]
vector<int> adj[1005];
vector<int> answer;
queue<pair<int, int>> q;//<v,length>
 int main() {

	 cin >> v >> e >> st >> mv;
	 while (e--)
	 {
		 int u, v;
		 cin >> u >> v;
		 adj[u].push_back(v);
		 adj[v].push_back(u);
	 }

	 q.push({ st,0 });
	 visited[st][0] = 1;
	 while (!q.empty()) {
		 int cur = 0;
		 int length = 0;
		 tie(cur,length)=q.front();
		 q.pop();
		 if (length == mv) {
			 answer.push_back(cur);
			 continue;
		 }		  
		
		 for (int nxt : adj[cur]) {
			 if (!visited[nxt][length+1]&&length+1<=mv) {
				 visited[nxt][length + 1] = 1;
				 q.push({ nxt,length + 1 });
			 }	
		 }
	 }

	 if (answer.empty())
		 cout << -1;
	 else {
		 sort(answer.begin(), answer.end());
		 for (int i : answer)
			 cout << i << ' ';
	 }
	 
	 return 0;
}