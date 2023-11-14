#include <iostream>
#include <cstring>

using namespace std;

int getLCSLen(char s1[], char s2[]);

int main()
{
    ios_base::sync_with_stdio(false);

    char s1[1001], s2[1001];

    cin << s1 << s2;
    cout << getLCSLen(s1, s2);

    return 0;
}

int getLCSLen(char s1[], char s2[])
{
    int tableLCS[strlen(s2)+1][strlen(s1)+1] = { 0, };
    int i, j;

    return 0;
}
