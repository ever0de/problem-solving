#include <bits/stdc++.h>
using namespace std;

typedef vector<int> location;

int main()
{
    int n;
    scanf("%d", &n);
    vector<location> location_vec;
    location_vec.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        int color, location;
        scanf("%d %d", &location, &color);

        location_vec[color].push_back(location);
    }

    long long result = 0;
    for (int i = 0; i < location_vec.size(); i++)
    {
        location now = location_vec[i];
        if (now.size() > 1)
        {
            sort(now.begin(), now.end());
            result += now[1] - now[0];
            result += now[now.size() - 1] - now[now.size() - 2];

            for (int j = 1; j < now.size() - 1; j++)
            {
                result += min(now[j] - now[j - 1], now[j + 1] - now[j]);
            }
        }
    }
    printf("%lld", result);

    return 0;
}
