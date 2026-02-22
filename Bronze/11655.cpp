#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, str);

    int s = str.size();
    for (int i = 0; i < s; i++)
    {
        int x = str[i] - 'A', y = str[i] - 'a';
        if (x >= 0 && x < 26)
        {
            x = (x + 13) % 26;
            str[i] = x + 'A';
        }
        else if (y >= 0 && y < 26)
        {
            y = (y + 13) % 26;
            str[i] = y + 'a';
        }
    }
    cout << str;
}