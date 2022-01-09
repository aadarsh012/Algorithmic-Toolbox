#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int BinarySearch(vector<int> Arr, int l, int u, int Target)
{

  while (l <= u)
  {

    int mid = (l + u) / 2;

    if (Arr[mid] == Target)
    {
      return mid;
    }
    else if (Target < Arr[mid])
    {
      u = mid - 1;
    }
    else if (Target > Arr[mid])
    {
      l = mid + 1;
    }
  }
  return -1;
}

void FindinFirst(vector<int> a, int n, vector<int> b, int m)
{
  for (int i = 0; i < m; i++)
  {
    if (b[i] > a[n - 1] || b[i] < a[0])
    {
      cout << -1 << " ";
    }
    else
    {
      cout << BinarySearch(a, 0, n - 1, b[i]) << " ";
    }
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> First(n);
  for (int i = 0; i < n; i++)
    cin >> First[i];

  int k;
  cin >> k;
  vector<int> Second(k);
  for (int i = 0; i < k; i++)
    cin >> Second[i];

  FindinFirst(First, n, Second, k);
  return 0;
}