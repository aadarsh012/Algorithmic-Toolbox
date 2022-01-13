#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  //write your code here
  int v = 1, sum = 0;
  while (sum < n)
  {
    sum += v;
    if (n - sum > v)
    {
      summands.push_back(v);
      v++;
    }
    else
    {
      sum -= v;
      summands.push_back(n - sum);
      sum = n;
    }
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
