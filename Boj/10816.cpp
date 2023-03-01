/*
https://www.acmicpc.net/problem/10816
*/


#include <bits/stdc++.h>

using namespace std;

/*
binary search�� �����ؼ� �迭���� ã�� ���� ��ִ��� ��� �ؾ� �ϱ⶧����
ã�� ������ �� ���� index �� �� ������ index �� ã�� ���ش�.
*/

int arr1[500002];
int n,m;
int lower_index(int find, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr1[mid] >= find)
        {
            en = mid;
        }
        else {
            st = mid + 1;
        }
    }

    return st;
}

int upper_index(int find, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr1[mid] > find)en = mid;
        else st = mid + 1;
    }

    return st;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cin >> m;

    sort(arr1, arr1 + n);
    while (m--)
    {
        int temp;
        cin >> temp;
        cout << upper_index(temp, n) - lower_index(temp, n) << " ";
      //cout<<upper_bound(a,a+n,t)-lower_bound(a,a+n,t)<<" ";
      //������ ��Ȱ���ϴ� stl �Լ� ����

    }
   
        return 0;
}



