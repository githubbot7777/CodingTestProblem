/*
https://www.acmicpc.net/problem/1431
���ڿ� �����ΰ� üũ�� ���Ҷ� ���ڷ� ��ȯ�ؼ� ���ؾ���
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> vec;

int comp(string a, string b)
{
    int lengthA = a.length();
    int lengthB = b.length();

    if (lengthA < lengthB)
        return 1;
    else if (lengthA == lengthB)
    {
        int sumA=0, sumB = 0;
        for (int i = 0; i < lengthA; i++)
        {
            //a[i]-'0' ������ 0�� �ƽ�Ű�ڵ尪 48������ ���� ���ڰ��� ���������� '1'-'0'=���� 1 �ƽ�Ű�ڵ� �� 49-48=1;
            if (isdigit(a[i]))
                sumA += a[i]-'0';
        }
        for (int i = 0; i < lengthB; i++)
        {
            if (isdigit(b[i]))
                sumB += b[i]-'0';
        }
        //cout << "sumA : " << sumA << " sumB: " << sumB << "\n";
        if (sumA < sumB)
            return 1;
        else if (sumA == sumB)
        {
            return a < b;
        }
        else
            return 0;
    }
    else
        return 0;



  
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end(), comp);
    
    for (auto it : vec)
       cout << it << "\n";

    

    return 0;

}