#include<bits/stdc++.h>
//https://school.programmers.co.kr/learn/courses/30/lessons/150366?language=cpp 문제
//https://www.youtube.com/watch?v=x7Fx5isJGCU 표병합 설명 영상
#define R first
#define C second
using namespace std;


string grid[52][52];
pair<int, int> p[52][52];

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
pair<int, int> find(int r, int c) {
	if (p[r][c] == make_pair(r,c))
		return { r,c };

	auto parent = p[r][c];

	return p[r][c] = find(parent.R, parent.C);

}
void init() {
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			p[i][j] = { i,j };

	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			grid[i][j] = "";
}
vector<string> solution(vector<string> commands) {
	vector<string> answer;
	init();
	for (auto cmd : commands) {
		vector<string> token = split(cmd, ' ');
		if (token[0]=="UPDATE") {
			if (token.size() == 4) {
				int r, c;
				string val;
				r = stoi(token[1]);
				c= stoi(token[2]);
				val=token[3];
				tie(r, c) = find(r, c);
				grid[r][c] = val;
			}
			else if (token.size() == 3) {
				string val1, val2;
				val1 = token[1];
				val2 = token[2];
				for (int i = 1; i <= 50; i++)
					for (int j = 1; j <= 50; j++)
						if (grid[i][j] == val1)
							grid[i][j] = val2;
			}
		}
		else if (token[0] == "MERGE") {
			int r1, c1, r2, c2;
			r1 = stoi(token[1]);
			c1 = stoi(token[2]);
			r2 = stoi(token[3]);
			c2 = stoi(token[4]);
			int pr1, pc1, pr2, pc2;
			tie(pr1, pc1) = find(r1, c1);
			tie(pr2, pc2) = find(r2, c2);
			if (make_pair(pr1, pc1) == make_pair(pr2, pc2))continue;
			string val = (!grid[pr1][pc1].empty()) ? grid[pr1][pc1] : grid[pr2][pc2];
			p[pr2][pc2] = { pr1,pc1 };
			grid[pr1][pc1] = val;
			grid[pr2][pc2] = "";
		}
		else if (token[0] == "UNMERGE") {
			int r, c;
			r = stoi(token[1]);
			c = stoi(token[2]);
			int pr, pc;
			tie(pr, pc) = find(r, c);
			string val = grid[pr][pc];
			vector<pair<int, int>>candidates;
			for (int i = 1; i <= 50; i++)
			{
				for (int j = 1; j <= 50; j++) {
					int _pr, _pc;
					tie(_pr, _pc) = find(i, j);
					if (make_pair(_pr, _pc) == make_pair(pr, pc))
						candidates.push_back({ i,j });
				}
			}

			for (auto it : candidates) {
				p[it.R][it.C] = { it.R,it.C };
				grid[it.R][it.C] = "";
			}
			grid[r][c] = val;

		}
	
		
		else if (token[0] == "PRINT") {
			int r, c;
			r = stoi(token[1]);
			c = stoi(token[2]);
			tie(r, c) = find(r, c);
			if (grid[r][c].empty())
				answer.push_back("EMPTY");
			else
				answer.push_back(grid[r][c]);
		}

	}
	
	return answer;
}

 int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 vector<string> commands = { "UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1" };
	 solution(commands);
	 return 0;
}
