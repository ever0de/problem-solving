#include <bits/stdc++.h>
using namespace std;

int COUNT = 0;
vector<int> CACHE;

int solve(int n) // f(n)의 return value = D[n]
{
    int &mem = CACHE[n];
    if (mem != -1)
        return mem;
    // n을 1로 만드는 데 드는 연산 횟수의 최솟값
    // if (n == 1)
    //     return 0;

    int ret = solve(n - 1) + 1;
    if (n % 3 == 0)
        ret = min(ret, solve(n / 3) + 1);
    if (n % 2 == 0)
        ret = min(ret, solve(n / 2) + 1);

    mem = ret;
    return ret;
}

int solve_bottom_up(int n)
{
    vector<int> value;
    value.resize(n + 1);
    value[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int ret = value[i - 1] + 1;
        if (i % 3 == 0)
            ret = min(ret, value[i / 3] + 1);
        if (i % 2 == 0)
            ret = min(ret, value[i / 2] + 1);

        value[i] = ret;
    }
    return value[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    // CACHE.resize(n + 1, -1);
    // CACHE[1] = 0;

    // int result = solve(n);
    int result = solve_bottom_up(n);
    printf("%d", result);
}