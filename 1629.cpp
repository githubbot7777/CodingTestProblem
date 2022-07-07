/*
함수 호출 한번에 두번의 재귀함수를 호출하면 오류가 난다.
함수 내에서 함수를 1번 부르는게 아니라 2번 불러서 시간복잡도가 O(log b)가 아닌 O(b)가 됨
 
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
 
 
 */
 
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
ll a,b,c;

ll cal(ll a,ll b)
{
    if(b==1)
    return a%c;
    
    ll t=cal(a,b/2);
    t=t*t%c;
    
    if(b%2==1)
    {
        return t*a%c;
    }
    return t%c;
}



int main()
{
    cin>>a>>b>>c;
    
    long long t=cal(a,b);
    cout<<t;
    
    return 0;
}
