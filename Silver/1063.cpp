#include <bits/stdc++.h>
using namespace std;
int n;
string order, king, stone;
int kx, sx;
int ky, sy;
char result_kx, result_sx;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> king >> stone >> n;

    kx = king[0] - 'A' + 1;
    sx = stone[0] - 'A' + 1;
    ky = king[1] - '1' + 1;
    sy = stone[1] - '1' + 1;

    for (int i = 0; i < n; i++)
    {
        cin >> order;

        if (order == "R")
        {
            if (kx + 1 == sx && ky == sy)
            {
                if (sx + 1 > 8)
                    continue;
                else
                {
                    kx++;
                    sx++;
                }
            }
            else
            {
                if (kx + 1 > 8)
                    continue;
                else
                    kx++;
            }
        }
        else if (order == "L")
        {
            if (kx - 1 == sx && ky == sy)
            {
                if (sx - 1 < 1)
                    continue;
                else
                {
                    kx--;
                    sx--;
                }
            }
            else
            {
                if (kx - 1 < 1)
                    continue;
                else
                    kx--;
            }
        }
        else if (order == "B")
        {
            if (ky - 1 == sy && kx == sx)
            {
                if (sy - 1 < 1)
                    continue;
                else
                {
                    ky--;
                    sy--;
                }
            }
            else
            {
                if (ky - 1 < 1)
                    continue;
                else
                    ky--;
            }
        }
        else if (order == "T")
        {
            if (ky + 1 == sy && kx == sx)
            {
                if (sy + 1 > 8)
                    continue;
                else
                {
                    ky++;
                    sy++;
                }
            }
            else
            {
                if (ky + 1 > 8)
                    continue;
                else
                    ky++;
            }
        }
        else if (order == "RT")
        {
            if (kx + 1 == sx && ky + 1 == sy)
            {
                if (sx + 1 > 8 || sy + 1 > 8)
                    continue;
                else
                {
                    kx++;
                    ky++;
                    sx++;
                    sy++;
                }
            }
            else
            {
                if (kx + 1 > 8 || ky + 1 > 8)
                    continue;
                else
                {
                    kx++;
                    ky++;
                }
            }
        }
        else if (order == "LT")
        {
            if (kx - 1 == sx && ky + 1 == sy)
            {
                if (sx - 1 < 1 || sy + 1 > 8)
                    continue;
                else
                {
                    kx--;
                    ky++;
                    sx--;
                    sy++;
                }
            }
            else
            {
                if (kx - 1 < 1 || ky + 1 > 8)
                    continue;
                else
                {
                    kx--;
                    ky++;
                }
            }
        }
        else if (order == "RB")
        {
            if (kx + 1 == sx && ky - 1 == sy)
            {
                if (sx + 1 > 8 || sy - 1 < 1)
                    continue;
                else
                {
                    kx++;
                    ky--;
                    sx++;
                    sy--;
                }
            }
            else
            {
                if (kx + 1 > 8 || ky - 1 < 1)
                    continue;
                else
                {
                    kx++;
                    ky--;
                }
            }
        }
        else if (order == "LB")
        {
            if (kx - 1 == sx && ky - 1 == sy)
            {
                if (sx - 1 < 1 || sy - 1 < 1)
                    continue;
                else
                {
                    kx--;
                    ky--;
                    sx--;
                    sy--;
                }
            }
            else
            {
                if (kx - 1 < 1 || ky - 1 < 1)
                    continue;
                else
                {
                    kx--;
                    ky--;
                }
            }
        }
    }

    result_kx = 'A' + kx - 1;
    result_sx = 'A' + sx - 1;

    cout << result_kx << ky << "\n" << result_sx << sy;
}
