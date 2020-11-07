#include <bits/stdc++.h>
using namespace std;

struct Person
{
    int age;
    string name;
};

bool compare(Person a, Person b)
{
    return a.age < b.age;
}

void solve(vector<Person> person_vec)
{
    stable_sort(person_vec.begin(), person_vec.end(), compare);
    for (Person p : person_vec)
    {
        printf("%d %s\n", p.age, p.name.c_str());
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Person> person_vec;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        // scanf("%d %s", &age, name.c_str());
        cin >> age >> name;
        Person person;
        person.age = age;
        person.name = name.c_str();

        person_vec.push_back(person);
    }
    solve(person_vec);
    return 0;
}
