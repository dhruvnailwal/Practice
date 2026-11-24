#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int fact(int n)
{
    if (n <= 1)
        return 1;

    return n * fact(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number :- ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();

    int ans = fact(n);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "The factorial of " << n << " is " << ans << endl;

    cout << "The time taken by the function in nanosecond is :- " << duration.count();

    return 0;
}