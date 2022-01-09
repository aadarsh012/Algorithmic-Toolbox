#include <iostream>
#include <vector>
using namespace std;
using std::vector;

long long MaxPairwiseProduct(const vector<int> numbers)
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
        if (max_indexj == -1 || (numbers[j] != numbers[max_indexi] && numbers[j] > numbers[max_indexj]))
        {
            max_indexj = j;
        }
    }

    return ((long long)(numbers[max_indexi])) * numbers[max_indexj];
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << endl;

    return 0;
}