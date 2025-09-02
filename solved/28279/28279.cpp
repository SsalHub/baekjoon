#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    deque<int> deq;
    int N, x;
    cin >> N;
    while (N--)
    {
        cin >> s;
        if (s == "1") {
            cin >> x;
            deq.push_front(x);
        }
        else if (s == "2") {
            cin >> x;
            deq.push_back(x);
        }
        else if (s == "3") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (s == "4") {
            if (deq.empty())  {
                cout << -1 << '\n';
            }  else  {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (s == "5") {
            cout << deq.size() << '\n';
        }
        else if (s == "6") {
            cout << (deq.empty() ? 1 : 0) << '\n';
        }
        else if(s == "7") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.front() << '\n';
            }
        } 
        else if (s == "8") {
          if (deq.empty()) {
            cout << -1 << '\n';
          } else {
            cout << deq.back() << '\n';
          }
        }
    }
    return 0;
}