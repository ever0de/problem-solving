#include <bits/stdc++.h>
using namespace std;

int solve(int N, vector<int> T, vector<int> P, int day)
{
    int sum = 0;
    if (day < N)
    {
        int pay = P[day], time = T[day];

        if (day + time < N + 1)
            sum = max(sum, pay + solve(N, T, P, day + time));
        sum = max(sum, solve(N, T, P, day + 1));
    }
    return sum;
}
int main()
{
    int N;
    vector<int> T, P;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int t_v, p_v;
        scanf("%d %d", &t_v, &p_v);
        T.push_back(t_v);
        P.push_back(p_v);
    }
    printf("%d", solve(N, T, P, 0));
    return 0;
}
