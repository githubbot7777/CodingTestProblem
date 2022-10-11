/*
https://www.acmicpc.net/problem/2295
*/


#include <bits/stdc++.h>

using namespace std;

/*

*/
int n;
int x[1005];
vector<int> two;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            two.push_back(x[i] + x[j]); //두수의 합을 저장하는 배열 

    sort(two.begin(), two.end());
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            //a+b+c=k a+b=k-c a+b는 two(두수 합 저장하는 배열) 
            //k-c의 값이 two배열에 있는지 binary search로 확인
            //시간 복잡도 O(N^2*log2)
            if (binary_search(two.begin(), two.end(), x[i] - x[j])) 
            {
                cout << x[i];
                return 0;
            }
                
        }
    }
    
   
        return 0;
}



