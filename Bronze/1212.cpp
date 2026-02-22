#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
string str[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    int cnt = a.size();
    for (int i = 0; i < cnt; i++)
    {
        b += str[a[i] - '0'];
    }
    int idx;
    cnt = b.size();
    for (int i = 0; i < cnt; i++)
    {
        if (b[i] == '1')
        {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < cnt; i++)
        cout << b[i];
}