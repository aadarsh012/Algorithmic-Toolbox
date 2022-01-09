#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for(int i=0; i<segments.size()-1; i++){
    for(int j=i+1; j<segments.size(); j++){
      int l = segments[i].end - segments[i].start;
      int a = segments[i].end - segments[j].start;
      int b = segments[i].start - segments[j].end;
      if(a<=l || b<=l){
        
      }
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
