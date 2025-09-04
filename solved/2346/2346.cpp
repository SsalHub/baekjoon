#include <deque>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  deque<pair<int, int>> dq; 
  for (int i = 1; i <= N; i++) 
  {
    int num;
    cin >> num;
    dq.push_back({i, num});
  }
  while (!dq.empty()) {
    auto current = dq.front();
    dq.pop_front();
    cout << current.first << " "; 
    if (dq.empty())
      break; 
    int move = current.second;
    if (move > 0) 
    {
      for (int i = 0; i < move - 1; i++) 
      {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } 
    else 
    {
      for (int i = 0; i < -move; i++) 
      {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
  return 0;
}
