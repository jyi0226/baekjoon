#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
string a, b, res;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, a);
    int s = a.size();
    bool flag = true;
    for (int i = 0; i < s; i++)
    {
        if (a[i] == '<')
        {
            reverse(b.begin(), b.end());
            res += b;
            res += a[i];
            b = "";
            flag = false;
        }
        else if (a[i] == '>')
        {
            flag = true;
            res += b;
            res += a[i];
            b = "";
        }
        else if (a[i] == ' ')
        {
            if (flag)
            {
                reverse(b.begin(), b.end());
                res += b;
                res += a[i];
                b = "";
            }
            else
            {
                b += a[i];
            }
        }
        else
            b += a[i];
    }
    if (a[s - 1] == '>')
        cout << res;
    else
    {
        reverse(b.begin(), b.end());
        cout << res + b;
    }
}