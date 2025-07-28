#include <iostream>
#include <string>


using namespace std;
string anj = "anj", a;
int n;
bool is_exist = false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == anj)
            is_exist = true;
    }
    if (is_exist)
        cout << "뭐야;";
    else
        cout << "뭐야?";
}