#include<bits/stdc++.h>
//https://softeer.ai/practice/info.do?idx=1&eid=1256

using namespace std;

int h, k, r;

queue<int> lc[2100];
queue<int> rc[2100];

int all_node_num;
int day;
int result = 0;
//2의 배수 왼쪽 3의배수 오른쪽
void post_order(int r,int depth)
{
	if (depth>h)
		return;
	
	
	if (depth==h)//leaf node 말단 직원
	{
		if (r % 2 == 0&&!lc[r].empty())
		{
			
				int pop = lc[r].front();
				lc[r].pop();
				lc[r/2].push(pop);
	
		}
		else if (r%2==1&& !lc[r].empty()) {
			
				int pop = lc[r].front();
				lc[r].pop();
				rc[r/2].push(pop);
		
		}
	}
	else {//상사

		if (day % 2 == 0&& !rc[r].empty())
		{
			
				int pop = rc[r].front();
				rc[r].pop();
				if (r == 1)
				{
					result += pop;
				}
				else {
					if (r % 2 == 0)
					{
						lc[r / 2].push(pop);
					}
					else if (r % 2 == 1)
						rc[r / 2].push(pop);
				}
			
		}
		else if (day % 2 == 1&& !lc[r].empty()) {
			
				int pop = lc[r].front();
				lc[r].pop();
				if (r == 1)
				{
					result += pop;
				}
				else {
					if (r % 2 == 0)
					{
						lc[r / 2].push(pop);
					}
					else if (r % 2 == 1)
						rc[r / 2].push(pop);
				}
			}
		
	}
	post_order(r * 2, depth + 1);
	post_order(r * 2 + 1, depth + 1);
}
 int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 //첫 줄에 조직도의 높이 H, 말단에 대기하는 업무의 개수 K, 업무가 진행되는 날짜 수 R
	 cin >> h >> k >> r;
	 
	     all_node_num = pow(2, h + 1) - 1;
	 int leaf_node_num = pow(2, h);
	 int start_leaf_index = all_node_num - leaf_node_num + 1;
	 for (int i = 0; i < leaf_node_num; i++)
	 {
		 for (int j = 0; j < k; j++)
		 {
			 int t;
			 cin >> t;
			 lc[start_leaf_index + i].push(t);
		 }
	 }
	 
	 for (day = 1; day <= r; day++)
		 post_order(1,0);

	
	
	 cout << result;
	 /*
	    o
	  o   o
	  9	  5
	  3   11
	  7   2
	 
	 */

	 return 0;
}