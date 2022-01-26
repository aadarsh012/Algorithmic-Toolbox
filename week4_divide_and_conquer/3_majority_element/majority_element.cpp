#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    vector<int> res;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            res.push_back(a[i++]);
        }
        else
        {
            res.push_back(a[j++]);
        }
    }

    while (i <= mid)
    {
        res.push_back(a[i++]);
    }
    while (j <= end)
    {
        res.push_back(a[j++]);
    }
    for (int k = start; k <= end; k++)
    {
        a[k] = res[k - start];
    }
}

void mergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    int counter = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            counter++;
            if (counter + 1 > n / 2)
            {
                cout << 1 << endl;
                return 0;
            }
        }
        else
        {
            counter = 0;
        }
    }
    cout << 0 << endl;
    return 0;
}