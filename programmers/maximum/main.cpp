#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> answer_vec;
    for (int number : numbers)
    {
        answer_vec.push_back(to_string(number));
    }
    sort(answer_vec.begin(), answer_vec.end(), compare);
    if (answer_vec[0] == "0")
        return "0";
    for (string anw : answer_vec)
    {
        answer.append(anw);
    }

    return answer;
}