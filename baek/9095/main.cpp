#include <bits/stdc++.h>
using namespace std;

int solve(int n) // solve(n) = n을 1, 2, 3 더하기로 나타내는 경우의 수
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        printf("%d\n", solve(n));
        // printf("%d\n", cnt);
    }

    return 0;
}