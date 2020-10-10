#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    typedef pair<int, int> day;
    vector<day> dayVec;

    for (int i = 0; i < progresses.size(); i++)
    {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)
        {
            dayVec.push_back(make_pair(day + 1, i));
        }
        else
        {
            dayVec.push_back(make_pair(day, i));
        }
    }

    int len = 0;
    while (len < dayVec.size())
    {
        day day = dayVec[len];
        int count = 1;

        len += 1;
        while (len < dayVec.size())
        {
            if (day.first >= dayVec[len].first)
            {
                len += 1;
                count += 1;
                continue;
            }
            break;
        }
        answer.push_back(count);
    }

    return answer;
}

int main()
{
    static const int arr[] = {95, 90, 99, 99, 80, 99};
    vector<int> progresses(arr, arr + sizeof(arr) / sizeof(arr[0]));
    static const int arr2[] = {1, 1, 1, 1, 1, 1};
    vector<int> speeds(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    for (int a : solution(progresses, speeds))
    {
        printf("%d ", a);
    }
}