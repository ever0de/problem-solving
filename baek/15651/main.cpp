#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, vector<int> &v)
{
    if (m == 0)
    {
        for (int i : v)
            printf("%d ", i);
        printf("\n");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            v.push_back(i + 1);
            solve(n, m - 1, v);
            v.pop_back();
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v;

    solve(n, m, v);

    return 0;
}