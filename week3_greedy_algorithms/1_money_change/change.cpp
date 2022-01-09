#include <iostream>

int get_change(int m)
{
  //write your code here
  int n = 0, count = 0;
  while (n <= m)
  {
    if (m - n >= 10)
    {
      n += 10;
      count++;
    }
    else if (m - n >= 5)
    {
      n += 5;
      count++;
    }
    else if (m - n >= 1)
    {
      n++;
      count++;
    }
    else
    {
      break;
    }
  }

  return count;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
