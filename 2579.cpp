/*
https://www.acmicpc.net/problem/2579

*/
#include <bits/stdc++.h>
using namespace std;

int s[305];//��� ���� �����ϴ� �迭
int n;
int d[305];//dp ���̺�
/*
d[i]=i��° ��ܱ��� �ö����� ���� ���� ����� ���� �ּڰ�, �� 
i��° ����� �ݵ�� ���� ���� ������� �����ؾ� ��

��ȭ��: d[i]=min(d[i-2],d[i-3])+s[i]*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        tot += s[i];
    }
    if (n <= 2)
    {
        cout << tot;
        return 0;
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for (int i = 4; i <= n - 1; i++)
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    /*
    ������ ���� ����� �ݵ�� ��ƾ� �Ѵٰ� ������ 
    ���� ���������� ���õ� ���� ���� 
    ����� N-1��° ����̰ų� N-2��° ����Դϴ�. 
    �׷��� ��ܿ� ���� ������ �տ��� 
    min(D[N-1], D[N-2])�� ���� �װ� �����Դϴ�.
    */
    cout << tot - min(d[n - 1], d[n - 2]);


    return 0;

}