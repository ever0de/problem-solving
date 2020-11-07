#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    vector<int> result;
    while (n > 0)
    {
        if (n % 10 == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(n % 10);
        }

        n = n / 10;
    }

    sort(result.begin(), result.end(), greater<int>());
    for (int a : result)
    {
        printf("%d", a);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    solve(n);
    return 0;
}

// radix sort
// #include <stdio.h>
// int N, a[10];
// int main() {
//     scanf("%d", &N);
//     while(N>0) {
//         a[N%10]++;
//         N/=10;
//     }
//     for(int i=9;i>=0;i--) for(int j=0;j<a[i];j++) printf("%d", i);
//     return 0;
// }