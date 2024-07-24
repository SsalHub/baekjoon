#include <iostream>
#include <cmath>
#define _MIN_ 0
#define _MAX_ 1
#define _X_ 0
#define _Y_ 1

using namespace std;

int main()
{
    int N, area, input_pos[2], pos[2][2] = {{10001, 10001}, {-10001, -10001}};
    cin >> N;
    while (N--)
    {
        cin >> input_pos[_X_] >> input_pos[_Y_];
        if (input_pos[_X_] < pos[_MIN_][_X_])
            pos[_MIN_][_X_] = input_pos[_X_];
        if (input_pos[_Y_] < pos[_MIN_][_Y_])
            pos[_MIN_][_Y_] = input_pos[_Y_];

        if (pos[_MAX_][_X_] < input_pos[_X_])
            pos[_MAX_][_X_] = input_pos[_X_];
        if (pos[_MAX_][_Y_] < input_pos[_Y_])
            pos[_MAX_][_Y_] = input_pos[_Y_];
    }
    area = abs((pos[_MAX_][_X_] - pos[_MIN_][_X_])) * abs((pos[_MAX_][_Y_] - pos[_MIN_][_Y_]));
    cout << area << "\n";
    return 0;
}