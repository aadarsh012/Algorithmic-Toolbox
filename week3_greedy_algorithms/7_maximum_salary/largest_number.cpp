#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using std::string;
using std::vector;

string largest_number(vector<string> a)
{
  //write your code here
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < a.size() - i - 1; j++)
    {
      string res1 = a[j] + a[j + 1];
      string res2 = a[j + 1] + a[j];
      if (res1.compare(res2) < 0)
      {
        string temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
