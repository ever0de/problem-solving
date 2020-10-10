#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve(int n, int m, vector<int> &v, vector<bool> &check_vec)
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
            if (!check_vec[i])
            {
                check_vec[i] = true;
                v.push_back(i + 1);
                solve(n, m - 1, v, check_vec);
                v.pop_back();
                check_vec[i] = false;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v;
    vector<bool> check_vec(n, false);

    solve(n, m, v, check_vec);

    return 0;
}
