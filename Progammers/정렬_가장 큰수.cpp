//https://programmers.co.kr/learn/courses/30/lessons/42746
//참고https://mungto.tistory.com/22
#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> temp;
    string answer = "";
    for (auto it : numbers)
        temp.push_back(to_string(it));

    sort(temp.begin(), temp.end(), cmp);

    if (temp[0] == "0") return "0";

    for (auto it : temp)
        answer += it;

    return answer;
}