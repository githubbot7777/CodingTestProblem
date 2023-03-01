/*
https://www.acmicpc.net/problem/1431
문자열 숫자인거 체크후 더할때 숫자로 변환해서 더해야함
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
            //a[i]-'0' 이유는 0의 아스키코드값 48을빼서 원래 숫자값을 얻을려고함 '1'-'0'=숫자 1 아스키코드 값 49-48=1;
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