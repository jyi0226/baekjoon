#include <cmath>
#include <iostream>

using namespace std;
int n;
int dp[101010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        int a = dp[i - 2];
        int b = dp[i - 5];

        if (a == -1 && b == -1)
        {
            dp[i] = -1;
        }
        else
        {
            if (a == -1)
            {
                dp[i] = b + 1;
            }
            else if (b == -1)
            {
                dp[i] = a + 1;
            }
            else
            {
                dp[i] = min(a, b) + 1;
            }
        }
    }
    cout << dp[n];
}