#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here

    int n = stops.size();

    int count = 0;
    int curr = 0;
    int currPos = -1;
    int far = 0;
    int i = 0;

    if (dist - stops[n - 1] > tank || stops[0] > tank)
    {
        return -1;
    }
    while (i <= n)
    {
        if (dist - far <= tank)
        {
            return count;
        }
        // for (i = currPos + 1; i < n && stops[i] - far <= tank; i++)
        // {
        //     curr = stops[i];
        // }
        // i--;
        if (stops[i] - curr > tank)
        {
            return -1;
        }
        curr = stops[i];
        i++;
        if (stops[i] - far > tank)
        {
            far = curr;
            count++;
        }
        // currPos = i;
    }

    return count;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    stops[n] = d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
