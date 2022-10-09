/*
https://www.acmicpc.net/problem/18870
*/


#include <bits/stdc++.h>

using namespace std;

/*
[2,4,-10,4,-9] 나보다 작은수가 몇개 있는지?
1. 정렬
2. 중복제거
3. binary_search
*/
int arr_origin[1000002];
int arr1[1000002];
int arr2[1000002];
int n;

int b_search(int find,int len)
{
    int st = 0;
    int en = len-1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (arr2[mid] < find)
            st = mid + 1;
        else if (arr2[mid] > find)
            en = mid - 1;
        else
            return mid;

    }

    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr_origin[i];
    memcpy(arr1, arr_origin, sizeof(int)*n);
    sort(arr1, arr1 + n);
    arr1[n] = (int)pow(10, 10) + 1;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
            if (arr1[i] != arr1[i + 1])
            {
                arr2[index++] = arr1[i];
               
            }
               
    }
    /*for (int i = 0; i < index; i++)
        cout << arr2[i] << " ";

    cout << "\n";*/

    for (int i = 0; i < n; i++)
    {
        int result = b_search(arr_origin[i],index);
        cout << result << " ";
    }
   
        return 0;
}



