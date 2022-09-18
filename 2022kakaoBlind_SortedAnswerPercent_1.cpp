/*
https://school.programmers.co.kr/learn/courses/30/lessons/92335
k�������� �Ҽ� ���� ���ϱ�
*/
#include <bits/stdc++.h>
using namespace std;

/*
1. ���� ��ȯ
2. 0�� ���������ʴ� �Ҽ� ���� ����(10�������� ������)

�߸��Ǵ��Ѱ�
1. ���� ��ȯ�� int ���� �Ѿ�� �ֱ� ������ long long �ڷ��� ����ؾ���
2. �Ҽ� �Ǻ��Ҷ� sqrt()�� �Ⱦ��ϱ� �ð��ʰ� �߻�
3. ���ڿ� ���ڷ� ��ȯ�Ҷ� ���ڿ� null üũ
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

string notation(int notation, int n)//����,��
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

   
   
    cout <<"���� ��ȯ��: "<< temp<<"\n";

    
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



