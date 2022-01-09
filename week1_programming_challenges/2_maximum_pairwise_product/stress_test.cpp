#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

long long MaxPairwiseProduct(const vector<int> numbers)
{
    int n = numbers.size();

    long long max = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] * numbers[j] > max)
            {
                max = (long long)numbers[i] * numbers[j];
            }
        }
    }
    return max;
}

long long MaxPairwiseProductFast(const vector<int> numbers)
{
    int n = numbers.size();

    int max_indexi = -1;
    for (int i = 0; i < n; i++)
    {
        if (max_indexi == -1 || numbers[i] > numbers[max_indexi])
        {
            max_indexi = i;
        }
    }

    int max_indexj = -1;
    for (int j = 0; j < n; j++)
    {
        if (j != max_indexi && (max_indexj == -1 || numbers[j] > numbers[max_indexj]))
        {
            max_indexj = j;
        }
    }

    return (long long)numbers[max_indexi] * numbers[max_indexj];
}

int main()
{
    // while (true)
    // {
    //     int n = rand() % 10 + 2;
    //     cout << n << endl;
    //     vector<int> a(n);
    //     for (int i = 0; i < n; i++)
    //     {
    //         a.push_back(rand() % 100000);
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << a[i] << " ";
    //     }
    //     cout << endl;
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProductFast(a);
    //     if (res1 != res2)
    //     {
    //         cout << "Wrong: " << res1 << " " << res2 << endl;
    //         break;
    //     }
    //     else
    //     {
    //         cout << "Ok" << endl;
    //     }
    // }

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << endl;

    return 0;
}