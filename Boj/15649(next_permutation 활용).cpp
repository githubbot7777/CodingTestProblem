
//https://www.acmicpc.net/problem/15649
//n과m

#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[8] = { 1,2,3,4,5,6,7,8};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    do
    {
        reverse(arr + m, arr + n);//중복없게 하기 위해서,next_permutation 1번 한것과 같은 효과
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(arr, arr + n));

  
    
    return 0;
}


