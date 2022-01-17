#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

void Merge(vector<Segment> &a, int s, int m, int e)
{
  vector<Segment> res;
  int i = s, j = m + 1;
  while (i <= m && j <= e)
  {
    if (a[i].start <= a[j].start)
    {
      res.push_back(a[i++]);
    }
    else
    {
      res.push_back(a[j++]);
    }
  }
  while (i <= m)
  {
    res.push_back(a[i++]);
  }
  while (j <= e)
  {
    res.push_back(a[j++]);
  }

  for (int k = s; k <= e; k++)
  {
    a[k] = res[k - s];
  }
}

void sortByleftEnd(vector<Segment> &a, int s, int e)
{
  if (s >= e)
  {
    return;
  }
  int mid = (s + e) / 2;
  sortByleftEnd(a, s, mid);
  sortByleftEnd(a, mid + 1, e);
  Merge(a, s, mid, e);
}

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  //write your code here

  int i = 0, j = i + 1;
  int start = segments[i].start;
  int end = segments[i].end;
  while (i < segments.size())
  {
    while (j < segments.size())
    {
      if (segments[j].start <= end)
      {
        start = segments[j].start;
        if (segments[j].end <= end)
        {
          end = segments[j].end;
        }
        j++;
      }
      else
      {
        points.push_back(start);
        i = j;
        start = segments[i].start;
        end = segments[i].end;
        j++;
      }
    }
    points.push_back(start);
    break;
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sortByleftEnd(segments, 0, n - 1);
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
