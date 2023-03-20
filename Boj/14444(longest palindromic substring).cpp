
//https://www.acmicpc.net/problem/14444
//가장 긴 회문 찾기
//설명https://www.crocus.co.kr/1075

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001 * 2;
string tmp, str;
int A[MAX];
void manacher(string s)
{
    int n = s.size();
  
    int r = -1, p = -1;
    //p는 회문의 중심 인덱스, r은 회문의 오른쪽 끝 인덱스 의미
    for (int i = 0; i < n; i++)
    {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 <n && s[i - A[i] - 1] == s[i + A[i] + 1])
            A[i] = A[i] + 1;

        if (i + A[i] > r)
        {
            r = i + A[i];
            p = i;
        }
    }
 
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tmp;
    int len = tmp.size();
    for (int i = 0; i < len; i++)
    {
        str += '#';
        str += tmp[i];
    }
    str += '#';
    manacher(str);

    len = str.size();
    cout << *max_element(A, A + len);
    
    return 0;
}


