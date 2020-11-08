#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> que;
    for (int value : scoville)
    {
        que.push(value);
    }

    while (que.top() < K && que.size() > 1)
    {
        int first, second;
        answer++;
        first = que.top();
        que.pop();
        second = que.top();
        que.pop();

        que.push(first + second * 2);
    }

    if (que.top() < K)
    {
        return -1;
    }

    return answer;
}