#include<bits/stdc++.h>
//https://school.programmers.co.kr/learn/courses/30/lessons/150367
#define ll long long

using namespace std;

string to_bin(ll n) {
	string temp = "";
	while (n > 0)
	{
		temp += to_string(n % 2);
		n /= 2;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

bool dfs(string& bin_str, ll root, ll depth) {

	if (depth == 0)return true;
	if (root < 0 || root >= bin_str.length())return false;

	if (bin_str[root] == '0')
	{
		if (bin_str[root + depth] == '1' || bin_str[root - depth] == '1')
			return false;
	}

	return dfs(bin_str, root - depth, depth / 2) && dfs(bin_str, root + depth, depth / 2);
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	string bin_str;
	string comp_bin_str;
	ll bin_str_length = 0;
	ll c_bin_str_length = 0;
	for (auto num : numbers) {
		bin_str = "";
		comp_bin_str = "";

		bin_str = to_bin(num);
		bitset<64> bits(bin_str);

		bin_str_length = bin_str.length();

		comp_bin_str = to_bin(bin_str_length + 1);
		bitset<64> c_bits(comp_bin_str);

		c_bin_str_length = comp_bin_str.length();

		for (int i = 1; i < c_bin_str_length; i++) {
			if (comp_bin_str[i] == '1')
			{
				/*
				포화이진트리 갯수=2^n-1
				가장 가까운 갯수=문자열의 길이+1=2^n 
				*/
				ll diff = (1 << c_bin_str_length) - (c_bits.to_ulong());

				string zeros = "";
				for (ll j = 0; j < diff; j++)
					zeros += '0';

				bin_str = zeros + bin_str;
				bin_str_length += zeros.length();
				break;
			}
		}

		//depth 규칙  
		int result = dfs(bin_str, bin_str_length / 2, (bin_str_length + 1) / 4);


		answer.push_back(result);
	}


	return answer;
}
