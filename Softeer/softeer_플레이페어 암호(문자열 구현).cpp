#include<bits/stdc++.h>
//문제https://softeer.ai/practice/info.do?idx=1&eid=804&sw_prbl_sbms_sn=146211
using namespace std;
char m[5][5];
string msg;
string key;
int alpha[26];

void print_m()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << m[i][j];

		cout << '\n';
	}
}

void encrpt_msg()
{
	for (int i = 1; i < msg.size(); i += 2) {
		if (msg[i - 1] == msg[i] && msg[i] == 'X')
		{
			msg.insert(i, 1, 'Q');
		}
		else if (msg[i - 1] == msg[i])
			msg.insert(i, 1, 'X');

	}
	if (msg.size() % 2 != 0)
		msg.append("X");
	//cout<<msg;
}
vector<int> find_char(char c)
{
	vector<int> r;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (m[i][j] == c)
			{
				r.push_back(i);
				r.push_back(j);
			}
		}

	}
	//cout<<c<<":"<<r[0]<<","<<r[1]<<'\n';
	return r;
}
void encrpt_m() {
	for (int i = 1; i < msg.size(); i += 2) {
		vector<int>rc1 = find_char(msg[i - 1]);
		vector<int>rc2 = find_char(msg[i]);
		if (rc1[0] == rc2[0])//같은 행에 존재할경우
		{
			rc1[1] = (rc1[1] + 1) % 5;
			rc2[1] = (rc2[1] + 1) % 5;

		}
		else if (rc1[1] == rc2[1])//같은 열에 존재할경우
		{
			rc1[0] = (rc1[0] + 1) % 5;
			rc2[0] = (rc2[0] + 1) % 5;
		}
		else {
			swap(rc1[1], rc2[1]);
		}

		msg[i - 1] = m[rc1[0]][rc1[1]];
		msg[i] = m[rc2[0]][rc2[1]];

	}

}

int main(int argc, char** argv)
{
	alpha[9] = 1;//J 처리
	cin >> msg >> key;
	int r = 0, c = 0;
	for (int i = 0; i < key.length(); i++) {
		int index = (int)key[i] - 65;
		if (!alpha[index])
			alpha[index] = 1;
		else
			continue;

		m[r][c] = key[i];
		c++;
		if (c == 5)
		{
			c = 0;
			r++;
		}

	}
	for (int i = 0; i < 26; i++) {
		if (!alpha[i])
		{
			m[r][c] = (char)(i + 65);
		}
		else {
			continue;
		}

		c++;
		if (c == 5)
		{
			c = 0;
			r++;
		}

	}
	//print_m();
	encrpt_msg();
	encrpt_m();
	cout << msg;



	return 0;
}