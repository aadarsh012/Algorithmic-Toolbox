#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int merge(vector<int> &a, int start, int mid, int end)
{
  int i = start, j = mid + 1, counter = 0;

  while (i <= mid)
  {
    j = mid + 1;
    while (j <= end)
    {
      if (a[i] > a[j++])
      {
        counter++;
      }
    }
    i++;
  }

  return counter;
}

int mergeSort(vector<int> &a, int start, int end)
{
  int count = 0;
  if (start < end)
  {
    int mid = (start + end) / 2;
    count += mergeSort(a, start, mid);
    count += mergeSort(a, mid + 1, end);
    count += merge(a, start, mid, end);
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    cin >> a[i];
  }

  int result = mergeSort(a, 0, n - 1);

  cout << result << endl;
}
