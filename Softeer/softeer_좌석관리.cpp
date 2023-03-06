//문제: https://softeer.ai/practice/info.do?idx=1&eid=625&sw_prbl_sbms_sn=99436
//문제설명:https://www.youtube.com/watch?v=To4sF5i_3B8&t=8s
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, q;
int board[22][22];
int visited[10002];
pair<int, int> loc[10002];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
struct point {
	int x;
	int y;
	int safety;
};
void print_b()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

}
bool is_seat(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (board[nx][ny] == 1)
			return false;
	}
	return true;
}
int nearest(int x, int y)
{
	int mn = 1000;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 1)
			{
				mn = min(mn, (x - i) * (x - i) + (y - j) * (y - j));
			}
		}
	}
	return mn;
}
bool empty()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 1)
				return false;
		}
	}
	return true;
}
bool assign(int id)
{
	int mx_safety = 0;
	int mx = 0;
	int my = 0;
	if (empty())
	{
		loc[id] = { 1,1 };
		return true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 0 && is_seat(i, j))
			{
				int safety = nearest(i, j);
				if (safety > mx_safety)
				{
					mx_safety = safety;
					mx = i;
					my = j;
				}
				else if (safety == mx_safety && safety > 0)
				{

					if (mx > i)
						mx = i;
					else if (mx == i)
					{
						my = min(my, j);
					}
				}
			}
		}
	}
	if (mx == 0 && my == 0)
		return false;

	loc[id] = { mx,my };
	return true;

}

int main(int argc, char** argv)
{

	cin >> n >> m >> q;
	while (q--)
	{
		string str;
		int id;
		cin >> str >> id;
		//print_b();
		if (str == "In")
		{

			if (visited[id] == 1)
				cout << id << " already seated.\n";
			else if (visited[id] == 2)
				cout << id << " already ate lunch.\n";

			else {
				if (assign(id))
				{
					cout << id << " gets the seat (" << loc[id].X << ", " << loc[id].Y << ").\n";
					board[loc[id].X][loc[id].Y] = 1;
					visited[id] = 1;
				}
				else {
					cout << "There are no more seats.\n";

				}

			}
		}
		else {//out
			if (visited[id] == 0)
			{
				cout << id << " didn't eat lunch.\n";
			}
			else if (visited[id] == 1)
			{

				cout << id << " leaves from the seat (" << loc[id].X << ", " << loc[id].Y << ").\n";
				board[loc[id].X][loc[id].Y] = 0;
				visited[id] = 2;
			}
			else if (visited[id] == 2)
			{
				cout << id << " already left seat.\n";
			}
		}

	}
	return 0;
}