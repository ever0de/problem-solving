#include <string>
#include <numeric>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int length = truck_weights.size();

    vector<int> cross_truck;
    vector<int> finish_truck;
    vector<int> count_vec;

    while (finish_truck.size() != length)
    {
        for (int i = 0; i < cross_truck.size(); i++)
        {
            // count_vec[i] += 1;
            if (count_vec[i] == bridge_length)
            {
                finish_truck.push_back(cross_truck[i]);

                cross_truck.erase(cross_truck.begin() + i);
                count_vec.erase(count_vec.begin() + i);
            }
        }

        if (!truck_weights.empty() && weight >= accumulate(cross_truck.begin(), cross_truck.end(), 0) + truck_weights[0])
        {
            cross_truck.push_back(truck_weights[0]);
            count_vec.push_back(0);

            truck_weights.erase(truck_weights.begin());
        }
        for (int i = 0; i < cross_truck.size(); i++)
        {
            count_vec[i] += 1;
        }
        answer += 1;
    }

    printf("answer: %d", answer);
    return answer;
}

int main()
{
    int bridge_length = 100;
    int weight = 100;
    static const int arr[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> truck_weights(arr, arr + sizeof(arr) / sizeof(arr[0]));
    solution(bridge_length, weight, truck_weights);
}