#include <iostream>

int gcd_algo(int a, int b)
{
  if (b == 0)
  {
    return a;
  }
  int rem = a % b;

  return gcd_algo(b, rem);
}

long long lcm_naive(int a, int b)
{
  int gcd = gcd_algo(a, b);
  if (gcd == 1)
  {
    return (long long)a * b;
  }
  int n = a / gcd;
  int m = b / gcd;
  return (long long)n * m * gcd;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
