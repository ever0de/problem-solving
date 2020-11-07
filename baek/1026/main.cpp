#include <bits/stdc++.h>
using namespace std;

bool compare_desc(int a, int b)
{
    return a > b;
}

void solve(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare_desc);

    int result = 0;
    for (int i = 0; i < A.size(); i++)
    {
        result += A[i] * B[i];
    }

    printf("%d", result);
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> A, B;
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        A.push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        B.push_back(v);
    }

    solve(A, B);
    return 0;
}
