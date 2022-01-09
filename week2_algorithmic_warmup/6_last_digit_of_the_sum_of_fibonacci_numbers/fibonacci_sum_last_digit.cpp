#include <iostream>

int pisano(int m)
{
    int prev = 0;
    int curr = 1;
    int res = 0;

    for (int i = 0; i < m * m; i++)
    {
        int temp = curr;
        curr = (curr + prev) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
        {
            res = i + 1;
        }
    }
    return res;
}

int fibonacci_sum_naive(long long n)
{
    n = n % pisano(10);
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return sum % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
