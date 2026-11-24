#include <bits/stdc++.h>
#include <chrono>

using namespace std;

long long calls = 0;
long long c = 0;

long long f(int n)
{
    calls++;

    if (n <= 0)
        return 0;

    f(n / 2);
    f(n / 2);

    for (int i = 0; i < n; i++)
    {
        c++;
    }

    return c;
}

int main()
{

    vector<int> value = {1000, 5000, 10000, 50000};

    for (auto n : value)
    {
        calls = 0;
        c = 0;

        auto start = chrono::high_resolution_clock::now();

        f(n);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout << "For the value :- " << n << endl;

        cout << "The total calls made by the function is :- " << calls << endl;

        cout << "The total time taken by this function is :- " << duration.count() << endl;
    }

    return 0;
}