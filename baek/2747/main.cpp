#include <bits/stdc++.h>
using namespace std;

vector<int> cache;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int &result = cache[n];
    if (result > 0)
        return result;

    result = fibo(n - 1) + fibo(n - 2);
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    cache.resize(46);

    int result = fibo(n);
    printf("%d", result);

    return 0;
}