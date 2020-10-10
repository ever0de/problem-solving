#include <bits/stdc++.h>
using namespace std;

void solve(int n, int s, int index, vector<int> &v, vector<int> &result, int &count)
{

    if (index == n)
    {
        if (result.size() != 0 && std::accumulate(result.begin(), result.end(), 0) == s)
            count += 1;
        return;
    }

    result.push_back(v[index]);
    solve(n, s, index + 1, v, result, count);
    result.pop_back();
    solve(n, s, index + 1, v, result, count);
}

int main()
{
    int n, s, count = 0, index = 0;
    scanf("%d %d", &n, &s);
    vector<int> v, result;
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    solve(n, s, index, v, result, count);
    printf("%d", count);

    return 0;
}