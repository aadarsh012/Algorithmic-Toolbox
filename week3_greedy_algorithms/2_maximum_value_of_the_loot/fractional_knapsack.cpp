// #include <iostream>
// #include <vector>
// #include <iomanip>

// using std::vector;

// int max(int a, int b)
// {
//   return a > b ? a : b;
// }
// int min(int a, int b)
// {
//   return a < b ? a : b;
// }

// void sortValuesAndWeights(vector<int> &a, vector<int> &b)
// {
//   int n = sizeof(a) / sizeof(int);
//   for (int i = 0; i < n - 1; i++)
//   {
//     for (int j = i + 1; j < n; j++)
//     {
//       if ((a[i] / b[i]) < (a[j] / b[j]))
//       {
//         int temp1 = a[i];
//         a[i] = a[j];
//         a[j] = temp1;
//         int temp2 = b[i];
//         b[i] = b[j];
//         b[j] = temp2;
//       }
//     }
//   }
// }

// double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
// {

//   double value = 0.0;

//   int n = sizeof(weights) / sizeof(int);

//   // write your code here

//   for (int i = 0; i < n; i++)
//   {
//     if (capacity == 0)
//     {
//       return value;
//     }

//     double a = min(weights[i], capacity);

//     double perUnit = ((double)values[i] / (double)weights[i]);

//     value += a * perUnit;

//     weights[i] -= a;
//     capacity -= a;
//   }

//   return value;
// }

// int main()
// {
//   int n;
//   int capacity;
//   std::cin >> n >> capacity;
//   vector<int> values(n);
//   vector<int> weights(n);
//   for (int i = 0; i < n; i++)
//   {
//     std::cin >> values[i] >> weights[i];
//   }

//   sortValuesAndWeights(values, weights);

//   double optimal_value = get_optimal_value(capacity, weights, values);

//   std::cout.precision(10);
//   std::cout << std::fixed << std::setprecision(4);
//   std::cout << optimal_value << std::endl;
//   return 0;
// }

#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

int max(int a, int b)
{
  return a > b ? a : b;
}
int min(int a, int b)
{
  return a < b ? a : b;
}

int get_max_index(vector<int> weights, vector<int> values)
{
  int max_i = 0;
  double max = 0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (weights[i] != 0 && (double)values[i] / weights[i] > max)
    {
      max = (double)values[i] / weights[i];
      max_i = i;
    }
  }
  return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (capacity == 0)
      return value;
    int index = get_max_index(weights, values);
    int a = min(capacity, weights[index]);
    value += a * (double)values[index] / weights[index];
    weights[index] -= a;
    capacity -= a;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << std::fixed << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}