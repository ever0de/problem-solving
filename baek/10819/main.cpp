#include <bits/stdc++.h>
using namespace std;

int ANSWER = 0;
int calc_sum(vector<int> data)
{
    int sum = 0;
    for (int i = 1; i < data.size(); i++)
    {
        sum += abs(data[i - 1] - data[i]);
    }
    return sum;
}

void solve(int n, vector<int> input_vec, vector<int> pick_vec, vector<bool> check_vec)
{
    if (pick_vec.size() == n)
    {
        int sum = calc_sum(pick_vec);

        ANSWER = max(ANSWER, sum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check_vec[i])
            continue;
        check_vec[i] = true;
        pick_vec.push_back(input_vec[i]);
        solve(n, input_vec, pick_vec, check_vec);
        pick_vec.pop_back();
        check_vec[i] = false;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v, pick_vec;
    vector<bool> check_vec(n, false);
    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    solve(n, v, pick_vec, check_vec);
    printf("%d", ANSWER);
    return 0;
}