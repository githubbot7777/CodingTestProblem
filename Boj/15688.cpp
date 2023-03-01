//https://www.acmicpc.net/problem/15688
/*
절대값 1000000보다 작거나 같은 정수
-백만 ~ +백만을 배열에 counting sort 
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp + 1000000] += 1;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i - 1000000 << "\n";
        }
    }

    return 0;

}