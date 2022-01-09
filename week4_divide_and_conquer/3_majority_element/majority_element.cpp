// #include <iostream>
// #include <vector>

// //freopen("input.txt","r",stdin);
// //freopen("output.txt","w",stdout);

// using namespace std;

// int ContainMajority(vector<int> Arr, int l, int u)
// {

//   if (u == 0)
//   {
//     return Arr[0];
//   }

//   int majorL = ContainMajority(Arr, l, u / 2);
//   int majorU = ContainMajority(Arr, (u / 2) + 1, u);

//   int count = 0;
//   for (int i = 0; i <= u; i++)
//   {
//     if (Arr[i] == majorL)
//     {
//       count++;
//     }
//   }
//   if (count > (u + 1) / 2)
//   {
//     return majorL;
//   }

//   count = 0;
//   for (int i = 0; i <= u; i++)
//   {
//     if (Arr[i] == majorU)
//     {
//       count++;
//     }
//   }
//   if (count > (u + 1) / 2)
//   {
//     return majorU;
//   }

//   return -1;
// }
// int main()
// {
//   int n;
//   cin >> n;

//   vector<int> Arr(n);
//   for (int i = 0; i < n; i++)
//     cin >> Arr[i];

//   int res = ContainMajority(Arr, 0, n - 1);
//   if (res == -1)
//   {
//     cout << 0 << endl;
//   }
//   else
//   {
//     cout << res << endl;
//   }

//   return 0;
// }
