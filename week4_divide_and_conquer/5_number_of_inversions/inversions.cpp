#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void deletion(vector<int> &a, int index)
// {
//   for (int i = index; i < a.size(); i++)
//   {
//     a[i] = a[i + 1];
//   }
// }

pair<vector<int>, int> Merge(vector<int> &a, vector<int> &b)
{

  int n = a.size();
  int m = b.size();

  cout << m << " " << n << endl;

  int count = 0, i = 0, j = 0;
  vector<int> res(n + m);
  while (i < n && j < m)
  {

    if (a[i] <= b[j])
    {
      res.push_back(a[i]);
      i++;
    }
    else
    {
      count++;
      res.push_back(b[j]);
      j++;
    }
  }

  while (i < n)
  {
    res.push_back(a[i++]);
  }

  while (j < m)
  {
    res.push_back(b[j++]);
  }

  return make_pair(res, count);
}

pair<vector<int>, int> MergeSort(vector<int> &a, int l, int r)
{
  int count = 0;
  pair<vector<int>, int> A, B, Result;
  if (r == l)
  {
    return make_pair(a, count);
  }

  int mid = (r + l) / 2;
  A = MergeSort(a, l, mid);
  B = MergeSort(a, mid + 1, r);
  Result = Merge(A.first, B.first);
  count += Result.second;

  return make_pair(Result.first, count);
}

// long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
// {
//   long long number_of_inversions = 0;
//   if (right <= left + 1)
//     return number_of_inversions;
//   size_t ave = left + (right - left) / 2;
//   number_of_inversions += get_number_of_inversions(a, b, left, ave);
//   number_of_inversions += get_number_of_inversions(a, b, ave, right);
//   //write your code here
//   return number_of_inversions;
// }

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    cin >> a[i];
  }

  pair<vector<int>, int> result = MergeSort(a, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << result.first[i] << " ";
  }
  // cout << result.second << '\n';
}
