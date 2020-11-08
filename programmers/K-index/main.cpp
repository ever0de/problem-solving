#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (vector<int> command : commands)
    {
        int X = command[0];
        int Y = command[1];
        int index = command[2] - 1;
        auto start = array.begin() + X - 1;
        auto end = array.begin() + Y;

        vector<int> result(Y - X + 1);
        copy(start, end, result.begin());
        sort(result.begin(), result.end());

        answer.push_back(result[index]);
    }

    return answer;
}