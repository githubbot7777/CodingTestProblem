/*
https://school.programmers.co.kr/learn/courses/30/lessons/92335
k진수에서 소수 개수 구하기
*/
#include <bits/stdc++.h>
using namespace std;

/*
1. 진법 변환
2. 0을 포함하지않는 소수 갯수 세기(10진법으로 봤을때)

잘못판단한것
1. 진법 변환후 int 범위 넘어갈수 있기 때문에 long long 자료형 사용해야함
2. 소수 판별할때 sqrt()를 안쓰니까 시간초과 발생
3. 문자열 숫자로 변환할때 문자열 null 체크
*/
typedef long long ll;


bool isprime(ll n)
{
    if (n == 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)return 0;
    }
    return 1;
}

string notation(int notation, int n)//진법,수
{
    string t = "";
        while (n > 0)
        {
            t+=to_string(n % notation);
            n /= notation;
         
        }

        return string(t.rbegin(), t.rend());
}

int solution(int n, int k) {
    int answer = 0;
   
    string temp = notation(k, n);

   
   
    cout <<"진법 변환후: "<< temp<<"\n";

    
    string primeStr;
    int length = temp.length();
    for (int i = 0; i < length; i++)
    {
        if (temp[i] != '0')
        {
            primeStr += temp[i];
        }
        else {
            if (!primeStr.empty()&&isprime(stoll(primeStr)))
            {
                answer++;
                cout<<primeStr<<"\n";
            }
            primeStr = "";
        }
    }
    if (!primeStr.empty() && isprime(stoll(primeStr)))
    {
        answer++;
        cout << primeStr << "\n";
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solution(110011, 10);


        return 0;
}



