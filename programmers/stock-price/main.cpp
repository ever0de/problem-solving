#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    vector<int> temp;

    for (int index = 0; prices.size() != 0; index++)
    {
        temp.push_back(prices.back());
        prices.pop_back();

        if (temp.size() == 1)
        {
            answer.push_back(0);
            continue;
        }
        int count = 0;
        int last = temp.back();
        for (int i = temp.size() - 2; i >= 0; i--)
        {
            count += 1;
            if (last > temp[i])
            {
                break;
            }
        }
        answer.push_back(count);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    static const int arr[] = {1, 2, 3, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for (int a : solution(vec))
    {
        printf("%d ", a);
    }
}